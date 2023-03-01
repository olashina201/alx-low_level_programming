#include <stdio.h>

/**
 * print_buffer - Print a buffer 10 bytes at a time,
 * displaying the line in hex and byte pairs
 * @b: String to print from
 * @size: Size of buffer
 * Return: Nothing
 */

void print_buffer(char *b, int size)
{
	int i, counter = 0, size2 = size;
	char *ptr = b;

	if (size == 0)
		printf("\n");
	while (size > 0)
	{
		printf("%08x:", counter);
		i = 0;
		while (size > 0 && i < 10)
		{
			if (!(i % 2))
				printf(" ");
			printf("%02x", *ptr++);
			i++;
			size--;
			counter++;
		}
		while (counter % 10 != 0)
		{
			if (!(counter % 2))
				printf(" ");
			printf("  ");
			counter++;
		}
		printf(" ");
		i = 0;
		while (size2 > 0 && i < 10)
		{
			if (*b > 31 && *b != 127)
				printf("%c", *b);
			else
				printf(".");
			size2--;
			i++;
			b++;
		}
		printf("\n");
	}
}
