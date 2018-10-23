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