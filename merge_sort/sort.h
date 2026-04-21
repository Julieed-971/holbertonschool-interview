#ifndef SORT_H
#define SORT_H

#include <stdio.h>


void copy_and_split(int *array, int left, int middle, int right);
void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void recursive_merge_sort(int *array, int left, int right);

#endif /* SORT_H */
