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

void *reverse_list(int *list){
  int length = sizeof(list)/sizeof(int);
  int i;
  int *new_list = malloc(sizeof(list));

  for (i = length-1; i > 0; i--){
    new_list[length-1-i] = list[i]; 
  }

  free(new_list);
}

int main(){
  int list[3] = {1,2,3};


  int i, j, k;
  bool permuted = true;

  int length = sizeof(list)/sizeof(int);
  while(permuted) {
    int imax = 0;
    int jmax = 0;
      for (i = 0; i < length-2; i++){
        if (list[i] < list[i+1]) {
          imax = i;
        }
      }
      if (imax == 0) {
        reverse_list(list);
        permuted = false;
      }

  }

  for (k = 0; k < 3; k++){
    printf("%d ", list[k]);
  }
  print_newline;
  return 0;
}
