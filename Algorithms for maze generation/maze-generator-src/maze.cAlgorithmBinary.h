#include "maze.cAlgorithm.h"

using namespace std;

#ifndef ALGORITHM_BIN_H
#define ALGORITHM_BIN_H

class cAlgorithmBinary : public cAlgorithm {
    public:
        cAlgorithmBinary  (){};
        cAlgorithmBinary  (grid* srcMaze);
        ~cAlgorithmBinary (){};

        ERR_ENUM generate ();
};
#endif

