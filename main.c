#include <time.h>
#include <malloc.h>
#include <stdio.h>
#include "dictionary.h"
#include "file_reader.h"
#include "utils.h"

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
    freeDictionary(dictionary, numberOfWords);
    return 0;
}