#ifndef SUBSTRING_H
#define SUBSTRING_H
#include <stdbool.h>

int *find_substring(char const *s, char const **words, int nb_words, int *n);
bool is_complete_substring(bool *is_visited, int word_list_length);
void copy_substring_element(char const *s, int i,
	int s_index_stop, char *substring_element);
int find_word_index(char *chunk, char const **words,
	int nb_words, bool *is_visited);
void initialize_is_visited(bool *is_visited, int nb_words);


#endif /* SUBSTRING_H */
