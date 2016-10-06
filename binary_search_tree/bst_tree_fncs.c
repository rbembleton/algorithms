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
      (*tempL).parent = pNode;
    }
  } else if (currVal < val) {
    if (pNode -> right != NULL) {
      insert (pNode -> right, val);
    } else {
      BSTNode *tempR = createNode(val);
      (*pNode).right = tempR;
      (*tempR).parent = pNode;
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

BSTNode * findMaxNode (BSTNode *pNode) {
  if (pNode == NULL) { return NULL; }
  if (pNode -> right == NULL) { return pNode; };
  return findMaxNode(pNode -> right);
};


BSTNode * findMinNode (BSTNode *pNode) {
  if (pNode == NULL) { return NULL; }
  if (pNode -> left == NULL) { return pNode; };
  return findMaxNode(pNode -> left);
};

void delete (BSTNode *pNode, int val) {
  BSTNode *foundNode = searchTree(pNode, val);
  if (foundNode == NULL) { return; }
  BSTNode *toAssign = NULL;

  if ((*foundNode).left == NULL && (*foundNode).right == NULL) {
    toAssign = NULL;
  } else if ((*foundNode).left && (*foundNode).right == NULL) {
    toAssign = (*foundNode).left;
  } else if ((*foundNode).right && (*foundNode).left == NULL) {
    toAssign = (*foundNode).right;
  } else if ((*foundNode).left && (*foundNode).right) {
    if ((*(*foundNode).left).left == NULL && (*(*foundNode).left).right == NULL) {
      toAssign = (*foundNode).left;
      (*((*foundNode).left)).right = (*foundNode).right;
    } else if ((*(*foundNode).right).left == NULL && (*(*foundNode).right).right == NULL) {
      toAssign = (*foundNode).right;
      (*((*foundNode).right)).left = (*foundNode).left;
    } else {
      int leftDepth = treeDepth((*foundNode).left);
      int rightDepth = treeDepth((*foundNode).right);

      if (leftDepth <= rightDepth) {
        BSTNode *maxNode = findMaxNode((*foundNode).left);
        toAssign = createNode(maxNode -> value);
        (*toAssign).right = (*foundNode).right;
        (*((*foundNode).right)).parent = toAssign;
        (*toAssign).left = (*foundNode).left;
        (*((*foundNode).left)).parent = toAssign;
        delete(toAssign -> left, maxNode -> value);
      } else {
        BSTNode *minNode = findMinNode((*foundNode).right);
        toAssign = createNode(minNode -> value);
        (*toAssign).right = (*foundNode).right;
        (*((*foundNode).right)).parent = toAssign;
        (*toAssign).left = (*foundNode).left;
        (*((*foundNode).left)).parent = toAssign;
        delete(toAssign -> right, minNode -> value);
      }

    }
  }

  if ((*foundNode).parent && foundNode -> parent -> value > val) {
    (*((*foundNode).parent)).left = toAssign;
  } else if ((*foundNode).parent && foundNode -> parent -> value < val) {
    (*((*foundNode).parent)).right = toAssign;
  }

  if (toAssign != NULL) {
    (*toAssign).parent = (*foundNode).parent;
  }

  if (pNode == foundNode && (*pNode).parent == NULL) {
    (*pNode).value = (*toAssign).value;
    (*pNode).parent = (*toAssign).parent;
    (*pNode).right = (*toAssign).right;
    (*pNode).left = (*toAssign).left;
    (*((*pNode).left)).parent = pNode;
    (*((*pNode).right)).parent = pNode;
    free(toAssign);
  } else {
    free(foundNode);
  }


};


int treeDepth (BSTNode *pNode) {
  if (pNode -> left || pNode -> right) {
    if (pNode -> left && pNode -> right) {
      int leftDepth = treeDepth(pNode -> left) + 1;
      int rightDepth = treeDepth(pNode -> right) + 1;
      return leftDepth > rightDepth ? leftDepth : rightDepth;
    } else if (pNode -> left) {
      return treeDepth(pNode -> left) + 1;
    } else if (pNode -> right) {
      return treeDepth(pNode -> right) + 1;
    }
  } else {
    return 1;
  }
  return 0;
};
