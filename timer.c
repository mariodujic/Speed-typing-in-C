#include <time.h>

const int maxRunTime = 10;

int runEnd(time_t startTime) {
    time_t currentTime = time(0);
    int timePassed = currentTime - startTime;
    return maxRunTime < timePassed;
}