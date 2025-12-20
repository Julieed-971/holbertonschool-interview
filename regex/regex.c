#include <stdio.h>
#include <string.h>
#include "regex.h"

/**
 * regex_recursion - recursively check if a string matches a given pattern
 * @str: pointer to the string to scan
 * @pattern: pointer to the regular expression
 * @n: size of the string
 * @m: size ot the pattern
 * Return: 1 if it matches, 0 if it doesn't
 */
int regex_recursion(char const *str, char const *pattern, int n, int m)
{
	if (str[n] == '\0' && pattern[m] == '\0')
	{
		return (1);
	}
	if (str[n] != '\0' && pattern[m] == '\0')
	{
		return (0);
	}
	if (str[n] == '\0' && pattern[m] != '\0' && pattern[m + 1] == '*')
	{
		return (regex_recursion(str, pattern, n, m + 2));
	}
	if (pattern[m] != '\0' && pattern[m + 1] != '*')
	{
		if (str[n] == pattern[m] || pattern[m] == '.')
		{
			return (regex_recursion(str, pattern, n + 1, m + 1));
		}
	}
	if (pattern[m] != '\0' && pattern[m + 1] == '*')
	{
		if (str[n] == pattern[m] || pattern[m] == '.')
		{
			return (regex_recursion(str, pattern, n + 1, m) ||
					regex_recursion(str, pattern, n, m + 2));
		}
		if (str[n] != pattern[m])
		{
			return (regex_recursion(str, pattern, n, m + 2));
		}
	}
	return (0);
}


/**
 * regex_match - check wether a given pattern matches a given string
 * @str: pointer to the string to scan
 * @pattern: pointer to the regular expression
 * Return: 1 if it matches, 0 if it doesn't
 */
int regex_match(char const *str, char const *pattern)
{
	int n = 0;
	int m = 0;

	return (regex_recursion(str, pattern, n, m));
}
