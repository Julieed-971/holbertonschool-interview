#!/usr/bin/python3
"""Module to determine the fewest number of coins
to meet a given amount total"""


def makeChange(coins, total):
    """Determine the fewest number of coins
    needed to meet a given amount total"""

    if total <= 0:
        return 0
    # Initialize a dp array to length of amount + 1 (going from 0 to total)
    # with default value for all element to amount + 1 = max value
    dp = [total + 1] * (total + 1)
    dp[0] = 0

    # Iterate through all possible amount from 1 to total
    for amount in range(1, total + 1):
        # For each amount, iterate through each
        # possible coin for possible solution
        for coin in coins:
            # Check if coin is not greater than current amount
            if amount - coin >= 0:
                # Setting to the minimum of itself and
                # 1 (current coin) and dp[amount - coin]
                # e.g if coin = 4 & amount = 7
                # -> dp[7] = 1 (current coin) + dp[7 - 4]
                # <=> dp[7] = 1 + dp[3]
                # (which is already computed and
                # we choose the minimum solution)
                dp[amount] = min(dp[amount], 1 + dp[amount - coin])
    # Check if the value for total is different
    # from the default value
    if dp[total] != total + 1:
        return dp[total]
    return -1
