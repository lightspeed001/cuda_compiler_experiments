#include <nvvm.h>
#include <stdio.h>

int main() {
    nvvmProgram prog;
    nvvmResult res;

    // Create a simple LLVM IR module (add two floats)
    const char *llvm_ir =
        "target datalayout = \"e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v16:16:16-v32:32:32-v64:64:64-v128:128:128-n16:32:64\"\n"
        "target triple = \"nvptx64-nvidia-cuda\"\n"
        "define float @add(float %a, float %b) {\n"
        "  %sum = fadd float %a, %b\n"
        "  ret float %sum\n"
        "}\n";

    // Compile LLVM IR → NVVM IR → PTX
    res = nvvmCreateProgram(&prog);
    res = nvvmAddModuleToProgram(prog, llvm_ir, strlen(llvm_ir), "add.ll");
    res = nvvmCompileProgram(prog, 0, NULL); // Compile to NVVM IR

    // Get PTX
    size_t ptx_size;
    res = nvvmGetCompiledResultSize(prog, &ptx_size);
    char *ptx = malloc(ptx_size);
    res = nvvmGetCompiledResult(prog, ptx);

    printf("Generated PTX:\n%s\n", ptx);
    free(ptx);
    nvvmDestroyProgram(&prog);
    return 0;
}
