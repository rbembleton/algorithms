#ifndef _BSTNODE_H_
#define _BSTNODE_H_

typedef struct DynamicArray {
  int *start;
  int length;
  int size;
}DynamicArray;

DynamicArray * newDynamicArray (void);
void push (DynamicArray *dynArr, int val);
void show (DynamicArray *dynArr);
int pop (DynamicArray *dynArr);
int valAt (DynamicArray *dynArr, int pos);
void doubleSize (DynamicArray *dynArr);
DynamicArray * concat (DynamicArray *firstArr, DynamicArray *secondArr);

#endif
