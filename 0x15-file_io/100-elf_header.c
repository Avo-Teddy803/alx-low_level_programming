#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <elf.h>

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
    char *input_file = argv[1];
    char *output_file = argv[2];

    FILE *in_fp = fopen(input_file, "rb");
    if (in_fp == NULL) {
        fprintf(stderr, "Error opening input file\n");
        return 1;
    }

    fseek(in_fp, 0, SEEK_END);
    size_t size = ftell(in_fp);
    rewind(in_fp);

    char *buffer = malloc(size);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        return 1;
    }

    if (fread(buffer, 1, size, in_fp) != size) {
        fprintf(stderr, "Error reading input file\n");
        return 1;
    }

    fclose(in_fp);

    Elf64_Ehdr *ehdr = (Elf64_Ehdr *)buffer;
    Elf64_Shdr *shdr = (Elf64_Shdr *)(buffer + ehdr->e_shoff);

    int i;
    for (i = 0; i < ehdr->e_shnum; i++) {
        if (shdr[i].sh_type == SHT_SYMTAB || shdr[i].sh_type == SHT_DYNSYM) {
            Elf64_Sym *symtab = (Elf64_Sym *)(buffer + shdr[i].sh_offset);
            char *strtab = buffer + shdr[shdr[i].sh_link].sh_offset;

            int j;
            for (j = 0; j < shdr[i].sh_size / sizeof(Elf64_Sym); j++) {
                if (ELF64_ST_TYPE(symtab[j].st_info) == STT_FUNC) {
                    printf("%s\n", strtab + symtab[j].st_name);
                }
            }
        }
    }

    FILE *out_fp = fopen(output_file, "wb");
    if (out_fp == NULL) {
        fprintf(stderr, "Error opening output file\n");
        return 1;
    }

    if (fwrite(buffer, 1, size, out_fp) != size) {
        fprintf(stderr, "Error writing output file\n");
        return 1;
    }

    fclose(out_fp);
    free(buffer);

    return 0;
}
