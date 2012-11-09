#include <stdio.h>
#include <ctype.h>
#include "dbg.h"

#define MAX_DNA 1000

int main(){
  FILE * fp = fopen("rosalind_dna.txt", "r");
  check(fp, "Unable to open rosalind_dna.txt"); 

  char dna[MAX_DNA];
  char *sp;
  int i;
  int a_count = 0;
  int t_count = 0;
  int c_count = 0;
  int g_count = 0;

  sp = fgets(dna, MAX_DNA, fp);
  check(sp != NULL, "Unable to read data from the file");
  fclose(fp);

  printf("The dns string is %s\n", dna);

  /* Assumes that the sting is properly terminated */
  for (i = 0; i < MAX_DNA && dna[i] != '\0'; i++ ){
    char symbol = toupper(dna[i]);
    if (symbol == '\n') {
      continue;
    }

    switch (symbol) {
      case 'A':
        a_count++;
        break;
      case 'G':
        g_count++;
        break;
      case 'C':
        c_count++;
        break;
      case 'T':
        t_count++;
        break;
      default:
        printf("Houston, we have a problem\n");
    }
  }

  printf("%d %d %d %d\n", a_count, c_count, g_count, t_count);
  return 0;

error:
  return 1;
}
