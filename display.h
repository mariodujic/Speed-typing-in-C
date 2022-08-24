#ifndef DISPLAY
#define DISPLAY

const int wordsSize;

void writeDisplay(char **words, char **dictionary, int dictionarySize);

int containsWord(char **words, char *input);

void freeDisplay(char **words);

#endif // DISPLAY