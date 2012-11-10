#include <stdio.h>
#include "dbg.h"

#define MAX_DNA 1000

int hamming_distance(const char *str1, const char * str2){
  int length = strlen(str1);
  int i, count = 0;

  for (i = 0; i < length-1; i++){
    if (str1[i] != str2[i]) {
      count++;
      /* printf("%d: %c != %c\\n", count, str1[i], str2[i]); */
    }
  }

  return count;
}

int main() {
  char str1[MAX_DNA];
  char str2[MAX_DNA];
  FILE *fp = fopen("rosalind_point_mutations.txt", "r");

  fgets(str1, MAX_DNA, fp);
  fgets(str2, MAX_DNA, fp);

  printf("The hamming distance is:\n");
  printf("%d\n", hamming_distance(str1, str2));

  return 0;
}
