#include <stdio.h>
#include "dbg.h"

#define MASS_TABLE_LENGTH 20
#define PROTEIN_SIZE 1000+1

typedef struct {
  char protein;
  double mass;
} monoisotopic_mass;


double protein_mass(const char protein, monoisotopic_mass *mass_table) {
  int i;
  for (i = 0; i < MASS_TABLE_LENGTH; i++) {
    if (mass_table[i].protein == protein) {
      return mass_table[i].mass;
    }
  }

  return 0;
}

int main(){

  FILE *lp = fopen("monoisotopic_mass_table.txt", "r");
  check(lp != NULL, "Could not open the monoisotopic mass table.\n");

  monoisotopic_mass mass_table[MASS_TABLE_LENGTH];

  int i = 0;
  char buf[2];
  while(fscanf(lp, "%c %lf", &mass_table[i].protein, &mass_table[i].mass) != EOF && i < MASS_TABLE_LENGTH) {
    fgets(buf, 2, lp);
    printf("Loading mass %0.5f for amino acid %c\n", mass_table[i].mass, mass_table[i].protein);
    i++;
  }



  FILE *fp = fopen("calculating_protein_mass_input.txt", "r");
  check(fp != NULL, "Could not open the input file\n");
  
  char input[PROTEIN_SIZE];
  fgets(input, PROTEIN_SIZE, fp);
  if (input[strlen(input)-1] == '\n') {
    input[strlen(input)-1] = '\0';
  }
  int protein_count = strlen(input);
  printf("The input protein string has %d proteins in: %s\n", protein_count, input); 


  double mass_sum = 0.0;
  for (i = 0; input[i] != '\0'; i++) {
    mass_sum += protein_mass(input[i], mass_table);
    printf("%d: %c %f\n", i, input[i], protein_mass(input[i], mass_table));
  }


  printf("The total mass of the protein is %0.2f Da\n", mass_sum);



  goto success;

success:
  fclose(lp); 
  fclose(fp);
  return 0;

error:
  return -1;
}
