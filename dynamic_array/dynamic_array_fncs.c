#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array_fncs.h"

DynamicArray * newDynamicArray (void) {
  int *newPtr;
  newPtr = malloc(2 * sizeof(int));
  if (newPtr == NULL) {
    printf("Not enough memory\n");
    exit(0);
  }

  DynamicArray * newArr;
  newArr = (DynamicArray *)malloc(sizeof(DynamicArray));
  if (newArr == NULL) {
    printf("Not enough memory\n");
    exit(0);
  }

  (*newArr).start = newPtr;
  (*newArr).length = 0;
  (*newArr).size = 2;

  return newArr;
};

void doubleSize (DynamicArray *dynArr) {
  int *newPtr;
  newPtr = malloc(((*dynArr).size * 2) * sizeof(int));
  if (newPtr == NULL) {
    printf("Not enough memory\n");
    exit(0);
  }

  for (int i = 0; i < dynArr -> length; i++) {
    newPtr[i] = ((*dynArr).start)[i];
  }

  free(((*dynArr).start));

  (*dynArr).start = newPtr;
  (*dynArr).size *= 2;
};

void push (DynamicArray *dynArr, int val) {
  if (dynArr -> length < dynArr -> size) {
    ((*dynArr).start)[(dynArr -> length)] = val;
    (*dynArr).length ++;
  } else {
    doubleSize(dynArr);
    ((*dynArr).start)[(dynArr -> length)] = val;
    (*dynArr).length ++;
  }
  return;
};

int pop (DynamicArray *dynArr) {
  if (dynArr -> length > 1) {
    (*dynArr).length --;
    int poppedVal = (((*dynArr).start)[(dynArr -> length)]);
    (((*dynArr).start)[(dynArr -> length)]) = 0;
    return poppedVal;
  }
  return -1;
};

int valAt (DynamicArray *dynArr, int pos) {
  if (pos >= 0 && dynArr -> length > pos) {
    return ((*dynArr).start)[pos];
  } else if (pos < 0 && dynArr -> length >= (pos * -1)) {
    return ((*dynArr).start)[dynArr -> length + pos];
  }
  return -1;
};

void show (DynamicArray *dynArr) {
  printf("[");
  for (int i = 0; i < dynArr -> length; i++) {
    if (i == 0) {
      printf("%d", ((*dynArr).start)[i]);
    } else {
      printf(", %d", ((*dynArr).start)[i]);
    }
  }
  printf("]\n");
};
