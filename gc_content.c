#include <stdio.h>
#include <string.h>
#include "dbg.h"

#define NAME_SIZE 16
#define MAX_DNA 1000+2


float gc_content(char *dna){
  size_t i;
  int count = 0;

  for (i = 0; i < strlen(dna); i++){
    if ((dna[i] == 'G') || dna[i] == 'C') {
      count++;
    }
  }

  return 100.0*count/strlen(dna);
}

typedef struct {
  char name[NAME_SIZE];
  char dna[MAX_DNA];
} fasta_record;

int main(){

  char *rp;

  float cur_gc, max_gc = 0;

  FILE *fp = fopen("gc_content_input.txt", "r");
  check(fp != NULL, "Unable to open gc_content_input.txt");

  fasta_record rec, max_rec;

  while(!feof(fp)) {
    rp = fgets(rec.name, NAME_SIZE, fp); 
    if (rp == NULL) { break; }

    rec.name[strlen(rec.name)-1] = '\0'; 
    fgets(rec.dna, MAX_DNA, fp); 
    rec.dna[strlen(rec.dna)-1] = '\0'; 

    /* printf("Name read: %s\\n", rec.name);  */
    /* printf("DNA read: %s\\n", rec.dna);  */

    cur_gc = gc_content(rec.dna);
    /* printf("The GC-content is %0.4f \\n", cur_gc); */
    if (cur_gc > max_gc) {
      max_rec = rec;
      max_gc = cur_gc; 
    }
    /* printf("\\n"); */
  }

  printf("%s\n", max_rec.name+1);
  printf("%0.4f%%\n", gc_content(max_rec.dna));
  fclose(fp);

  return 0;

error:
  return -1;
}
