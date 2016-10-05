#include <stdio.h>

void clearTree (BSTNode *pNode);
void insert (BSTNode *pNode, int val);
void show (BSTNode *pNode);

void clearTree (BSTNode *pNode) {
  if ((*pNode).left != NULL) {
    clearTree((*pNode).left);
  }
  if ((*pNode).right != NULL) {
    clearTree((*pNode).right);
  }
  printf("free %d\n", (*pNode).value ? (*pNode).value : 0);
  free(pNode);
  return;
}

void insert (BSTNode *pNode, int val) {
  int currVal = (*pNode).value;
  if (currVal > val) {
    if (pNode -> left != NULL) {
      insert (pNode -> left, val);
    } else {
      BSTNode *tempL = createNode(val);
      (*pNode).left = tempL;
    }
  } else if (currVal < val) {
    if (pNode -> right != NULL) {
      insert (pNode -> right, val);
    } else {
      BSTNode *tempR = createNode(val);
      (*pNode).right = tempR;
    }
  }
  return;
};

void show (BSTNode *pNode) {
  if (pNode -> left != NULL) { show(pNode -> left); }
  printf("%d\n", pNode -> value );
  if (pNode -> right != NULL) { show(pNode -> right); }
  return;
};
