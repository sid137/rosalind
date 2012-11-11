#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"
#include "print_library.h"

void reverse_list(int *list, size_t length) {
  int midpoint, i;

  midpoint = length/2;

  for (i = 0; i < midpoint; i++) {
    swap(list[i], list[length-1-i]);
  }
}

int main() {
  int list[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int length;
  length = sizeof(list)/sizeof(int);

  print_list(list, length);
  reverse_list(list, length);
  print_newline;
  print_list(list, length);
  print_newline;

  int list2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  length = sizeof(list2)/sizeof(int);
  print_list(list2, length);
  reverse_list(list2, length);
  print_newline;
  print_list(list2, length);
  print_newline;

  return 0;
}
