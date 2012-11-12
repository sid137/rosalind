/*
 * =====================================================================================
 *
 *       Filename:  permutation.c
 *
 *    Description:  :
 *
 *        Version:  1.0
 *        Created:  11/11/2012 19:00:47
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdbool.h>
#include "dbg.h"
#include "print_library.h"
#include "permutation.h"

int permutation_count(int number){

  int i;
  int count = 1;
  for (i = 1; i <= number; i++) {
    count *= i;
  }

  return count;
}

void permute(int *list, size_t length) {
  int i, j;

  int imax = 0;
  int jmax = length-1;
  bool imax_found = false;

  for (i = 0; i < (int) length-1; i++){
    if (list[i] < list[i+1]) {
      imax = i;
      imax_found = true;
    }
  }

  if (!imax_found) {
    reverse_list(list, length);
    return;
  }

  for (j = length-1; j > imax; j--){
    if (list[j] > list[imax]) {
      jmax = j;
      break;
    }
  }

  swap(list[imax], list[jmax]);
  reverse_list_from(list, imax+1, length);

  return;
}

void print_all_permutations(int *list, size_t length) {
  int i, number_of_permutations;
  number_of_permutations = permutation_count(length);

  for (i = 0; i < number_of_permutations; i++){
    print_list(list, length);
    permute(list, length);
  }
  return ;
}
