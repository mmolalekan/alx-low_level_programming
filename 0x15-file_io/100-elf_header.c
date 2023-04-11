#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void check_elf(unsigned char *e_ident);
void print_property(char *prop, unsigned char value);
void close_elf(int elf);

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	for (int i = 0; i < EI_NIDENT; i++)
		if (e_ident[i] != 127 && e_ident[i] != 'E' && e_ident[i] != 'L' && e_ident[i] != 'F')
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n"), exit(98);
}

/**
 * print_property - Prints a property of an ELF header.
 * @prop: A pointer to the property to be printed.
 * @value: The value of the property.
 */
void print_property(char *prop, unsigned char value)
{
	printf("%s: ", prop);
	if (value >= ELFOSABI_NONE && value <= ELFOSABI_STANDALONE) printf("%s\n", (char *[]){"UNIX - System V", "UNIX - HP-UX", "UNIX - NetBSD", "UNIX - Linux", "UNIX - Solaris", "UNIX - IRIX", "UNIX - FreeBSD", "UNIX - TRU64", "ARM", "Standalone App"}[value]);
	else if (value == EV_CURRENT) printf("%d (current)\n", value);
	else if (value >= ELFCLASSNONE && value <= ELFCLASS64) printf("%s\n", (char *[]){"none", "ELF32", "ELF64"}[value - ELFCLASSNONE]);
	else if (value >= ELFDATANONE && value <= ELFDATA2MSB) printf("%s\n", (char *[]){"none", "2's complement, little endian", "2's complement, big endian"}[value - ELFDATANONE]);
	else printf("<unknown: %x>\n", value);
}

int main(int argc, char *argv[])
{
	int fd, elf;
	ssize_t bytes_read;
	Elf64_Ehdr e_hdr;

	if (argc != 2)
		dprintf(STDERR_FILENO, "Usage: %s <elf_filename>\n", argv[0]), exit(98);

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		dprintf(STDERR_FILENO, "Error: Cannot open file %s\n", argv[1]), exit(98);

	bytes_read = read(fd, &e_hdr, sizeof(e_hdr));
	if (bytes_read == -1)
		dprintf(STDERR_FILENO, "Error: Cannot read from file %s\n", argv[1]), exit(98);

	check_elf(e_hdr.e_ident);
	print_property("Class", e_hdr.e_ident[EI_CLASS]);
	print_property("Data", e_hdr.e_ident[EI_DATA]);
	print_property("Version", e_hdr.e_ident[EI_VERSION]);
	print_property("OS/ABI", e_hdr.e_ident[EI_OSABI]);
	print_property("ABI Version", e_hdr.e_ident[EI_ABIVERSION]);
	/* print_property("Type", e_hdr.e_type); */
	
	return(0);
}

