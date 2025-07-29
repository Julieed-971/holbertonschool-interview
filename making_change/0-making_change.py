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

    for coin in coins:
        if total >= coin:
            num = round(total / coin)
            change.append(num)
            total -= num * coin
        elif total / coin < 1:
            continue

    if total != 0:
        return -1

    return sum(change)
