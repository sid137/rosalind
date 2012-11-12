/*
 * =====================================================================================
 *
 *       Filename:  permutation.h
 *
 *    Description:  Library to manage permutations of integer lists
 *
 *        Version:  1.0
 *        Created:  11/11/2012 19:00:23
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Sidney Burks
 *   Organization:  
 *
 * =====================================================================================
 */

int permutation_count(int number);
void permute(int *list, size_t length);
void print_all_permutations(int *list, size_t length);
