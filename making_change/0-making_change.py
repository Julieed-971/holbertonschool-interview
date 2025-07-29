#!/usr/bin/python3
"""Module to determine the fewest number of coins
to meet a given amount total"""


def makeChange(coins, total):
    """Determine the fewest number of coins
    needed to meet a given amount total"""
    change = []

    if total <= 0:
        return 0

    coins = sorted(coins, reverse=True)

    for i in range(len(coins)):
        if total / coins[i] >= 1:
            change.append(round(total / coins[i]))
            total = total - (change[i] * coins[i])
        elif total / coins[i] < 1:
            i += 1

    if total != 0:
        return -1

    return sum(change)
