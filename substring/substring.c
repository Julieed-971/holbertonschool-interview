#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "substring.h"

/**
 * initialize_is_visited - reset an array of boolean values to false
 * @is_visited: the array to reset
 * @nb_words: the number of elements in the array
 *
 */
void initialize_is_visited(bool *is_visited, int nb_words)
{
	/** Initialize is_visited array with false*/
	for (int h = 0; h < nb_words; h++)
	{
		is_visited[h] = false;
	}
}

/**
 * copy_substring_element - create a copy of a substring element
 * @s: string to copy substring element from
 * @i: index where to start copy
 * @word_len: length of the substring element to copy
 * @substring_element: the substring_element array to
 * populate with copied values
 */
void copy_substring_element(char const *s, int i, int word_len,
							 char *substring_element)
{
	for (int j = 0; j <= word_len - 1; j++)
	{
		substring_element[j] = s[i];
		i++;
	}
	substring_element[word_len] = '\0';
}

/**
 * find_word_index - retrieve the index of a found word in an array of words
 * @chunk: chunk of char to find in the words array
 * @words: array of words to scan
 * @nb_words: number of words in the array
 * @is_visited: check for already visited words indices
 * Return: the index of the word found or -1 if no correspondance found
 */
int find_word_index(char *chunk, char const **words,
					int nb_words, bool *is_visited)
{
	for (int m = 0; m < nb_words; m++)
	{
		if (!is_visited[m] && strcmp(chunk, words[m]) == 0)
		{
			return (m);
		}
	}
	return (-1);
}

/**
 * check_sequence - check if a valid substring starts at start_index
 * @s: string to check
 * @start_index: index from which to check a potential sequence
 * @words: array of potentiel concatenated word to find in sequence
 * @nb_words: number of words in the array
 * @word_len: length of word in words
 * Return: true if there is a valid sequence, false otherwise
 */
bool check_sequence(char const *s, int start_index,
					char const **words, int nb_words, int word_len)
{
	bool is_visited[nb_words];
	int current_scan_index = start_index;
	char substring_element[word_len + 1];

	initialize_is_visited(is_visited, nb_words);
	for (int k = 0; k < nb_words; k++)
	{
		copy_substring_element(s, current_scan_index,
													word_len, substring_element);
		int match_index = -1;

		match_index = find_word_index(substring_element, words,
									  nb_words, is_visited);
		if (match_index == -1)
		{
			return (false);
		}
		is_visited[match_index] = true;
		current_scan_index += word_len;
	}
	return (true);
}

/**
 * find_substring - find  and return indices of all the possible substrings
 * containing a list of words withing a given string
 * @s: pointer to the string in which to find substrings
 * @words: array of words all substrings must be a concatenation arrangement of
 * @nb_words: number of elements in the array words
 * @n: holds the address at which to store the
 * number of elements in the returned array.
 * Return: the array of indices of substrings
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int string_len, word_len, substring_indices_capacity = 10;
	int current_result_count = 0;
	int *substring_indices = NULL;

	if (s == NULL || words == NULL)
	{
		return (NULL);
	}
	string_len = strlen(s);
	word_len = strlen(words[0]);
	substring_indices = (int *)malloc(substring_indices_capacity * sizeof(int));
	bool is_visited[nb_words];

	initialize_is_visited(is_visited, nb_words);

	for (int s_index_start = 0; s_index_start <= string_len - (
		word_len * nb_words); s_index_start++)
	{
		if (check_sequence(s, s_index_start, words, nb_words, word_len))
		{
			/* store index value */
			if (current_result_count >= substring_indices_capacity)
			{
				substring_indices_capacity *= 2;
				substring_indices = (int *)realloc(substring_indices,
												   substring_indices_capacity * sizeof(int));
				if (substring_indices == NULL)
				{
					break;
				}
				substring_indices[current_result_count] = s_index_start;
				current_result_count++;
			}
			substring_indices[current_result_count] = s_index_start;
			current_result_count++;
		}
	}
	*n = current_result_count;
	return (substring_indices);
}
