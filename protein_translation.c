#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbg.h"

#define NUM_CODONS 64
#define MAX_RNA 10000+1

typedef struct {
  char codon[4];
  char amino_acid;
} codon_mapping;

char *encode_codon(const char *codon, codon_mapping *codons){
  char * protein_string = "X";
  int i = 0;
  for (i = 0; i < NUM_CODONS; i++){
    if (strncmp(codon, codons[i].codon, 3) == 0) {
      protein_string = &codons[i].amino_acid;
      break;
    }
  }
  return protein_string;
}

int main(){
  FILE *fp = fopen("codon_table.txt", "r");
  check(fp != NULL, "Error opening codon table");

  codon_mapping *codons = malloc(NUM_CODONS * sizeof(codon_mapping)); 
  check_mem(codons);
  
  int i = 0;
  char buf[10];
  char temp[10];
  while(fgets(buf, 10, fp)) {
    sscanf(buf, "%s %s", (char *) &codons[i].codon, (char *) &temp);

    if (strncmp(temp, "Stop", 4) == 0) {
      codons[i].amino_acid = 'X';
    } else {
      codons[i].amino_acid = *temp;
    }

    printf("%s %c\n", codons[i].codon, codons[i].amino_acid);

    i++;
  }
  fclose(fp);


  FILE *dp = fopen("protein_translation_input.txt", "r");
  check(dp != NULL, "Unable to open data input file.\n");

  char input[MAX_RNA];
  check(fgets(input, MAX_RNA, dp) != NULL, "Unable to read data from dataset\n");
  if (input[strlen(input)-1] == '\n') {
    input[strlen(input)-1] = '\0';
  }
  fclose(dp);

  printf("The data has length %d: %s\n",(int) strlen(input), input);

  char tmp_codon[4];
  for (i = 0; i < (int) strlen(input)-1; i += 3) {
    strncpy(tmp_codon, &input[i], 3);
    tmp_codon[3] = '\0';
    printf("%d: %s\n", i, tmp_codon); 
  }

  printf("Encoded protein string:\n"); 

  char *protein;
  for (i = 0; i < (int) strlen(input)-1; i += 3) {
    strncpy(tmp_codon, &input[i], 3);
    tmp_codon[3] = '\0';
    protein = encode_codon(tmp_codon, codons);
    if (*protein == 'X') { break; }
    printf("%c", *protein); 
  }
  printf("\n");

  return 0;
error:
  return -1;
}
