#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"
#include "print_library.h"


int main() {
  int list[] = {1, 2, 3, 4, 5, 6, 7, 8};
  int length;
  length = sizeof(list)/sizeof(int);

  print_list(list, length);
  reverse_list(list, length);
  reverse_list(list, length);
  reverse_list_from(list, 0, length);
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

  int list3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  length = sizeof(list3)/sizeof(int);
  print_list(list3, length);
  reverse_list_from(list3, 4, length);
  print_newline;
  print_list(list3, length);
  print_newline;
  return 0;
}
