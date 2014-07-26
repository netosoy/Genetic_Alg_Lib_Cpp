#ifndef DEFS_H
#define DEFS_H

#include <iostream>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

enum SIDES_ENUM {
    EAST       = 0x01,
    SOUTH      = 0x02,
    WEST       = 0x04,
    NORTH      = 0x08,
    ALL_SIDES  = 0x0F
};

enum ERR_ENUM {
    FAILURE  = 0,
    SUCCESS  = 1
};

void seedRNG();
double getRnd();

#endif
