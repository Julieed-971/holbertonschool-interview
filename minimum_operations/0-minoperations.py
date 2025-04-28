#!/usr/bin/python3
"""Module to calculate the fewest number of operations 
needed to result in exactly n H characters in the file"""

def minOperations(n):
    if n < 2:
            return 0
    else:
        i = 0
        for i in range(i, n):
            if i != 0 and n % i == 0:
                i += i
            else:
                i += 1
        return i