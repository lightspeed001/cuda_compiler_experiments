# Link against libNVVM (part of CUDA Toolkit)
gcc nvvm_example.c -lnvvm -o nvvm_example -L/usr/local/cuda/lib64
./nvvm_example
