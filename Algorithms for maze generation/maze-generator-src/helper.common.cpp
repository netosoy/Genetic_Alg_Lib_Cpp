#include "helper.common.h"
#include <ctime>

double getRnd() {
    return ((double)rand()) / RAND_MAX;
}

void seedRNG() {
    srand((unsigned int)time(0));
}
