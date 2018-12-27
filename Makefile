c/binarytrees.js : c/binarytrees.c
	cd c; emcc binarytrees.c -s WASM=1 -o binarytrees.js -O3 -s ALLOW_MEMORY_GROWTH=1

c/binarytrees.exe: c/binarytrees.c
	cd c; $(CC) -O3 -o binarytrees.exe binarytrees.c

c/mandelbrot.js : c/mandelbrot.c
	cd c; emcc mandelbrot.c -s WASM=1 -o mandelbrot.js -O3 -s ALLOW_MEMORY_GROWTH=1

c/mandelbrot.exe: c/mandelbrot.c
	cd c; $(CC) -O3 -o mandelbrot.exe mandelbrot.c

testmandelbrot: c/mandelbrot.js js/mandelbrot.js c/mandelbrot.exe
	ls -al c/mandelbrot.exe c/mandelbrot.js c/mandelbrot.wasm js/mandelbrot.js
	time c/mandelbrot.exe
	time node js/mandelbrot.js
	time node c/mandelbrot.js

testbinarytree: c/binarytrees.js js/binarytrees.js c/binarytrees.exe 
	ls -al c/binarytrees.exe c/binarytrees.js c/binarytrees.wasm js/binarytrees.js
	time c/binarytrees.exe
	time node js/binarytrees.js
	time node c/binarytrees.js

clean:
	rm c/binarytrees.js c/binarytrees.wasm c/binarytrees.exe  c/mandelbrot.js c/mandelbrot.wasm c/mandelbrot.exe