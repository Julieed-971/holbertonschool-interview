#include <stdio.h>
#include "holberton.h"

/**
 * wildcmpRecursion - recursively compares two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string to compare
 * @n: size of the first string
 * @m: size of the second string
 * Return: 1 if identical else 0
 */

int wildcmpRecursion(char *s1, char *s2, int n, int m)
{
	/* Check for end of both strings */
	if (s1[n] == '\0' && s2[m] == '\0')
	{
		return (1);
	}
	/* Empty text can match with a pattern consisting of '*' only. */
	if (s1[n] == '\0')
	{
		if (s2[m] == '*')
		{
			return (wildcmpRecursion(s1, s2, n, m + 1));
		}
		return (0);
	}
    /* Pattern is empty but text is not */
	if (s2[m] == '\0')
	{
		return (0);
	}
	/* If pattern has '*', try matching zero or more characters */
	if (s2[m] == '*')
	{
		return (wildcmpRecursion(s1, s2, n, m + 1) ||
				wildcmpRecursion(s1, s2, n + 1, m));
	}
	/* If characters match, move both indices forward */
	if (s1[n] == s2[m])
	{
		return (wildcmpRecursion(s1, s2, n + 1, m + 1));
	}
	return (0);
}

/**
 * wildcmp - compares two strings
 * @s1: pointer to the first string
 * @s2: pointer to the second string to compare
 * Return: 1 if identical else 0
 */

int wildcmp(char *s1, char *s2)
{
	int n = 0;
	int m = 0;

	return (wildcmpRecursion(s1, s2, n, m));
}
