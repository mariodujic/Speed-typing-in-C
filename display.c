#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include "utils.h"

const int wordsSize = 3;
char *word;

void writeDisplay(char **words, char **dictionary, int dictionarySize) {
    for (int i = 0; i < wordsSize; i++) {
        int index = randomNumber(dictionarySize);
        word = dictionary[index];
        words[i] = malloc(strlen(word) * sizeof(char));
        strcpy(words[i], word);
    }
}

int processAnswer(char **dictionary, int dictionarySize, char **words, char *input) {
    input[strlen(input) - 1] = '\0';
    int contains = 0;
    for (int i = 0; i < wordsSize; i++) {
        char *w = words[i];
        if (strcmp(w, input) == 0) {
            int index = randomNumber(dictionarySize);
            char *newWord = dictionary[index];
            strcpy(words[i], newWord);
            contains = 1;
        }
    }
    return contains;
}

void freeDisplay(char **words) {
    for (int i = 0; i < wordsSize; i++) {
        free(&words[i]);
    }
    free(words);
}