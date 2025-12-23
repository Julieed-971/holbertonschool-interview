#!/usr/bin/python3
"""
    Determines who wins the Prime Game
"""


def isWinner(x, nums):
    """
    Determines who the winner is between Maria (odd turns)
    and Ben (even turns) when playing
    Prime game, taking turns picking a prime number
    and removing its multiples until
    one cannot make a move

    Args:
        x (int): number of rounds
        nums (list): array of n

    Return:
        str or None: Name of the player that won the most rounds or None
    """

    # Return None if the number of round is zero or if nums is empty
    if x == 0 or len(nums) == 0:
        return None

    maria_wins = 0
    ben_wins = 0
    rounds_to_play = min(x, len(nums))
    # Loop through the number of rounds
    for i in range(0, rounds_to_play):
        # For one turn, how many primes and their multiples
        #  can be picked and/or removed
        prime_count = count_primes_sieve(nums[i])
        if prime_count % 2 != 0:
            maria_wins += 1
        else:
            ben_wins += 1
    if maria_wins > ben_wins:
        return "Maria"
    if maria_wins < ben_wins:
        return "Ben"
    return None


def count_primes_sieve(n):
    """Count how many primes exist up to n using Sieve"""
    if n < 2:
        return 0

    # Step 1: Create list - all True initially (assuming all prime)
    is_prime = [True for i in range(n + 1)]

    # Step 2: Mark 0 and 1 as not prime
    is_prime[0] = False
    is_prime[1] = False

    # Step 3: Loop through numbers - mark multiples as False
    for p in range(2, int(n**0.5) + 1):
        if is_prime[p]:
            for multiple in range(p * p, n + 1, p):
                is_prime[multiple] = False

    # Step 4: Count how many True values remain
    return sum(is_prime)
