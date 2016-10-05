#include <stdio.h>

typedef struct BSTNode {
  int value;
  struct BSTNode *left;
  struct BSTNode *right;
}BSTNode;

BSTNode * createNode (int val);

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
  return newNode;
};
