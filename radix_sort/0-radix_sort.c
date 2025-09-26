#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * get_max - Finds the maximum number in an array
 * @array: The array
 * @size: Number of elements
 * Return: The maximum value
 */
int get_max(int *array, size_t size)
{
	int max = array[0];

	for (size_t i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_by_digit - Stable counting sort according to digit
 * @array: The array
 * @size: Number of elements
 * @exponent: Digit position (1 = ones, 10 = tens, 100 = hundreds, ...)
 */
void counting_sort_by_digit(int *array, size_t size, int exponent)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};

	if (!output)
		return;

	/* Count occurrences of each digit */
	for (size_t i = 0; i < size; i++)
		count[(array[i] / exponent) % 10]++;

	/* Accumulate counts */
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build output array (right-to-left for stability) */
	for (ssize_t i = size - 1; i >= 0; i--)
	{
		int digit = (array[i] / exponent) % 10;

		output[count[digit] - 1] = array[i];
		count[digit]--;
	}

	/* Copy back */
	for (size_t i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integer in ascending order
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void radix_sort(int *array, size_t size)
{
	if (size >= 2)
	{
		int max = get_max(array, size);

		/* Do counting sort for each digit */
		for (int exp = 1; max / exp > 0; exp *= 10)
		{
			counting_sort_by_digit(array, size, exp);
			print_array(array, size);
		}
	}
}
