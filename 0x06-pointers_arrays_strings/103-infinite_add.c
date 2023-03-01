#include "main.h"

/**
 * infinite_add - adds two numbers
 * @n1: first number to add
 * @n2: second number to add
 * @r: buffer to store the result
 * @size_r: size of the buffer
 *
 * Return: pointer to the result or 0 if buffer is too small
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int len1, len2, i, j, k, sum, carry = 0;

	for (len1 = 0; n1[len1]; len1++)
		;
	for (len2 = 0; n2[len2]; len2++)
		;
	if (len1 > size_r || len2 > size_r)
		return (0);
	for (i = len1 - 1, j = len2 - 1, k = size_r - 1; k >= 0 && (i >= 0 || j >= 0); i--, j--, k--)
	{
		sum = carry;
		if (i >= 0)
			sum += n1[i] - '0';
		if (j >= 0)
			sum += n2[j] - '0';
		carry = sum / 10;
		r[k] = (sum % 10) + '0';
	}
	if (carry)
	{
		if (size_r == len1 + len2 + 1)
			return (0);
		r[0] = carry + '0';
		return (r);
	}
	if (size_r == len1 + len2)
		return (0);
	return (&r[k + 1]);
}
