#include <stdio.h>
#include "function_pointers.h"

/**
 * print_name - function that prints a name
 * @name: name to print
 * @f: function to use
 * Return: Nothing
 */

void print_name(char *name, void (*f)(char *name))
{
	if (f != NULL && name != NULL)
		(*f)(name);
}
