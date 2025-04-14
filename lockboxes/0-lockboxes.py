#!/usr/bin/python3

def canUnlockAll(boxes):
    """Determines if all the boxes of a list of list can be open"""
    # Initialize a variable to track if all boxes can be opened
    all_boxes_can_be_opened = True

    # outer loop
    for i in range(len(boxes) - 1):
        if i + 1 not in boxes[i]:
            return False
    return True