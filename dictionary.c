#include <stdio.h>
#include <string.h>
#include <malloc.h>
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
            token = strtok(line, search) + 1;
            char *word = token + 2;
            word[strlen(word)-1] = '\0';
            length = strlen(word);
            dictionary[index] = malloc((length + 1) * sizeof(char));
            strcpy(dictionary[index], word);
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