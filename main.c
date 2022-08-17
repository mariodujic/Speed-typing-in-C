#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <malloc.h>
#include <time.h>

#define FILE_NAME "dictionary.txt"

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

void removeChar(char *str, char garbage) {
    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++) {
        *dst = *src;
        if (*dst != garbage) dst++;
    }
    *dst = '\0';
}

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

void freeArray(char **dictionary, int size) {
    for (int i = 0; i < size; i++) {
        free(&dictionary[i]);
    }
    free(dictionary);
}

int randomNumber(int maxRange) {
    return rand() % maxRange;
}

int main() {
    time_t t;
    srand((unsigned) time(&t));

    int numberOfWords = numberOfLinesInFile();
    char **dictionary = malloc(numberOfWords * sizeof(char *));
    writeDictionary(dictionary);

    const int displaySize = 5;
    for (int i = 0; i < displaySize; i++) {
        int index = randomNumber(numberOfWords);
        printf("%s", dictionary[index]);
    }
    freeArray(dictionary, numberOfWords);
    return 0;
}