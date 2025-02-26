#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

/**
 * sandpiles_sum - compute two sandpiles sum
 * @grid1: Left 3x3 grid
 * @grid2: Right 3x3 grid
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}

	/* Check if grid1 is unstable */
	while (check_if_unstable(grid1) == 0)
	{
		printf("=\n");
		print_grid(grid1);
		topple_grid(grid1);
	}
}

/**
 * check_if_unstable - check if a grid is unstable
 * @grid1: the grid to check for values superior to 3
 *
 * Return: 0 if true, 1 if false
 */

int check_if_unstable(int grid1[3][3])
{
	int i = 0;
	int j = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid1[i][j] > 3)
			{
				return (0);
			}
		}
	}
	return (1);
}

/**
 * topple_grid - topple grid numbers if superior to 3
 * @grid1: the grid to topple
 */

void topple_grid(int grid1[3][3])
{
	int i = 0;
	int j = 0;
	int topple[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			topple[i][j] = (grid1[i][j] > 3) ? 1 : 0;
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (topple[i][j] == 1)
			{
				grid1[i][j] -= 4;
				if (i > 0)
				{
					grid1[i - 1][j] += 1;
				}
				if (i < 2)
				{
					grid1[i + 1][j] += 1;
				}
				if (j > 0)
				{
					grid1[i][j - 1] += 1;
				}
				if (j < 2)
				{
					grid1[i][j + 1] += 1;
				}
			}
		}
	}
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
