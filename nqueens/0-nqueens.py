#!/usr/bin/python3

import sys

if not len(sys.argv) == 2:
    print("Usage: nqueens N")
    sys.exit(1)

try:
    if isinstance(int(sys.argv[1]), int):
        n = int(sys.argv[1])
        if n < 4:
            print("N must be at least 4")
            sys.exit(1)
except(ValueError):
    print("N must be a number")
    sys.exit(1)
