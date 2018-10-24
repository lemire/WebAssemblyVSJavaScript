c/binarytrees.js : c/binarytrees.c
	cd c; emcc binarytrees.c -s WASM=1 -o binarytrees.js -O3 -s ALLOW_MEMORY_GROWTH=1


test: c/binarytrees.js js/binarytrees.js
	ls -al c/binarytrees.js c/binarytrees.wasm js/binarytrees.js
	time node js/binarytrees.js
	time node c/binarytrees.js

clean:
	rm c/binarytrees.js c/binarytrees.wasm