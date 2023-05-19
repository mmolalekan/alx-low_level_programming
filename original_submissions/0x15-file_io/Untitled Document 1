#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf_print_magic(unsigned char *e_ident);
void print_class_data(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_elf_type_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf_file(int elf);

/**
 * check_elf_print_magic - check if file is an ELF header file
 *
 * @e_ident: pointer to indent
 */

void check_elf_print_magic(unsigned char *e_ident)
{
int n = 0;

while (n < 4)
{
if (e_ident[n] != 127 &&
e_ident[n] != 'E' &&
e_ident[n] != 'L' &&
e_ident[n] != 'F')
{
dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
exit(98);
}
n++;
}
printf("ELF Header:\n");
n = 0;

printf("  Magic:   ");

while (n < EI_NIDENT)
{
printf("%02x", e_ident[n]);

if (n == EI_NIDENT - 1)
printf("\n");
else
printf(" ");
n++;
}
}

/**
 * print_class_data - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_class_data(unsigned char *e_ident)
{
printf("  Class:                             ");
switch (e_ident[EI_CLASS])
{
case ELFCLASSNONE:
printf("none\n");
break;
case ELFCLASS32:
printf("ELF32\n");
break;
case ELFCLASS64:
printf("ELF64\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
printf("  Data:                              ");
switch (e_ident[EI_DATA])
{
case ELFDATANONE:
printf("none\n");
break;
case ELFDATA2LSB:
printf("2's complement, little endian\n");
break;
case ELFDATA2MSB:
printf("2's complement, big endian\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_CLASS]);
}
printf("  Version:                           %d", e_ident[EI_VERSION]);
switch (e_ident[EI_VERSION])
{
case EV_CURRENT:
printf(" (current)\n");
break;
default:
printf("\n");
break;
}
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
printf("  OS/ABI:                            ");
switch (e_ident[EI_OSABI])
{
case ELFOSABI_NONE:
printf("UNIX - System V\n");
break;
case ELFOSABI_HPUX:
printf("UNIX - HP-UX\n");
break;
case ELFOSABI_NETBSD:
printf("UNIX - NetBSD\n");
break;
case ELFOSABI_LINUX:
printf("UNIX - Linux\n");
break;
case ELFOSABI_SOLARIS:
printf("UNIX - Solaris\n");
break;
case ELFOSABI_IRIX:
printf("UNIX - IRIX\n");
break;
case ELFOSABI_FREEBSD:
printf("UNIX - FreeBSD\n");
break;
case ELFOSABI_TRU64:
printf("UNIX - TRU64\n");
break;
case ELFOSABI_ARM:
printf("ARM\n");
break;
case ELFOSABI_STANDALONE:
printf("Standalone App\n");
break;
default:
printf("<unknown: %x>\n", e_ident[EI_OSABI]);
}
}

/**
 * print_elf_type_entry - Print the entry point address and type of elf
 *
 * @e_entry: entry descriptor
 * @e_ident: entry indent
 */

void print_elf_type_entry(unsigned long int e_entry, unsigned char *e_ident)
{
printf("  Entry point address:               ");

if (e_ident[EI_DATA] == ELFDATA2MSB)
{
e_entry = ((e_entry << 8) & 0xFF00FF00) |
((e_entry >> 8) & 0xFF00FF);
e_entry = (e_entry << 16) | (e_entry >> 16);
}

if (e_ident[EI_CLASS] == ELFCLASS32)
printf("%#x\n", (unsigned int)e_entry);

else
printf("%#lx\n", e_entry);
}

/**
 * close_elf_file - close Elf header file
 *
 * @fd: file descriptor
 */

void close_elf_file(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(98);
}
}

/**
 * main - read Elf header file
 *
 * @argc: argument count
 * @argv: argument vectors
 * Return: int
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
Elf64_Ehdr *header;
int fd, read_bytes;

fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
header = malloc(sizeof(Elf64_Ehdr));
if (header == NULL)
{
close_elf_file(fd);
dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
exit(98);
}
read_bytes = read(fd, header, sizeof(Elf64_Ehdr));
if (read_bytes == -1)
{
free(header);
close_elf_file(fd);
dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
exit(98);
}

check_elf_print_magic(header->e_ident);
print_class_data(header->e_ident);
print_osabi(header->e_ident);
printf("  ABI Version:                       %d\n", header->e_ident[EI_ABIVERSION]);
if (header->e_ident[EI_DATA] == ELFDATA2MSB)
header->e_type >>= 8;

printf("  Type:                              ");

switch (header->e_type)
{
case ET_NONE:
printf("NONE (None)\n");
break;
case ET_REL:
printf("REL (Relocatable file)\n");
break;
case ET_EXEC:
printf("EXEC (Executable file)\n");
break;
case ET_DYN:
printf("DYN (Shared object file)\n");
break;
case ET_CORE:
printf("CORE (Core file)\n");
break;
default:
printf("<unknown: %x>\n", header->e_type);
}
print_elf_type_entry(header->e_entry, header->e_ident);

free(header);
close_elf_file(fd);
return (0);
}
