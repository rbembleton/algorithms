#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct BSTNode {
  int value;
  struct BSTNode *left;
  struct BSTNode *right;
}BSTNode;

BSTNode createNode (int val);
void insert (BSTNode *pNode, int val);
void show (BSTNode *pNode);

int main (void) {
  BSTNode rootNode = createNode(4);
  BSTNode *rootNodeP = &rootNode;
  printf("%d\n", (*rootNodeP).left == NULL ? 0 : (*rootNodeP).left -> value );
  printf("%d\n", (*rootNodeP).value == NULL ? 0 : (*rootNodeP).value );
  printf("%d\n", (*rootNodeP).right == NULL ? 0 : (*rootNodeP).right -> value );
  // show(&(*rootNodeP));

  insert(rootNodeP, 3);
  printf("%d\n", (*rootNodeP).left == NULL ? 0 : (*rootNodeP).left -> value );
  printf("%d\n", (*rootNodeP).value == NULL ? 0 : (*rootNodeP).value );
  printf("%d\n", (*rootNodeP).right == NULL ? 0 : (*rootNodeP).right -> value );
  // show(&(*rootNodeP));

  insert(rootNodeP, 6);
  printf("%d\n", (*rootNodeP).left == NULL ? 0 : (*rootNodeP).left -> value );
  printf("%d\n", (*rootNodeP).value == NULL ? 0 : (*rootNodeP).value );
  printf("%d\n", (*rootNodeP).right == NULL ? 0 : (*rootNodeP).right -> value );


  show(rootNodeP);

  return 0;
}

BSTNode createNode (int val) {
  BSTNode newNode;
  printf("set val: %d\n", val );
  newNode.value = val;
  newNode.left = NULL;
  newNode.right = NULL;
  printf("set val: %d\n", newNode.value );
  return newNode;
};

void insert (BSTNode *pNode, int val) {
  // printf("%d, %d\n", node -> value, val);
  int currVal = (*pNode).value;
  if (currVal > val) {
    if (pNode -> left != NULL) {
      insert (pNode -> left, val);
    } else {
      BSTNode tempL = createNode(val);
      (*pNode).left = &tempL;
      printf("set val: %d\n", tempL.value );
      printf("set val: %d\n", (*pNode).left -> value );
    }
  } else if (currVal < val) {
    if (pNode -> right != NULL) {
      insert (pNode -> right, val);
    } else {
      BSTNode tempR = createNode(val);
      (*pNode).right = &tempR;
      printf("set val: %d\n", tempR.value );
      printf("set val: %d\n", (*pNode).right -> value );
    }
  }
  printf("left val: %d\n", (*pNode).left ? (*pNode).left -> value : 0);
  printf("right val: %d\n", (*pNode).right ? (*pNode).right -> value : 0);
  return;
};

void show (BSTNode *pNode) {
  printf("%d\n", (*pNode).left == NULL ? 0 : (*pNode).left -> value );
  printf("%d\n", (*pNode).value == NULL ? 0 : (*pNode).value );
  printf("%d\n", (*pNode).right == NULL ? 0 : (*pNode).right -> value );
  //
  // if (pNode -> left != NULL) { show(pNode -> left); }
  // printf("%d\n", pNode -> value );
  // if (pNode -> right != NULL) { show(pNode -> right); }
  return;
};
