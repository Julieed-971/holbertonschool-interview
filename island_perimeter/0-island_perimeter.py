#!/usr/bin/python3
"""_summary_
"""


def island_perimeter(grid):
    """_summary_

    Args:
        grid (_type_): _description_
    """
    # initiate perimeter
    perimeter = 0
    # iterate through the grid
    for i in range(len(grid)):
        for j in range(len(grid[i])):
            # check if the cell is land or water
            # if water, skip to the next cell
            if grid[i][j] == 0:
                continue
            # if cell is land
            if grid[i][j] == 1:
                # for each border next to water, add 1 to the perimeter
                # check if cell is not in the first or last row
                if i != 0 and i != len(grid) - 1:
                    if grid[i - 1][j] == 0:
                        perimeter += 1
                    if grid[i + 1][j] == 0:
                        perimeter += 1
                if j != 0 and j != len(grid[i]) - 1:
                    if grid[i][j - 1] == 0:
                        perimeter += 1
                    if grid[i][j + 1] == 0:
                        perimeter += 1
                # if in the first or last row, add one to the perimeter
                if i == 0:
                    perimeter += 1
                if i == len(grid) - 1:
                    perimeter += 1
                # if in the first or last column, add one to the perimeter
                if j == 0 :
                    perimeter += 1
                if j == len(grid[i]) - 1:
                    perimeter += 1
    return perimeter
