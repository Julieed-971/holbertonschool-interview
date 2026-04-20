#!/usr/bin/python3
"""
    Program which recursively call RedditAPI hot articles endpoint,
    parses the titles and print a sorted count of given keywords
    as command line argument
"""
import requests


def keyword_count(titles_list, keyword_multipliers, keyword_count_totals):
    """
            Recursively count keyword occurrences in subreddit titles

            Args:
                    titles_list (list): list of hot titles in the subreddit
                    arg parameter of count_words
                    keyword_list (list): list of keywords to count in titles
                    keyword_dict_counter:
    """
    if (len(keyword_multipliers) == 0):
        return
    else:
        for title in titles_list:
            for keyword in title:
                if keyword in list(keyword_multipliers.keys()):
                    keyword_count_totals[
                        keyword] += keyword_multipliers[keyword]
        return keyword_count_totals


def count_words(
    subreddit,
    word_list,
    current_after="",
    fetched_items=0,
    keyword_multipliers=None,
    keyword_count_totals=None
):
    """
    Function which recursively call RedditAPI hot articles endpoint,
    parses the titles and print a sorted count of given keywords
    as command line argument
    """
    base_url = f"https://www.reddit.com/r/{subreddit}/hot/.json"
    headers = {
        "User-Agent": "count_it_algorithm (by /u/Hungry-Escape-7340)",
    }
    params = {
        "limit": 100,
        "count": fetched_items,
        "after": current_after,
        "raw_json": 1
    }

    try:
        if keyword_multipliers is None:
            keyword_multipliers = {}
            keyword_list = [keyword.lower() for keyword in word_list]
            for key in keyword_list:
                keyword_multipliers[key] = keyword_list.count(key)
        if keyword_count_totals is None:
            keyword_count_totals = {}
            for key in list(keyword_multipliers.keys()):
                keyword_count_totals[key] = 0
        if (current_after is None):
            if keyword_count_totals is not None:
                for keyword, count in sorted(
                        keyword_count_totals.items(),
                        key=lambda item: item[1],
                        reverse=True
                ):
                    if count > 0:
                        print(f"{keyword}: {count}")
                    else:
                        pass
            return
        response = requests.get(
            base_url, headers=headers, params=params, allow_redirects=False)
        if (response.status_code == 200):
            data = response.json()
            next_after = data["data"]["after"]
            fetched_items += len(data["data"]["children"])
            titles_list = [post["data"]["title"].lower().split(" ")
                           for post in data["data"]["children"]]
            keyword_count_totals = keyword_count(
                titles_list, keyword_multipliers, keyword_count_totals)
            count_words(subreddit, word_list, next_after, fetched_items,
                        keyword_multipliers, keyword_count_totals)
        else:
            pass
    except Exception as e:
        print(f"An error occured: {e}")
