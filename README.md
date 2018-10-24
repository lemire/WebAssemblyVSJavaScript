# WebAssemblyVSJavaScript
Project to compare the performance of WebAssembly with JavaScript.

We use some good programs in C and JavaScript written for the Computer Language Benchmarks Game.

We have kept the following benchmarks:

- binarytrees
- fannkuchredux
- fasta              
- mandelbrot        
- nbody
- reverse-complement  (can be run on `data/knucleotide-input10000.txt`)
- spectralnorm

All benchmarks are single-threaded.

## Method

- Compile the C code to WebAssembly. Different flags and compilers are possible.
- Execute both the JavaScript and the WebAssembly.
- Compare the performance.


Ideally memory usage, file sizes and different environments should be included in the benchmark. Most browsers support WebAssembly.


## Outstanding problems

- The fasta test is problematic since it implies outputting a large volume of data to the standard output. It is likely to become a limiting factor. In JavaScript, we can use a buffered output. For the C version, we need some fast print-out approach.


## References

- Egorov, [Maybe you don't need Rust and WASM to speed up your JS](https://mrale.ph/blog/2018/02/03/maybe-you-dont-need-rust-to-speed-up-your-js.html)
- Haas et al., [Bringing the Web up to Speed with WebAssembly](ttps://www.cs.tufts.edu/~nr/cs257/archive/andreas-rossberg/webassembly.pdf), PLDI'17
- Herrera et al., [WebAssembly and JavaScript Challenge: Numerical program performance using modern browser technologies and devices](http://www.sable.mcgill.ca/publications/techreports/2018-2/techrep.pdf), 2018
- Lemire, [Is WebAssembly faster than JavaScript?](https://lemire.me/blog/2018/10/23/is-webassembly-faster-than-javascript/)
