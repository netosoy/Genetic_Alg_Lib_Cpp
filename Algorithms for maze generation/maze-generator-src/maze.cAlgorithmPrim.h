#include <set>
#include "maze.cAlgorithm.h"

using namespace std;

#ifndef ALGORITHM_PRIM_H
#define ALGORITHM_PRIM_H

class cAlgorithmPrim : public cAlgorithm {
    private:
        cellPos* curCell;
        inline void setRandomPos(set<cellPos>& cont, set<cellPos>::iterator& iter);

        set<cellPos> sIn;
        set<cellPos> sFront;
        set<cellPos> sOut;
        set<cellPos>::iterator pos;

    public:
        cAlgorithmPrim  ()                {};
        cAlgorithmPrim  (grid* srcMaze);
        ~cAlgorithmPrim ()                {};

        ERR_ENUM generate();
};
#endif

