#include "maze.cAlgorithm.h"

cAlgorithm::cAlgorithm() {
    maze=0;
    height=0;
    width=0;
}

cAlgorithm::cAlgorithm(grid* srcMaze,size_t width,size_t height) {
    hookMaze(srcMaze,width,height);
}

ERR_ENUM cAlgorithm::hookMaze(grid* srcMaze,size_t width,size_t height) {
    this->maze=srcMaze;
    this->width=width;
    this->height=height;
    return SUCCESS;
}
