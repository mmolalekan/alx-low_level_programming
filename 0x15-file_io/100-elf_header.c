#include "main.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int fd, i;
	Elf32_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: header elf_filename\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(98);
	}
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		perror("read");
		close(fd);
		exit(98);
	}
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
	header.e_ident[EI_MAG1] != ELFMAG1 ||
	header.e_ident[EI_MAG2] != ELFMAG2 ||
	header.e_ident[EI_MAG3] != ELFMAG3)
	{
		fprintf(stderr, "%s is not an ELF file\n", argv[1]);
		close(fd);
		return (98);
	}
	printf("Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x ", header.e_ident[i]);
	}
	printf("\nClass: %s\n", header.e_ident[EI_CLASS] == ELFCLASS32 ?
	"ELF32" : "ELF64");
	printf("Data: %s\n", header.e_ident[EI_DATA] == ELFDATA2LSB ?
	"2's complement, little endian" : "2's complement, big endian");
	printf("Version: %d\n", header.e_ident[EI_VERSION]);
	printf("OS/ABI: %d\n", header.e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", header.e_ident[EI_ABIVERSION]);
	printf("Type: %d\n", header.e_type);
	printf("Entry point address: %x\n", header.e_entry);
	close(fd);
	return (0);
}
