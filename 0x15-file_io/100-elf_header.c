#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_elf_header(Elf64_Ehdr *ehdr) {
    printf("ELF Header:\n");
    printf("  Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", ehdr->e_ident[i]);
    }
    printf("\n");
    printf("  Class:                             %s\n", (ehdr->e_ident[EI_CLASS] == ELFCLASS32) ? "ELF32" : "ELF64");
    printf("  Data:                              %s\n", (ehdr->e_ident[EI_DATA] == ELFDATA2MSB) ? "big endian" : "little endian");
    printf("  Version:                           %d%s\n", ehdr->e_ident[EI_VERSION], (ehdr->e_ident[EI_VERSION] == EV_CURRENT) ? " (current)" : "");
    printf("  OS/ABI:                            %s\n", (ehdr->e_ident[EI_OSABI] == ELFOSABI_SYSV) ? "UNIX - System V" : "UNKNOWN");
    printf("  ABI Version:                       %d\n", ehdr->e_ident[EI_ABIVERSION]);
    printf("  Type:                              ");
    switch (ehdr->e_type) {
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
            printf("<unknown: %x>\n", ehdr->e_type);
            break;
    }
    printf("  Entry point address:               0x%lx\n", ehdr->e_entry);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
        exit(98);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Error: Can't read from file %s\n", argv[1]);
        exit(98);
    }

    Elf64_Ehdr ehdr;
    if (read(fd, &ehdr, sizeof(Elf64_Ehdr)) != sizeof(Elf64_Ehdr)) {
        fprintf(stderr, "Error: Failed to read ELF header from %s\n", argv[1]);
        exit(98);
    }

    if (memcmp(ehdr.e_ident, ELFMAG, SELFMAG) != 0) {
        fprintf(stderr, "%s: Not an ELF file\n", argv[1]);
        exit(98);
    }

    print_elf_header(&ehdr);

    if (close(fd) == -1) {
        fprintf(stderr, "Error: Can't close fd %d\n", fd);
        exit(100);
    }

    return 0;
}

