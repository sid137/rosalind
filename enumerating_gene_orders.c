#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

/* O(n) */
int permutation_count(int number){

  int i;
  int count = 1;
  for (i = 1; i <= number; i++) {
    count *= i;
  }

  return count;
}


void permutation(int *list){

}

void print_permutations(int number){
  int *list = malloc(sizeof(int)*number);
  int number_of_permutations = permutation_count(number);
  int i;
  memset(list, 0, number);

  /* O(n) */
  for (i = 0; i < number; i++){
    list[i] = i+1;
  }

  for (i = 0; i < number; i++){
    printf("%d", list[i]);
    /* perm = i + perm(list/i); */
  }


  free(list); 
}
int main(){
  int number;

  printf("Enter a number: ");
  fscanf(stdin, "%d", &number);

  printf("The permutations of %d are:\n", number); 
  printf("%d\n", permutation_count(number));
  print_permutations(number);
  printf("\n"); 

  return 0;
}
