#include "maze.common.hh"

using namespace std;

#ifndef ALGORITHM_H
#define ALGORITHM_H

class cAlgorithm {
    protected:
        size_t  height;
        size_t  width;

    public:
        grid*   maze;

        cAlgorithm                 ();
        cAlgorithm                 (grid* srcMaze,size_t width,size_t height);
        virtual ~cAlgorithm        () {};

        ERR_ENUM hookMaze          (grid* srcMaze,size_t width,size_t height);
        virtual ERR_ENUM generate  () = 0;
};
#endif
