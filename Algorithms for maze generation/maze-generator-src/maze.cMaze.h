#include "maze.common.h"
#include "maze.cAlgorithmDFS.h"
#include "maze.cAlgorithmPrim.h"
#include "maze.cAlgorithmKruskal.h"
#include "maze.cAlgorithmSubdivision.h"
#include "maze.cAlgorithmBinary.h"

using namespace std;

#ifndef MAZE_H
#define MAZE_H

class cMaze {
    private:
        size_t        height;
        size_t        width;
        size_t        x;
        size_t        y;

    public:
        grid          maze;
        cAlgorithm*   algorithms[5];
        cMaze         ();
        cMaze         (size_t width, size_t height);
        ~cMaze        ();

        size_t getHeight  () {return height;};
        size_t getWidth   () {return width;};

        ERR_ENUM init     ();
        ERR_ENUM clear    ();
        ERR_ENUM create   (size_t width, size_t height);
        ERR_ENUM generate (ALGORITHMS_ENUM algorithm);
        ERR_ENUM solve    (size_t startX, size_t startY, size_t finishX, size_t finishY, bool visual);
        ERR_ENUM render   ();
};
#endif
