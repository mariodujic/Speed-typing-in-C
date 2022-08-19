#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include "utils.h"
#include "definitions.h"

void writeDictionary(char **dictionary) {
    char *token;
    char *search = ":";
    FILE *file = fopen(FILE_NAME, "r");
    int length;
    if (file != NULL) {
        char line[1500];
        int index = 0;
        while (fgets(line, sizeof line, file) != NULL) {
            token = strtok(line, search);
            removeChar(token, '"');
            length = strlen(token);
            dictionary[index] = malloc((length + 1) * sizeof(char));
            strcpy(dictionary[index], token);
            index++;
        }
        fclose(file);
    }
}

void freeDictionary(char **dictionary, int size) {
    for (int i = 0; i < size; i++) {
        free(&dictionary[i]);
    }
    free(dictionary);
}