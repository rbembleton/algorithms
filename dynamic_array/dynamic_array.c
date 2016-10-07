#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array_fncs.h"

// TO COMPILE: gcc -o dynamic_array dynamic_array.c dynamic_array_fncs.c
// TO RUN: ./dynamic_array

int main (void) {

  // Tests
  DynamicArray * myArrPtr = newDynamicArray();
  push(myArrPtr, 4);
  push(myArrPtr, 3);
  show(myArrPtr);
  push(myArrPtr, 5);
  show(myArrPtr);
  push(myArrPtr, 6);
  show(myArrPtr);
  push(myArrPtr, 7);
  show(myArrPtr);
  push(myArrPtr, 8);
  show(myArrPtr);
  push(myArrPtr, 9);
  show(myArrPtr);
  push(myArrPtr, 11);
  show(myArrPtr);
  push(myArrPtr, 100);
  show(myArrPtr);
  printf("pop %d\n", pop(myArrPtr));
  printf("pop %d\n", pop(myArrPtr));
  push(myArrPtr, 2);
  show(myArrPtr);
  printf("Length: %d\n", myArrPtr -> length );

  printf("[4] %d\n", valAt(myArrPtr, 4) );
  printf("[0] %d\n", valAt(myArrPtr, 0) );
  printf("[-2] %d\n", valAt(myArrPtr, -2) );
  printf("[-3] %d\n", valAt(myArrPtr, -3) );
  printf("[-1] %d\n", valAt(myArrPtr, -1) );
  printf("[-8] %d\n", valAt(myArrPtr, -8) );
  printf("[-7] %d\n", valAt(myArrPtr, -7) );
  printf("[-9] %d\n", valAt(myArrPtr, -9) );

  return 0;
};
