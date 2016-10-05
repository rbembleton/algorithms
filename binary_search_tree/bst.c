#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bst_node.h"
#include "bst_tree_fncs.h"

int main (void) {
  BSTNode *rootNodeP = createNode(4);

  insert(rootNodeP, 3);
  insert(rootNodeP, 6);
  insert(rootNodeP, 5);

  show(rootNodeP);

  clearTree(rootNodeP);

  return 0;
}
