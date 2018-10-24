/* The Computer Language Benchmarks Game
   http://benchmarksgame.alioth.debian.org/
   contributed by Isaac Gouy 
   *reset* 
*/

/* The Computer Language Benchmarks Game
   https://salsa.debian.org/benchmarksgame-team/benchmarksgame/

   contributed by Léo Sarrazin 
*/

const TreeNode = function(left, right) {
    this.left  = left;
    this.right = right;
};

const itemCheck = function(node){
    if (node===null) return 1;
    return 1 + itemCheck(node.left) + itemCheck(node.right);
};

function bottomUpTree(depth){
    return depth>0 ? new TreeNode(
            bottomUpTree(depth-1),
            bottomUpTree(depth-1)
    ) : null;
};

const maxDepth = Math.max(6, 21);//parseInt(process.argv[2]));
const stretchDepth = maxDepth + 1;

let check = itemCheck(bottomUpTree(stretchDepth));
console.log("stretch tree of depth "+ stretchDepth+ "\t check: "+ check);

const longLivedTree = new TreeNode(
    bottomUpTree(maxDepth-1),
    bottomUpTree(maxDepth-1)
);

for (let depth=4; depth<=maxDepth; depth+=2){
    const iterations = 1 << maxDepth - depth + 4;
    check = 0;
    for (let i=1; i<=iterations; i++){
        check += itemCheck(bottomUpTree(depth));
    }
    console.log(iterations+"\t trees of depth "+ depth +"\t check: " + check);
}

console.log("long lived tree of depth "+ maxDepth
            + "\t check: "+ itemCheck(longLivedTree));
/*
function TreeNode(left,right,item){
   this.left = left;
   this.right = right;
}

TreeNode.prototype.itemCheck = function(){
   if (this.left==null) return 1;
   else return 1 + this.left.itemCheck() + this.right.itemCheck();
}

function bottomUpTree(depth){
   if (depth>0){
      return new TreeNode(
          bottomUpTree(depth-1)
         ,bottomUpTree(depth-1)
      );
   }
   else {
      return new TreeNode(null,null);
   }
}

function runBinaryTreesJS(){
	var minDepth = 4;
	var n = 21;
	var maxDepth = Math.max(minDepth + 2, n);
	var stretchDepth = maxDepth + 1;

	var check = bottomUpTree(stretchDepth).itemCheck();
	console.log("stretch tree of depth " + stretchDepth + "\t check: " + check);

	var longLivedTree = bottomUpTree(maxDepth);
	for (var depth=minDepth; depth<=maxDepth; depth+=2){
   		var iterations = 1 << (maxDepth - depth + minDepth);

   		check = 0;
   		for (var i=1; i<=iterations; i++){
      			check += bottomUpTree(depth).itemCheck();
   		}
   		console.log(iterations + "\t trees of depth " + depth + "\t check: " + check);
	}

	console.log("long lived tree of depth " + maxDepth + "\t check: " 
   	+ longLivedTree.itemCheck());
}

runBinaryTreesJS()*/