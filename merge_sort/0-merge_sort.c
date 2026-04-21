#include "sort.h"


/**
 * merge - merge sub arrays in the array
 *
 * @array: the original array to sort
 * @left_sub_array: the left sub array to merge
 * @right_sub_array: the right sub array to merge
 * @left: left of the array
 * @left_sub_array_size: size of the left sub array
 * @right_sub_array_size: size of the right array
 */

void merge(int *array, int *left_sub_array, int *right_sub_array,
	 int left, int left_sub_array_size, int right_sub_array_size)
{
	int i = 0;
	int j = 0;
	int k = left;

	while (i < left_sub_array_size && j < right_sub_array_size)
	{
		if (left_sub_array[i] <= right_sub_array[j])
		{
			array[k] = left_sub_array[i];
			i++;
		}
		else
		{
			array[k] = right_sub_array[j];
			j++;
		}
		k++;
	}
	while (i < left_sub_array_size)
	{
		array[k] = left_sub_array[i];
		i++;
		k++;
	}
	while (j < right_sub_array_size)
	{
		array[k] = right_sub_array[j];
		j++;
		k++;
	}
}
/**
 * copy_and_split - merges two subarrays or array
 *
 * @array: the array to divide, sort and merge back
 * @left: left index of the array to sort
 * @middle: middle index of the array to sort
 * @right: right index of the array to sort
 */

void copy_and_split(int *array, int left, int middle, int right)
{
	int i, j = 0;
	int left_sub_array_size = middle - left + 1;
	int right_sub_array_size = right - middle;

	int left_sub_array[left_sub_array_size];
	int right_sub_array[right_sub_array_size];

	printf("Merging...\n");
	for (i = 0; i < left_sub_array_size; i++)
	{
		left_sub_array[i] = array[left + i];
	}
	printf("[left]: ");
	print_array(left_sub_array, left_sub_array_size);


	for (j = 0; j < right_sub_array_size; j++)
	{
		right_sub_array[j] = array[middle + 1 + j];
	}
	printf("[right]: ");
	print_array(right_sub_array, right_sub_array_size);

	merge(array, left_sub_array, right_sub_array, left,
		 left_sub_array_size, right_sub_array_size);
	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * recursive_merge_sort - recursively divide, sort, and merge the array
 *
 * @array: array to merge sort
 * @left: left index of the array
 * @right: right index of the array
 */
void recursive_merge_sort(int *array, int left, int right)
{
	int middle = 0;
	int size = 0;
	int left_half_size = 0;

	if (left < right)
	{
		size = right - left + 1;
		left_half_size = size / 2;
		middle = left + left_half_size - 1;
		recursive_merge_sort(array, left, middle);
		recursive_merge_sort(array, middle + 1, right);

		copy_and_split(array, left, middle, right);
	}
}

/**
 * merge_sort - sort a list of integer in ascending order
 * using the top-down merge algorithm
 *
 * @array: the array of integer to sort
 * @size: length of the array
 */

void merge_sort(int *array, size_t size)
{
	int left = 0;
	int right = size - 1;

	if (size < 2)
	{
		return;
	}

	recursive_merge_sort(array, left, right);
}
