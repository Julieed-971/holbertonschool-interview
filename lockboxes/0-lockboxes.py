#!/usr/bin/python3
"""
This module contains a function `canUnlockAll` that determines if all the boxes
in a list of lists can be opened. Each box may contain keys to other boxes, and
the goal is to check if all boxes can be unlocked starting from the first box.
"""

def canUnlockAll(boxes):
    """Determines if all the boxes of a list of list can be open"""
    
    # list of keys to be found, excluding box 0 as it's already unlocked
    locked_boxes = [i for i in range(1, len(boxes))]

    # set a boolean to check if all the boxes are opened
    all_boxes_are_opened = True
    
    # iterate over the boxes
    for i in range(len(boxes) - 1):
        
        # iterate over box's list
        for key in boxes[i]:
            
            # check for the keys inside the box
            if key in locked_boxes:
                # if found remove from the list of boxes keys
                locked_boxes.remove(key)

    # check if unlock boxes remains
    if len(locked_boxes) != 0:
        all_boxes_are_opened = False
    
    return all_boxes_are_opened
