#ifndef _BST_TREE_FNCS_H_
#define _BST_TREE_FNCS_H_

void clearTree (BSTNode *pNode, int show);
int treeDepth (BSTNode *pNode);
void insert (BSTNode *pNode, int val);
void delete (BSTNode *pNode, int val);
void show (BSTNode *pNode);
BSTNode * searchTree (BSTNode *pNode, int val);
BSTNode * findMaxNode (BSTNode *pNode);
BSTNode * findMinNode (BSTNode *pNode);


#endif
