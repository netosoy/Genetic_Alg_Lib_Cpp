#include "maze.cAlgorithm.hh"

using namespace std;

#ifndef ALGORITHM_DFS_H
#define ALGORITHM_DFS_H

class cAlgorithmDFS : public cAlgorithm {
    private:
        cellPos curCell;
        stack<cellPos> cellStack;

    public:
        cAlgorithmDFS  ()                {};
        cAlgorithmDFS  (grid* srcMaze);
        ~cAlgorithmDFS ()                {};

        ERR_ENUM generate();
};
#endif

