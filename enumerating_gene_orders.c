#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"
#include "permutation.h"

/* O(n) */

void print_permutations(int number){
  int length = number;
  int *list = malloc(sizeof(int)*length);
  memset(list, 0, length);

  /* Fill list from 1 to n */
  int i;
  for (i = 0; i < length; i++){
    list[i] = i+1;
  }

  print_all_permutations(list, length); 

  free(list); 
}

int main(){
  int number;

  printf("Enter a number: ");
  fscanf(stdin, "%d", &number);

  printf("The permutations of %d are:\n", number); 
  printf("%d\n", permutation_count(number));
  print_permutations(number);

  return 0;
}
