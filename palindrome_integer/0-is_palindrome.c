#include <stdio.h>

/**
 * get_n_length - returns the length of an unsigne long integer
 * @n: unsigned long n
 * Return: length of n
 */
int get_n_length(unsigned long n)
{
	int n_size = 1;
	unsigned long n_copy = n;

	while (n_copy > 9)
	{
		n_size++;
		n_copy /= 10;
	}
	return (n_size);
}

/**
 * is_palindrome - checks whether or not a given unsigned integer
 * is a palindrome.
 * @n: unsigned long n
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */

int is_palindrome(unsigned long n)
{
	int n_len = 0;

	n_len = get_n_length(n);

	if (n_len == 1)
	{
		return (1);
	}
	/* Declare  and initialize an array of n_len size */
	int n_list[n_len];
	int n_len_copy = n_len;
	/* Use modulo 10 to copy each digit of n in an array */
	while (n_len_copy > 0)
	{
		n_list[n_len_copy - 1] = n % 10;
		n /= 10;
		n_len_copy--;
	}
	/* loop through array by both start and end and check if values are equal */
	int start = 0;
	int end = n_len - 1;
	int is_palindrome = 1;

	for (int i = 0; i < n_len; i++)
	{
		if (n_list[start] != n_list[end])
		{
			is_palindrome = 0;
			return (is_palindrome);
		}
		start++;
		end--;
	}
	return (is_palindrome);
}
