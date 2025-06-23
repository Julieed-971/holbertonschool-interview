#!/usr/bin/python3
"""Module to determines if a given data
set represents a valid UTF-8 encoding"""


def validUTF8(data):
    # bytes to process counter
    n_bytes = 0
    for num in data:
        # Get the binary string representation (8 least significant
        # bits) of each integer
        binary_num = format(num, '#010b')[-8:]
        # Check if beginning of a process
        if n_bytes == 0:
            # Get number of 1 at the beginning of the string
            for bit in binary_num:
                if bit == '0':
                    break
                n_bytes += 1
            # Pass to next for 1 byte char
            if n_bytes == 0:
                continue
            # Check if the char starts with 1
            # and is 1 byte or if char is more than 4 bytes
            if n_bytes == 1 or n_bytes > 4:
                return False
        # Check if the next n - 1 bytes char are a valid pattern 10xxxxxx
        else:
            if not (binary_num[0] == '1' and binary_num[1] == '0'):
                return False
        # Reducing the number of bytes processed
        n_bytes -= 1
    # False if data is missing for a given UTF8 char
    return n_bytes == 0
