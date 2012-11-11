/*
 * =====================================================================================
 *
 *       Filename:  print_library.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/11/2012 15:18:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

void print_list(const int *list, size_t length){
  size_t i = 0;
  
  for (i = 0; i < length; i++) {
    printf("%d ", list[i]);
  }

  return;
}
