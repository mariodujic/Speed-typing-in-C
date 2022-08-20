#include <time.h>
#include <malloc.h>
#include <stdio.h>
#include "dictionary.h"
#include "file_reader.h"
#include "timer.h"
#include "display.h"

int main() {
    time_t t;
    srand((unsigned) time(&t));

    int dictionarySize = numberOfLinesInFile();
    char **dictionary = malloc(dictionarySize * sizeof(char *));
    writeDictionary(dictionary);

    char **words = malloc(wordsSize * sizeof(char *));
    writeDisplay(words, dictionary, dictionarySize);

    char input[100];
    time_t startTime = time(0);
    while (runEnd(startTime) == 0) {
        for (int i = 0; i < wordsSize; i++) {
            printf("%s", words[i]);
        }
        fgets(input, 100, stdin);
    }

    freeDisplay(words);
    freeDictionary(dictionary, dictionarySize);
    return 0;
}