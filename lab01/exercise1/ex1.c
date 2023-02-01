#include <string.h>
#include "ex1.h"

/* Returns the number of times LETTER appears in STR.
There are two different ways to iterate through a string.
1st way hint: strlen() may be useful
2nd way hint: all strings end in a null terminator */
int num_occurrences(char *str, char letter) {
    int count = 0;
    while (*str) {
        if (*str++ == letter) {
            count += 1;
        }
    }
    return count;
}

/* Populates DNA_SEQ with the number of times each nucleotide appears.
Each sequence will end with a NULL terminator and will have up to 20 nucleotides.
All letters will be upper case. */
void compute_nucleotide_occurrences(DNA_sequence *dna_seq) {
    char *p = dna_seq->sequence;
    dna_seq->A_count =
    dna_seq->C_count =
    dna_seq->G_count =
    dna_seq->T_count = 0;
    while (*p) {
        switch (*p++) {
        case 'A':
            dna_seq->A_count += 1;
            break;
        case 'C':
            dna_seq->C_count += 1;
            break;
        case 'G':
            dna_seq->G_count += 1;
            break;
        case 'T':
            dna_seq->T_count += 1;
            break;
        }
    }
}
