#include <stdio.h>
#include <ctype.h>
#include "dbg.h"

#define MAX_DNA 1000

int main(){
  FILE * fp = fopen("rosalind_reverse_compliment.txt", "r");
  check(fp, "Unable to open rosalind_reverse_compliment.txt"); 

  char dna[MAX_DNA];
  char *sp;
  int i;

  memset(dna, 0, MAX_DNA);
  sp = fgets(dna, MAX_DNA, fp);
  check(sp != NULL, "Unable to read data from the file");
  fclose(fp);

  printf("The dna string is %s\n", dna);

  for (i = MAX_DNA; i >= 0; i-- ){
    char symbol = toupper(dna[i]);
    switch(symbol) {
      case 'T': printf("A"); break;
      case 'A': printf("T"); break;
      case 'C': printf("G"); break;
      case 'G': printf("C"); break;
      default: break;
    }
  }
 
  printf("\n"); 
  return 0;

error:
  return 1;
}
