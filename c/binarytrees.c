
/* The Computer Language Benchmarks Game
 * http://benchmarksgame.alioth.debian.org/

   contributed by Kevin Carson
   compilation:
       gcc -O3 -fomit-frame-pointer -funroll-loops -static binary-trees.c -lm
       icc -O3 -ip -unroll -static binary-trees.c -lm

   *reset*
*/

#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <emscripten/emscripten.h>
#include <string.h>
typedef struct tn {
    struct tn*    left;
    struct tn*    right;
} treeNode;


treeNode* NewTreeNode(treeNode* left, treeNode* right)
{
    treeNode*    new;

    new = (treeNode*)malloc(sizeof(treeNode));

    new->left = left;
    new->right = right;

    return new;
} /* NewTreeNode() */


long ItemCheck(treeNode* tree)
{
    if (tree->left == NULL)
        return 1;
    else
        return 1 + ItemCheck(tree->left) + ItemCheck(tree->right);
} /* ItemCheck() */


treeNode* BottomUpTree(unsigned depth)
{
    if (depth > 0)
        return NewTreeNode
        (
            BottomUpTree(depth - 1),
            BottomUpTree(depth - 1)
        );
    else
        return NewTreeNode(NULL, NULL);
} /* BottomUpTree() */


void DeleteTree(treeNode* tree)
{
    if (tree->left != NULL)
    {
        DeleteTree(tree->left);
        DeleteTree(tree->right);
    }

    free(tree);
} /* DeleteTree() */

/*int main() {
    printf("WebAssembly binarytrees module loaded\n");
    return 0;
}*/

int EMSCRIPTEN_KEEPALIVE binarytrees ()
{
    //clock_t begin;
    //begin = clock();
    
    unsigned   N, depth, minDepth, maxDepth, stretchDepth;
    treeNode   *stretchTree, *longLivedTree, *tempTree;

    N = atol("21");
    minDepth = 4;

    if ((minDepth + 2) > N)
        maxDepth = minDepth + 2;
    else
        maxDepth = N;

    stretchDepth = maxDepth + 1;

    stretchTree = BottomUpTree(stretchDepth);
    //char*  step1 = ""; 
    printf
    (   //step1,
        "stretch tree of depth %u\t check: %li\n",
        stretchDepth,
        ItemCheck(stretchTree)
    );
    
    DeleteTree(stretchTree);

    longLivedTree = BottomUpTree(maxDepth);
    //char* step2 = "";
    for (depth = minDepth; depth <= maxDepth; depth += 2)
    {
        long    i, iterations, check;

        iterations = pow(2, maxDepth - depth + minDepth);

        check = 0;

        for (i = 1; i <= iterations; i++)
        {
            tempTree = BottomUpTree(depth);
            check += ItemCheck(tempTree);
            DeleteTree(tempTree);
        } /* for(i = 1...) */
        printf
        (   //step2,
            "%li\t trees of depth %u\t check: %li\n",
            iterations,
            depth,
            check
        );
    } /* for(depth = minDepth...) */
    //char* step3 ="";
    printf
    (   //step3,
        "long lived tree of depth %u\t check: %li\n",
        maxDepth,
        ItemCheck(longLivedTree)
    );
    //clock_t end = clock();
    //double time_taken = ((double)(end - begin))/CLOCKS_PER_SEC; // in seconds
    //char* step = (char*) malloc(strlen(step1) + strlen(step2) + strlen(step3) + 1);
    //strcpy(step,step1);
    //strcat(step,step2);
    //strcat(step,step3);
    return 0;
}
