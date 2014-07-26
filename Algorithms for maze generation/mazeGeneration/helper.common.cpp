#include "helper.common.hh"
#include <ctime>

double getRnd() {
    return ((double)rand()) / RAND_MAX;
}

void seedRNG() {
    srand((unsigned int)time(0));
}
