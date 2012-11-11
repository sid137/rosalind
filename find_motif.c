#include <stdio.h>
#include "dbg.h"

#define STRING_SIZE 1000
#define remove_newline(A) if (A[strlen(A)-1] == '\n') {A[strlen(A)-1] = '\0'; }

int main(){

  FILE * dp = fopen("motif_input.txt", "r");
  check(dp, "Unable to open motif_input.txt\n");

  char haystack[STRING_SIZE];
  char needle[STRING_SIZE];

  fgets(haystack, STRING_SIZE, dp);
  fgets(needle, STRING_SIZE, dp);

  remove_newline(needle);
  remove_newline(haystack);

  printf("Haystack: %s\n", haystack);
  printf("Needle: %s\n", needle);

  goto success;
success:
  fclose(dp);
  return 0;

error:
  return 1;
}
