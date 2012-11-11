/*
 * =====================================================================================
 *
 *       Filename:  print_library.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/11/2012 15:18:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "print_library.h"
#define swap(A, B)  do { A ^= B; B ^= A; A ^= B;  } while (0)

void print_list(const int *list, size_t length){
  size_t i = 0;
  
  for (i = 0; i < length; i++) {
    printf("%d ", list[i]);
  }
  print_newline;
  return;
}



void reverse_list(int *list, size_t length) {
  int midpoint, i;

  midpoint = length/2;

  for (i = 0; i < midpoint; i++) {
    swap(list[i], list[length-1-i]);
    /* temp = list[i]; */
    /* list[i] = list[length-1-i]; */
    /* list[length-1-i] = temp; */
  }
  return;
}

void reverse_list_from(int *list, size_t starting_point, size_t length) {
  reverse_list(list+starting_point, length-starting_point);
  return;
}
