#include <stdio.h>
#include <stdlib.h>

/**
 * print_opcodes - prints the opcodes of the main function
 * @n: number of bytes to print
 */
void print_opcodes(int n)
{
        unsigned char *main_opcodes = (unsigned char *)main;
        int i;

        for (i = 0; i < n; i++) {
                printf("%02x ", main_opcodes[i]);
        }
        printf("\n");
}

/**
 * main - prints its own opcodes
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 1 if the number of arguments is incorrect, 2 if the
 * number of bytes is negative
 */
int main(int argc, char **argv)
{
        int n;

        if (argc != 2) {
                printf("Error\n");
                return (1);
        }

        n = atoi(argv[1]);

        if (n < 0) {
                printf("Error\n");
                return (2);
        }

        print_opcodes(n);

        return (0);
}
