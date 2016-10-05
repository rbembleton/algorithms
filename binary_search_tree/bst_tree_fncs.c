#include <stdio.h>
#include <stdlib.h>
#include "bst_node.h"
#include "bst_tree_fncs.h"


void clearTree (BSTNode *pNode, int show) {
  if ((*pNode).left != NULL) {
    clearTree((*pNode).left, show);
  }
  if ((*pNode).right != NULL) {
    clearTree((*pNode).right, show);
  }
  if (show == 1) {
    printf("free %d\n", (*pNode).value ? (*pNode).value : 0);
  }
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

BSTNode * searchTree (BSTNode *pNode, int val) {
  if (pNode -> value == val) {
    return pNode;
  } else if (pNode -> value > val) {
    if (pNode -> left != NULL) {
      return searchTree (pNode -> left, val);
    } else {
      return NULL;
    }
  } else if (pNode -> value < val) {
    if (pNode -> right != NULL) {
      return searchTree (pNode -> right, val);
    } else {
      return NULL;
    }
  }
  return NULL;
};
