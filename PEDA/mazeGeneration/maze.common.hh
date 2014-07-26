#include "helper.common.hh"
#include "helper.cCell.hh"
#include <stack>

#ifndef MAZEDEFS_H
#define MAZEDEFS_H

class cellPos {
    public:
        size_t x;
        size_t y;

        inline friend bool operator < (const cellPos& m1, const cellPos& m2) {
            return (((m1.x*64) + m1.y) < ((m2.x*64) + m2.y)) ? true : false;
        }
};

enum ALGORITHMS_ENUM {
    ALG_BINARY              = 0,
    ALG_SUBDIVISION         = 1,
    ALG_DEPTH_FIRST_SEARCH  = 2,
    ALG_PRIM                = 3,
    ALG_KRUSKAL             = 4
};

typedef cCell** grid;		//puntero para recorrer celdas de la rejilla

//Console Consts
const unsigned char BLOCK            = 178;
const unsigned char SPACE            = ' ';
const unsigned char PATH             = 'O';
const unsigned char BACKTRACK        = '~';
const unsigned char CURRENT          = '*';

const size_t MIN_WIDTH      = 3;
const size_t MAX_WIDTH      = 22;
const size_t MIN_HEIGHT     = 3;
const size_t MAX_HEIGHT     = 10;

#endif
