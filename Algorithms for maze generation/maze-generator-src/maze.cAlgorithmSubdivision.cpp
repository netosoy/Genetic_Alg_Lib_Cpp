#include "maze.cAlgorithmSubdivision.h"

ERR_ENUM cAlgorithmSubdivision::generate() {
    if (height<=1 || width<=1 || maze==0) return FAILURE;

    for (size_t i=0; i<width; i++) {
        for (size_t j=0; j<height; j++) {
            (*maze)[i][j].crushWall(ALL_SIDES);
        }
    }

    cRect room(0,0,width-1,height-1);
    subdivide(room);

    for (size_t i=0; i<width; i++) {
        (*maze)[i][1].buildWall(NORTH);
        (*maze)[i][height-1].buildWall(SOUTH);
    }
    for (size_t i=0; i<height; i++) {
        (*maze)[1][i].buildWall(WEST);
        (*maze)[width-1][i].buildWall(EAST);
    }

    return SUCCESS;
}

void cAlgorithmSubdivision::subdivide(cRect& room) {
    if (room.width()>1 && room.height()>1) {
        int randX = 1 + room.left + (long)(getRnd() * (room.width()-1));
        int randY = 1 + room.top + (long)(getRnd() * (room.height()-1));
        for (int i=room.top+1; i<=room.bottom; i++) {
            (*maze)[randX][i].buildWall(EAST);
            (*maze)[randX+1][i].buildWall(WEST);
        }
        for (int i=room.left+1; i<=room.right; i++) {
            (*maze)[i][randY].buildWall(SOUTH);
            (*maze)[i][randY+1].buildWall(NORTH);
        }

        int rand = 1 + (int)(getRnd() * 4);
        switch (rand) {
        case 1:
            crushTop(randX,randY,room,maze);
            crushBottom(randX,randY,room,maze);
            crushRight(randX,randY,room,maze);
            break;
        case 2:
            crushTop(randX,randY,room,maze);
            crushLeft(randX,randY,room,maze);
            crushRight(randX,randY,room,maze);
            break;
        case 3:
            crushTop(randX,randY,room,maze);
            crushBottom(randX,randY,room,maze);
            crushLeft(randX,randY,room,maze);
            break;
        case 4:
            crushLeft(randX,randY,room,maze);
            crushBottom(randX,randY,room,maze);
            crushRight(randX,randY,room,maze);
            break;
        }

        int top = room.top;
        int left = room.left;
        int right = room.right;
        int bottom = room.bottom;

        room.create(top,left,randX,randY);
        subdivide(room);

        room.create(top,randX,right,randY);
        subdivide(room);

        room.create(randY,left,randX,bottom);
        subdivide(room);

        room.create(randY,randX,right,bottom);
        subdivide(room);
    }
}

inline void cAlgorithmSubdivision::crushTop(int x, int y, cRect& room, grid* maze) {
    int rand = 1 + room.top + (int)(getRnd() * (y - room.top - 1));
    (*maze)[x][rand].crushWall(EAST);
    (*maze)[x+1][rand].crushWall(WEST);
}

inline void cAlgorithmSubdivision::crushBottom(int x, int y, cRect& room, grid* maze) {
    int rand = 1 + y + (int)(getRnd() * (room.bottom - y - 1));
    (*maze)[x][rand].crushWall(EAST);
    (*maze)[x+1][rand].crushWall(WEST);
}

inline void cAlgorithmSubdivision::crushLeft(int x, int y, cRect& room, grid* maze) {
    int rand = 1 + room.left + (int)(getRnd() * (x - room.left - 1));
    (*maze)[rand][y].crushWall(SOUTH);
    (*maze)[rand][y+1].crushWall(NORTH);
}

inline void cAlgorithmSubdivision::crushRight(int x, int y, cRect& room, grid* maze) {
    int rand = 1 + x + (int)(getRnd() * (room.right - x - 1));
    (*maze)[rand][y].crushWall(SOUTH);
    (*maze)[rand][y+1].crushWall(NORTH);
}
