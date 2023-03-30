#include <stdio.h>

/* Using constructors in C */

void main_constructor(void) __attribute__((constructor));

/**
 * main_constructor - constructor that prints a message
 * befor main runs
 * Return: Nothing
 */

void main_constructor(void)
{
	printf("You're beat! and yet, you must allow,\n");
	printf("I bore my house upon my back!\n");
}
