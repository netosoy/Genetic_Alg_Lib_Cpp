#include "maze.cAlgorithm.h"
#include "helper.cRect.h"

using namespace std;

#ifndef ALGORITHM_SUBDIV_H
#define ALGORITHM_SUBDIV_H

class cAlgorithmSubdivision : public cAlgorithm {
    private:
        void subdivide(cRect& room);
        inline void crushTop(int x, int y, cRect& room, grid* maze);
        inline void crushBottom(int x, int y, cRect& room, grid* maze);
        inline void crushLeft(int x, int y, cRect& room, grid* maze);
        inline void crushRight(int x, int y, cRect& room, grid* maze);
        int q;

    public:
        cAlgorithmSubdivision  (){q=0;};
        cAlgorithmSubdivision  (grid* srcMaze);
        ~cAlgorithmSubdivision (){};

        ERR_ENUM generate();
};
#endif

