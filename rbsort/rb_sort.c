#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(void) {
  int arr_length = 100000;
  int unsorted_arr[arr_length];
  printf("This is the fourth index of the array before populating: %d\n", unsorted_arr[4]);

  for (int i = 0; i < sizeof(unsorted_arr)/sizeof(int); i++) {
    unsorted_arr[i] = i + 1;
  }
  printf("This is the fourth index of the array after populating: %d\n", unsorted_arr[4]);

  for (int i = 0; i < arr_length; i++) {
    int new_rand = (rand() % arr_length);
    int temp_arr_val = unsorted_arr[new_rand];
    unsorted_arr[new_rand] = unsorted_arr[i];
    unsorted_arr[i] = temp_arr_val;
  }

  printf("This is the fourth index of the array after shuffling: %d\n", unsorted_arr[4]);

  int max = 0;
  for (int i = 0; i < arr_length; i++) {
    if (unsorted_arr[i] > max) {
      max = unsorted_arr[i];
    }
  }

  printf("This is the max value in the array: %d\n", max);
  max ++;

  int almost_sorted_arr[max];

  for (int i = 0; i < arr_length; i++) {
    almost_sorted_arr[unsorted_arr[i] % max] = unsorted_arr[i];
  }

  int sorted_arr[arr_length];
  int j = 0;

  for (int i = 0; i < sizeof(almost_sorted_arr)/sizeof(int); i++) {
    if (almost_sorted_arr[i]) {
      sorted_arr[j] = almost_sorted_arr[i];
      j++;
    }
  }

  printf("This is the fourth index of the array after sorting: %d\n", sorted_arr[4]);


  return 0;
}
