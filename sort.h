/* This header file contains 3 types of sorting functions.
 * quick sort, merge sort, and heap sort
 * Each of these sorting functions has string mode and number mode.
*/
#include "sort.c"
void num_quick_sort(int *arr, int len);
void str_quick_sort(char **strs, int len);
void num_merge_sort(int *arr, int len);
void str_merge_sort(char **strs, int len);
void num_heap_sort(int *arr, int len);
void str_heap_sort(char **strs, int len);