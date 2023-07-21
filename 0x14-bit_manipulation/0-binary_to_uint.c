#include "main.h"
#include <string.h>

/**
 * binary_to_uint - convert binary number to unsigned int
 * @b: the binary number as a cstring
 * Description:
 * NOTE: the limit of @b length is the maximum positive signed int
 * otherwise returns zero
 *
 * Only 0s and 1s chars allowed any other chars returns zero
 *
 * Return: the decimal form of the converted number otherwise zero
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int i, num = 0, field;

	if (!b)
		return (num);

	for (i = strlen(b) - 1, field = 1; (signed int)i >= 0; i--, field *= 2)
		if (b[i] == '1')
			num += field;
		else if (b[i] == '0')
			continue;
		else
			return (0);
	return (num);
}

