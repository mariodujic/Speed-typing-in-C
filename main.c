#include <time.h>
#include <malloc.h>
#include <stdio.h>
#include "dictionary.h"
#include "file_reader.h"
#include "utils.h"
#include "timer.h"

int main() {
    time_t t;
    srand((unsigned) time(&t));

    int numberOfWords = numberOfLinesInFile();
    char **dictionary = malloc(numberOfWords * sizeof(char *));
    writeDictionary(dictionary);

    char input[100];
    time_t startTime = time(0);
    while (runEnd(startTime) == 0) {
        int index = randomNumber(numberOfWords);
        printf("%s\n", dictionary[index]);
        fgets(input, 100, stdin);
    }

    freeDictionary(dictionary, numberOfWords);
    return 0;
}