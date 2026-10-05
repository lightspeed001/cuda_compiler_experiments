# Generate NVVM IR and PTX
nvcc --keep --ptxas-options=-v -arch=sm_80 -m64 your_kernel.cu -o kernel.out

# Output files:
# - your_kernel.nvvm      (NVVM IR)
# - your_kernel.ptx       (PTX)
# - kernel.out           (Host executable + cubin)
