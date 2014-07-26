#include "maze.cAlgorithmDFS.h"

ERR_ENUM cAlgorithmDFS::generate() {
    if (height<=1 || width<=1 || maze==0) return FAILURE;

    size_t totalCells = (width-1)*(height-1);
    size_t visitedCells = 1;

    curCell.x = 1 + (int)(getRnd() * (width-1));
    curCell.y = 1 + (int)(getRnd() * (height-1));

    while (visitedCells < totalCells) {
        bool neighbours[4];
        if (curCell.x < width-1) {
            if ((*maze)[curCell.x+1][curCell.y].getWall(ALL_SIDES)) {
                neighbours[0]=true;
            } else {
                neighbours[0]=false;
            }
        } else neighbours[0]=false;
        if (curCell.y < height-1) {
            if ((*maze)[curCell.x][curCell.y+1].getWall(ALL_SIDES)) {
                neighbours[1]=true;
            } else {
                neighbours[1]=false;
            }
        } else neighbours[1]=false;
        if (curCell.x > 1) {
            if ((*maze)[curCell.x-1][curCell.y].getWall(ALL_SIDES)) {
                neighbours[2]=true;
            } else {
                neighbours[2]=false;
            }
        } else neighbours[2]=false;
        if (curCell.y > 1) {
            if ((*maze)[curCell.x][curCell.y-1].getWall(ALL_SIDES)) {
                neighbours[3]=true;
            } else {
                neighbours[3]=false;
            }
        } else neighbours[3]=false;
        if (neighbours[0] || neighbours[1] || neighbours[2] || neighbours[3]) {
            int rand = (int)(getRnd() * 4);
            if (!neighbours[rand]) {
                if (neighbours[(rand + 1) % 4]) {
                    rand = (rand + 1) % 4;
                } else if (neighbours[(rand + 2) % 4]) {
                    rand = (rand + 2) % 4;
                } else if (neighbours[(rand + 3) % 4]) {
                    rand = (rand + 3) % 4;
                }
            }
            if (rand==0) {
                (*maze)[curCell.x][curCell.y].crushWall(EAST);
                (*maze)[curCell.x+1][curCell.y].crushWall(WEST);
                cellStack.push(curCell);
                curCell.x++;
            } else if (rand==1) {
                (*maze)[curCell.x][curCell.y].crushWall(SOUTH);
                (*maze)[curCell.x][curCell.y+1].crushWall(NORTH);
                cellStack.push(curCell);
                curCell.y++;
            } else if (rand==2) {
                (*maze)[curCell.x][curCell.y].crushWall(WEST);
                (*maze)[curCell.x-1][curCell.y].crushWall(EAST);
                cellStack.push(curCell);
                curCell.x--;
            } else if (rand==3) {
                (*maze)[curCell.x][curCell.y].crushWall(NORTH);
                (*maze)[curCell.x][curCell.y-1].crushWall(SOUTH);
                cellStack.push(curCell);
                curCell.y--;
            }
            visitedCells++;
        } else {
            curCell = cellStack.top();
            cellStack.pop();
        }
    }
    return SUCCESS;
}
