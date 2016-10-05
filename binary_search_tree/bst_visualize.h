void visualizeTree (BSTNode *pNode);
int treeDepth (BSTNode *pNode);
int printNumberRow (BSTNode *pNode, int row, int spaces);
void printLineRow (BSTNode *pNode, int row, int spaces);

void visualizeTree (BSTNode *pNode) {
  int allNulls = 0;
  int startingSpaces = pow(2, treeDepth(pNode) - 1);

  for (int i = 1; allNulls == 0; i++) {
    allNulls = printNumberRow(pNode, i, startingSpaces);
    printf("\n");
    printLineRow(pNode, i, startingSpaces);
    printf("\n");
  }

  return;
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

void printLineRow (BSTNode *pNode, int row, int spaces) {
  if (row == 1) {
    if (pNode != NULL) {
      for (size_t i = 0; i < (spaces >= 4 ? spaces / 2 + (floor(spaces / 4)) : spaces / 2); i++) { printf(" "); }
      if (pNode -> left) {
        printf("/");
      } else {
        printf(" ");
      }
      for (size_t i = 0; i < (spaces >= 4 ? spaces - (floor(spaces / 2) + 1) : spaces - 2); i++) { printf(" "); }
      if (pNode -> right) {
        printf("\\");
      } else {
        printf(" ");
      }
      for (size_t j = 0; j < (spaces >= 4 ? spaces / 2 + (floor(spaces / 4) - 1): spaces / 2 ); j++) { printf(" "); }
    } else {
      for (size_t i = 0; i < spaces * 2; i++) { printf(" "); }
    }
    return;
  } else {
    printLineRow(pNode && pNode -> left ? pNode -> left : NULL, row - 1, spaces / 2);
    printLineRow(pNode && pNode -> right ? pNode -> right : NULL, row - 1, spaces / 2);
  }
  return;
};

int printNumberRow (BSTNode *pNode, int row, int spaces) {
  int left = 1;
  int right = 1;
  if (row == 1) {
    int leftSpaces = (pNode != NULL && floor((pNode -> value) / 10) > 0)  ? spaces - 1 : spaces;
    for (size_t i = 0; i < leftSpaces; i++) { printf(" "); }
    if (pNode == NULL) {
      printf(" ");
    } else {
      printf("%d", (pNode -> value) ? pNode -> value : 0 );
    }
    for (size_t j = 0; j < spaces - 1; j++) { printf(" "); }
    return (pNode && pNode -> value && (pNode -> left || pNode -> right)) ? 0 : 1;
  } else {
    left = printNumberRow(pNode && pNode -> left ? pNode -> left : NULL, row - 1, spaces / 2);
    right = printNumberRow(pNode && pNode -> right ? pNode -> right : NULL, row - 1, spaces / 2);
  }
  return (left == 0 || right == 0) ? 0 : 1;
};
