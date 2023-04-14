#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>

/**
 * print_error - Prints error message to stderr and exits with status code 98.
 * @msg: Error message to be printed.
 */
void print_error(const char *msg)
{
	fprintf(stderr, "Error: %s\n", msg);
	exit(98);
}

/**
 * main - Entry point of the program.
 * @argc: Number of command line arguments.
 * @argv: Array of command line arguments.
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	int fd, n;
	Elf64_Ehdr header;

	if (argc != 2)
		print_error("Usage: elf_header elf_filename");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Failed to open file");

	n = read(fd, &header, sizeof(header));
	if (n != sizeof(header))
		print_error("Failed to read ELF header");

	close(fd);

	/* Check if it's an ELF file */
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	    header.e_ident[EI_MAG1] != ELFMAG1 ||
	    header.e_ident[EI_MAG2] != ELFMAG2 ||
	    header.e_ident[EI_MAG3] != ELFMAG3)
		print_error("Not an ELF file");

	/* Print the information from the ELF header */
	printf("Magic: ");
	for (int i = 0; i < EI_NIDENT; i++)
		printf("%02x ", header.e_ident[i]);
	printf("\nClass: %d\n", header.e_ident[EI_CLASS]);
	printf("Data: %d\n", header.e_ident[EI_DATA]);
	printf("Version: %d\n", header.e_ident[EI_VERSION]);
	printf("OS/ABI: %d\n", header.e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
	printf("Type: %d\n", header.e_type);
	printf("Entry point address: %#lx\n", header.e_entry);
	printf("Format: %d\n", header.e_version);

	return 0;
}
