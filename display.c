#include <string.h>
#include <malloc.h>
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

void freeDisplay(char **words) {
    for (int i = 0; i < wordsSize; i++) {
        free(&words[i]);
    }
    free(words);
}