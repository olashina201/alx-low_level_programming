#include <stddef.h>

/**
 * flip_bits - count the number of bits needed to change to match @n and @m
 * @n: the first number
 * @m: the second number
 *
 * Return: the number of changes needed to match @m and @m
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int counter = 0;
	size_t bits = sizeof(n) * 8;

	for (; bits > 0; bits--)
		if ((n >> bits & 0x01) != (m >> bits & 0x01))
			counter++;
	return (counter);
}

