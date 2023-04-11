#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
        exit(97);
    }

    char *file_from = argv[1];
    char *file_to = argv[2];

    FILE *fp_from = fopen(file_from, "r");
    if (!fp_from) {
        dprintf(2, "Error: Can't read from file %s\n", file_from);
        exit(98);
    }

    FILE *fp_to = fopen(file_to, "w");
    if (!fp_to) {
        dprintf(2, "Error: Can't write to %s\n", file_to);
        exit(99);
    }

    char buffer[BUFFER_SIZE];
    size_t nread;
    while ((nread = fread(buffer, 1, BUFFER_SIZE, fp_from)) > 0) {
        size_t nwritten = fwrite(buffer, 1, nread, fp_to);
        if (nwritten != nread) {
            dprintf(2, "Error: Can't write to %s\n", file_to);
            exit(99);
        }
    }

    if (fclose(fp_from) != 0) {
        dprintf(2, "Error: Can't close fd %d\n", fileno(fp_from));
        exit(100);
    }

    if (fclose(fp_to) != 0) {
        dprintf(2, "Error: Can't close fd %d\n", fileno(fp_to));
        exit(100);
    }

    return 0;
}

