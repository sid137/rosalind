/* 
 * Implementation of Pandita permutation algorithm taken from  
 * http://eusebeia.dyndns.org/epermute 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dbg.h"
#include "print_library.h"
#include "permutation.h"


int main(){
  int list[3] = {1,2,3};


  int i, j;
  int permutation_number = 2;
  bool imax_found, permuted = true;

  int length = sizeof(list)/sizeof(int);
  printf("Length is %d\n", length);
  printf("Starting list: \n");
  printf("1: ");
  print_list(list, length);
  while(permuted) {
    int imax = 0;
    int jmax = length-1;
    imax_found = false;
    for (i = 0; i < length-1; i++){
      if (list[i] < list[i+1]) {
        imax = i;
        imax_found = true;
      }
    }
    printf("imax: %d i: %d  imax_found: %d  jmax:%d\\\\n", imax, i, imax_found, jmax);
    if (!imax_found) {
      reverse_list(list, length);
      permuted = false;
      printf("Found lexicographically least permutation:\\\\n"); 
      print_list(list, length);
      break;
    }
    for (j = length-1; j > imax; j--){
      if (list[j] > list[imax]) {
        jmax = j;
        break;
      }
    }
    printf("imax: %d i: %d  imax_found: %d  jmax:%d\\\\n", imax, i, imax_found, jmax);
    printf("S: ");
    swap(list[imax], list[jmax]);
    print_list(list, length);
    printf("R: ");
    reverse_list_from(list, imax+1, length);
    print_list(list, length);
    printf("%d: ", permutation_number++);
    print_list(list, length);

  }

  return 0;
}
