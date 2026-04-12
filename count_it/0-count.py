#!/usr/bin/python3
"""Program which recursively call RedditAPI hot articles endpoint,
   parses the titles and print a sorted count of given keywords
   as command line argument
"""
import requests


def count_words(subreddit, word_list):
    """
    Function which recursively call RedditAPI hot articles endpoint,
    parses the titles and print a sorted count of given keywords
    as command line argument
    """

    response = requests.get(``)