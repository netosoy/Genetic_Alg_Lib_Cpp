#include "maze.cAlgorithmKruskal.h"

ERR_ENUM cAlgorithmKruskal::generate() {
    if (height<=1 || width<=1 || maze==0) return FAILURE;

    wall curWall;
    int count = 0;

    walls.clear();

    for (size_t i=1; i<width-1; i++) {
        for (size_t j=1; j<height-1; j++) {
            curWall.x=i;
            curWall.y=j;
            curWall.dir=VERTICAL;
            walls.push_back(curWall);
            curWall.dir=HORIZONTAL;
            walls.push_back(curWall);
            count++;
        }
    }
    curWall.x=width-1;
    for (size_t j=1; j<height-1; j++) {
        curWall.y=j;
        curWall.dir=HORIZONTAL;
        walls.push_back(curWall);
        count++;
    }
    curWall.y=height-1;
    for (size_t i=1; i<width-1; i++) {
        curWall.x=i;
        curWall.dir=VERTICAL;
        walls.push_back(curWall);
        count++;
    }

    while (count>0) {
        setRandomPos(walls,iter);
        curWall = *iter;
        if (iter->dir==VERTICAL) {
            if (family.findSet(&((*maze)[iter->x][iter->y])) != family.findSet(&((*maze)[iter->x+1][iter->y]))) {
                family.unionSet(&((*maze)[iter->x][iter->y]),&((*maze)[iter->x+1][iter->y]));
                (*maze)[iter->x][iter->y].crushWall(EAST);
                (*maze)[iter->x+1][iter->y].crushWall(WEST);
                count--;
            }
        } else {
            if (family.findSet(&((*maze)[iter->x][iter->y])) != family.findSet(&((*maze)[iter->x][iter->y+1]))) {
                family.unionSet(&((*maze)[iter->x][iter->y]),&((*maze)[iter->x][iter->y+1]));
                (*maze)[iter->x][iter->y].crushWall(SOUTH);
                (*maze)[iter->x][iter->y+1].crushWall(NORTH);
                count--;
            }
        }
        walls.erase(iter);
    }

    return SUCCESS;
}


inline void cAlgorithmKruskal::setRandomPos(list<wall>& cont, list<wall>::iterator& iter) {
    size_t rand;
    if (getRnd()>0.5) {
        iter = cont.begin();
        rand = (int)(getRnd() * cont.size());
        rand >>= 1;
        for (size_t i=1; i<rand; i++) iter++;
    } else {
        iter = cont.end();
        iter--;
        rand = (int)(getRnd() * cont.size());
        rand >>= 1;
        for (size_t i=1; i<rand; i++) iter--;
    }
}
