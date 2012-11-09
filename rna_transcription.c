#include <stdio.h>
#include <ctype.h>
#include "dbg.h"

#define MAX_DNA 1000

int main(){
  FILE * fp = fopen("rosalind_rna.txt", "r");
  check(fp, "Unable to open rosalind_rna.txt"); 

  char dna[MAX_DNA];
  char *sp;
  int i;

  sp = fgets(dna, MAX_DNA, fp);
  check(sp != NULL, "Unable to read data from the file");
  fclose(fp);

  printf("The dna string is %s\n", dna);

  /* Assumes that the sting is properly terminated */
  for (i = 0; i < MAX_DNA && dna[i] != '\0'; i++ ){
    char symbol = toupper(dna[i]);
    if (symbol == 'T') { symbol = 'U';}
    printf("%c", symbol);
  }

  return 0;

error:
  return 1;
}
