#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics
"""
import re
import sys


def print_stats():
    print(f"File size: {total_size}")
    for key, value in status_code.items():
        if value > 0:
            print(f"{key}: {value}")


if __name__ == "__main__":
    # Start line counter
    line_number = 0

    # status code list
    status_code = {
        200: 0,
        301: 0,
        400: 0,
        401: 0,
        403: 0,
        404: 0,
        405: 0,
        500: 0
        }

    # Initiate file size sum - for each correctly formatted line,
    #  add file size to total_size
    total_size = 0

    try:
        for line in sys.stdin:
            line_number += 1

            # Check input line format with regex
            pattern = r'.*?(\d+) (\d+)$'
            match = re.search(pattern, line)
            if match:
                line_status_code = int(match.group(1))
                line_size = int(match.group(2))
                # If status code exist in status_code keys,
                # increment status_code corresponding key
                if line_status_code in status_code:
                    status_code[line_status_code] += 1
                total_size += line_size

            # If Ctrl + c is pressed or if line_number % 10 == 0
            # print the total file size and number of line by
            # status code in ascending order
            if line_number % 10 == 0:
                print_stats()
    except KeyboardInterrupt:
        pass
    finally:
        print_stats()
