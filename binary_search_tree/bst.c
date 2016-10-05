#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>
#include "bst_node.h"
#include "bst_tree_fncs.h"
#include "bst_visualize.h"

// TO RUN: ./bst
// TO COMPILE: gcc -o bst bst_node.c bst_tree_fncs.c bst_visualize.c bst.c

void createRandomTree (BSTNode *pNode, int treeSize);

int main (void) {
  BSTNode *rootNodeP = createNode(16);
  createRandomTree(rootNodeP, 32);

  visualizeTree(rootNodeP);

  clearTree(rootNodeP, 0);

  return 0;
}

void createRandomTree (BSTNode *pNode, int treeSize) {
  int arr[treeSize];
  int rootVal = pNode -> value;
  srand(time(NULL));

  for (int i = 0; i < treeSize; i++) {
    if (i >= rootVal) {
      arr[i] = i + 1;
    } else {
      arr[i] = i;
    }
  }

  for (int i = 0; i < treeSize; i++) {
    int new_rand = (rand() % treeSize);
    int temp_arr_val = arr[new_rand];
    arr[new_rand] = arr[i];
    arr[i] = temp_arr_val;
  }

  for (int i = 0; i < treeSize; i++) {
    insert(pNode, arr[i]);
  }

  return;
};
