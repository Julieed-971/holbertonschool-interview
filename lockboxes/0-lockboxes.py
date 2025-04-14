#!/usr/bin/python3
"""
This module contains a function `canUnlockAll` that determines if all the boxes
in a list of lists can be opened. Each box may contain keys to other boxes, and
the goal is to check if all boxes can be unlocked starting from the first box.
"""

def canUnlockAll(boxes):
    """Determines if all the boxes of a list of list can be open"""
    # Initialize a variable to track if all boxes can be opened
    all_boxes_can_be_opened = True

    # outer loop
    for i in range(len(boxes) - 1):
        if i + 1 not in boxes[i]:
            return False
    return True