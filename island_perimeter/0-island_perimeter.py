#!/usr/bin/python3
"""
This module contains a function called `island_parameter` that calculate 
the perimeter of an "island" represented by a grid, a list of list of integer
0 representing water and 1 representing land
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
                perimeter += 4
                # for each surrounding cell of land, remove 1 to the perimeter
                if i > 0:
                    if grid[i - 1][j] == 1:
                        perimeter -= 1
                if j > 0:
                    if grid[i][j - 1] == 1:
                        perimeter -= 1
                if i < len(grid) - 1:
                    if grid[i + 1][j] == 1:
                        perimeter -= 1
                if j < len(grid[i]) - 1:
                    if grid[i][j + 1] == 1:
                        perimeter -= 1                    
    return perimeter
