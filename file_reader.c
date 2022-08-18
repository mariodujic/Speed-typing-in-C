#include <stdio.h>
#include "definitions.h"

int numberOfLinesInFile() {
    FILE *file = fopen(FILE_NAME, "r");
    int ch, number_of_lines = 0;
    do {
        ch = fgetc(file);
        if (ch == '\n')
            number_of_lines++;
    } while (ch != EOF);
    if (ch != '\n' && number_of_lines != 0)
        number_of_lines++;
    fclose(file);
    return number_of_lines;
}