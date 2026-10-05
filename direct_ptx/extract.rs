// After building a rustacuda project:
let ptx = rustacuda::module::Ptx::from_file("path/to/kernel.ptx")?;
println!("{}", ptx.as_str());
