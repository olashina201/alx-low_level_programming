#include <stdlib.h>

/**
 * int_index - check an array for an integer that matches
 * the function defined by cmp
 * @array: array
 * @size: size of array
 * @cmp: comparison
 * Return: index of match, otherwise -1
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (cmp == NULL || array == NULL)
		return (-1);

	if (size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
		if (cmp(array[i]))
			return (i);

	if (i == size)
		return (-1);

	return (-1);
}
