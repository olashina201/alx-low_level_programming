#include <stdio.h>
#include "function_pointers.h"

/**
 * array_iterator - perform a function on the whole array
 * @array: array to act on
 * @size: size of array
 * @action: function to execute on array
 * Return: nothing
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (action != NULL && array != NULL)
		for (i = 0; i < size; i++)
			action(array[i]);
}
