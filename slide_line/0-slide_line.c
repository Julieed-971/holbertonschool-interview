#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#include "slide_line.h"

/**
 * slide_line -  slides and merges an array of integers
 * @line: pointer to an array of integer
 * @size: size of the array
 * @direction: left or right
 *
 * Return: 1 upon success or 0 upon failure
 */

int slide_line(int *line, size_t size, int direction)
{
	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		merge_left(line, size);
		slide_left(line, size);
		return (1);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		merge_right(line, size);
		slide_right(line, size);
		return (1);
	}
	return (0);
}

/**
 * slide_left -  slides an array of integers to the left
 * @line: pointer to an array of integer
 * @size: size of the array
 */

void slide_left(int *line, size_t size)
{
	size_t i = 0;
	size_t j = 0;

	while (j < size)
	{
		if (line[j] != 0)
		{
			line[i] = line[j];
			i++;
		}
		j++;
	}
	while (i < size)
	{
		line[i] = 0;
		i++;
	}
}

/**
 * slide_right -  slides an array of integers to the left
 * @line: pointer to an array of integer
 * @size: size of the array
 */

void slide_right(int *line, size_t size)
{
	int i = size - 1;
	int j = size - 1;

	while (j >= 0)
	{
		if (line[j] != 0)
		{
			line[i] = line[j];
			i--;
		}
		j--;
	}
	while (i >= 0)
	{
		line[i] = 0;
		i--;
	}
}

/**
 * merge_left -  merges equal values in an array of integers
 * @line: pointer to an array of integer
 * @size: size of the array
 */

void merge_left(int *line, size_t size)
{
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
		{
			continue;
		}
		j = i + 1;
		while (j < size)
		{
			if (line[j] != 0)
			{
				if (line[i] == line[j])
				{
					line[i] += line[j];
					line[j] = 0;
				}
				break;
			}
			j++;
		}
	}
}

/**
 * merge_right -  merges equal values in an array of integers
 * @line: pointer to an array of integer
 * @size: size of the array
 */

void merge_right(int *line, size_t size)
{
	int i, j;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] == 0)
		{
			continue;
		}
		j = i - 1;
		while (j >= 0)
		{
			if (line[j] != 0)
			{
				if (line[i] == line[j])
				{
					line[i] += line[j];
					line[j] = 0;
				}
			}
			break;
		}
		j--;
	}
}
