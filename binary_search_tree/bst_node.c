#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct BSTNode {
  int value;
  struct BSTNode *left;
  struct BSTNode *right;
}BSTNode;

BSTNode createNode (int val);
void insert (BSTNode *node, int val);
void show (BSTNode node);

int main (void) {
  BSTNode rootNode = createNode(4);

  insert(&rootNode, 3);
  insert(&rootNode, 5);


  show(rootNode);


  return 0;
}

BSTNode createNode (int val) {
  BSTNode temp;
  temp.value = val;
  temp.left = NULL;
  temp.right = NULL;
  return temp;
};

void insert (BSTNode *node, int val) {
  if ((*node).value > val) {
    if ((*node).left != NULL) {
      insert ((*node).left, val);
    } else {
      BSTNode temp = createNode(val);
      (*node).left = &temp;
    }
  } else if ((*node).value < val) {
    if ((*node).right != NULL) {
      insert ((*node).right, val);
    } else {
      BSTNode temp = createNode(val);
      (*node).right = &temp;
    }
  }
  return;
};

void show (BSTNode node) {
  if (node.left != NULL) { show(*node.left); }
  printf("%d\n", node.value );
  if (node.right != NULL) { show(*node.right); }
  return;
};
