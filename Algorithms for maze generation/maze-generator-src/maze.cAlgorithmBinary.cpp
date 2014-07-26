#include "maze.cAlgorithmBinary.h"

ERR_ENUM cAlgorithmBinary::generate() {
    if (height<=1 || width<=1 || maze==0) return FAILURE;

    for (size_t i=1; i<width-1; i++) {
        for (size_t j=1; j<height-1; j++) {
            if (getRnd()>0.5) {
                (*maze)[i][j].crushWall(EAST);
                (*maze)[i+1][j].crushWall(WEST);
            } else {
                (*maze)[i][j].crushWall(SOUTH);
                (*maze)[i][j+1].crushWall(NORTH);
            }
        }
    }

    for (size_t i=1; i<width; i++) {
        (*maze)[i][height-1].crushWall(EAST);
        (*maze)[i][height-1].crushWall(WEST);
    }
    for (size_t i=1; i<height; i++) {
        (*maze)[width-1][i].crushWall(SOUTH);
        (*maze)[width-1][i].crushWall(NORTH);
    }

    (*maze)[width-1][1].buildWall(NORTH);
    (*maze)[1][height-1].buildWall(WEST);
    (*maze)[width-1][height-1].buildWall(EAST);
    (*maze)[width-1][height-1].buildWall(SOUTH);

    return SUCCESS;
}
