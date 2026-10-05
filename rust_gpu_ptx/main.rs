#[spirv(compute(threads(1024)))]
pub fn add_kernel(
    #[spirv(global_invocation_id)] id: Vec3,
    #[spirv(storage_buffer, descriptor_set = 0, binding = 0)] a: &[f32],
    #[spirv(storage_buffer, descriptor_set = 0, binding = 1)] b: &[f32],
    #[spirv(storage_buffer, descriptor_set = 0, binding = 2)] c: &mut [f32],
) {
    let idx = id.x as usize;
    c[idx] = a[idx] + b[idx];
}
