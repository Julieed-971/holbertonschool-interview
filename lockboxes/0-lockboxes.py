#!/usr/bin/python3
"""
This module contains a function `canUnlockAll` that determines if all the boxes
in a list of lists can be opened. Each box may contain keys to other boxes, and
the goal is to check if all boxes can be unlocked starting from the first box.
"""


def canUnlockAll(boxes):
    """Determines if all the boxes of a list of list can be open"""

    # List of keys to be found, excluding box 0 as it's already unlocked
    boxes_to_unlock = set(range(1, len(boxes)))

    # Found keys
    found_keys = set(boxes[0])

    # Iterate until no new keys are found
    new_keys_found = True

    while new_keys_found:

        new_keys_found = False
        # Iterate over keys found so far
        for key in list(found_keys):
            # Check if key corresponds to an unlocked box
            if key in boxes_to_unlock:
                # Unlock the box and add its keys
                found_keys.update(boxes[key])
                boxes_to_unlock.remove(key)
                new_keys_found = True

        # If no new keys are found, stop
        if not new_keys_found:
            break

    # Return True if all boxes are unlocked
    return len(boxes_to_unlock) == 0
