#include <stdio.h>
#include <stdlib.h>
#include "bst_node.h"

BSTNode * createNode (int val) {
  BSTNode *newNode;
  newNode = (BSTNode *)malloc(sizeof(BSTNode));
  if (newNode == NULL) {
    printf("Not enough memory\n");
    exit(0);
  }
  (*newNode).value = val;
  (*newNode).left = NULL;
  (*newNode).right = NULL;
  (*newNode).parent = NULL;
  return newNode;
};
