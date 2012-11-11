/*
 * =====================================================================================
 *
 *       Filename:  print_library.h
 *
 *    Description:  j
 *
 *        Version:  1.0
 *        Created:  11/11/2012 15:18:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#define print_newline printf("\n");
#define swap(A, B)  do { A ^= B; B ^= A; A ^= B;  } while (0)

void print_list(const int *list, size_t length);
void reverse_list(int *list, size_t length);
void reverse_list_from(int *list, size_t starting_point, size_t length);
