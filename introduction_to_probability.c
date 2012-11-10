#include <stdio.h>
#include "dbg.h"

#define MAX_PROB 20

float probability(float gc_content) {
  float probability = gc_content;
  float pg, pc, pa, pt;
  pg = pc = gc_content/2;
  pa = pt = (1-gc_content)/2; 

  probability = 2*pa*pa + 2*pg*pg; 
  return probability;
}

int main(){

  float list[MAX_PROB];
  memset(list, 0, sizeof(float) * MAX_PROB); 

  FILE *fp = fopen("introduction_to_probability_input.txt", "r");
  check(fp != NULL, "Problem opening input file");

  int i = 0;
  while(!feof(fp)){
    if(fscanf(fp, "%f", &list[i])) { i++; }
  }
  fclose(fp);

  int length = i;
  for (i = 0; i < length-1; i++) {
    printf("%0.6f ", probability(list[i]));
  }

  printf("\n"); 

  return 0;
error: 
  return 1;
}
