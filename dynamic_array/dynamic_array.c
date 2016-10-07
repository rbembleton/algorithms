#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array_fncs.h"

// TO COMPILE: gcc -o dynamic_array dynamic_array.c dynamic_array_fncs.c
// TO RUN: ./dynamic_array

int main (void) {

  // Tests
  DynamicArray * myFirstArrPtr = newDynamicArray();
  push(myFirstArrPtr, 4);
  push(myFirstArrPtr, 3);
  push(myFirstArrPtr, 5);
  push(myFirstArrPtr, 6);
  show(myFirstArrPtr);

  DynamicArray * mySecondArrPtr = newDynamicArray();
  push(mySecondArrPtr, 2);
  push(mySecondArrPtr, 1);
  show(mySecondArrPtr);

  DynamicArray * myConcatArrPtr = concat(myFirstArrPtr, mySecondArrPtr);
  show(myConcatArrPtr);

  return 0;
};
