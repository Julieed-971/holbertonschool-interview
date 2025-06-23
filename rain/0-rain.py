#!/usr/bin/python3
"""Module that calculates how many squares of water
will be retained after it rains"""


def rain(walls):
    """Calculates how many squares of water
    will be retained after it rains"""
    rain = 0
    n = len(walls)

    # Initialize empty array of n size
    left_max_height = [0] * n
    right_max_height = [0] * n

    # Return 0 if list is empty
    if len(walls) == 0:
        return 0

    # Initialize left max height to wall height at index 0
    left_max_height[0] = walls[0]

    # Calculate the left max height for each element starting from index 1
    for i in range(1, n):
        left_max_height[i] = max(left_max_height[i - 1], walls[i])

    # Initialize right max height to wall height at the end of the list
    right_max_height[n - 1] = walls[n - 1]

    #  Calculate the right max height for each element starting at index - 2
    for i in range(n - 2, 0, -1):
        right_max_height[i] = max(right_max_height[i + 1], walls[i])

    # Find the minimum fillable rain value
    # between left and right height of each element
    for i in range(1, n - 1):
        min_to_fill = min(left_max_height[i], right_max_height[i])

        # The rain value is the minimum fillable value
        # minus the height of the element itself
        rain += min_to_fill - walls[i]
    return rain
