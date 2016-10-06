#ifndef _BSTNODE_H_
#define _BSTNODE_H_

typedef struct BSTNode {
  int value;
  struct BSTNode *left;
  struct BSTNode *right;
  struct BSTNode *parent;
}BSTNode;

BSTNode * createNode (int val);

#endif
