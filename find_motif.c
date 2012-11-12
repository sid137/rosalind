#include <stdio.h>
#include "dbg.h"

#define STRING_SIZE 1000
#define remove_newline(A) if (A[strlen(A)-1] == '\n') {A[strlen(A)-1] = '\0'; }
#define print_newline printf("\n");

#define true 1
#define false 0

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


  int i, j, m, location;
  int match_locations[STRING_SIZE];
  memset(&match_locations, 0, STRING_SIZE);

  char no_match;
  m = 0;
  int needle_size = strnlen(needle, STRING_SIZE);
  for (i = 0; i < (int) strlen(haystack) - needle_size + 1; i++) {
    no_match = false;
    if (haystack[i] == needle[0] && haystack[i+needle_size-1] == needle[needle_size-1]) {
      j = 0;
      // do O(m) scan to verify match
      while (!no_match && j <= needle_size) {
        if (needle[j] != haystack[i+j]) {
          no_match = true;
          break; 
        }
        if (j == needle_size-1) {
          location = i+1;
          printf("%c: Match at %d:%d\n", haystack[i], location, i+j);
          match_locations[m++] = location;
        }
        j++;
      }
    } else {
      printf("%c\n", haystack[i]);
    }
  }

  for (i = 0; i < m; i++) {
    printf("%d ", match_locations[i]);
  }
  print_newline;

  goto success;
success:
  fclose(dp);
  return 0;

error:
  return 1;
}
