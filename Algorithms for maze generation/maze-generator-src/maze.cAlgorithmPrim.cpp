#include "maze.cAlgorithmPrim.h"

ERR_ENUM cAlgorithmPrim::generate() {
    if (height<=1 || width<=1 || maze==0) return FAILURE;

    curCell = new cellPos;

    for (curCell->x=1; curCell->x<width; curCell->x++) {
        for (curCell->y=1; curCell->y<height; curCell->y++) {
            sOut.insert(*curCell);
        }
    }

    setRandomPos(sOut,pos);
    *curCell=*pos;
    sIn.insert(*pos);
    sOut.erase(pos);

    if (curCell->x < width-1) {
        curCell->x++; sOut.erase(*curCell); sFront.insert(*curCell); curCell->x--;
    }
    if (curCell->x > 1) {
        curCell->x--; sOut.erase(*curCell); sFront.insert(*curCell); curCell->x++;
    }
    if (curCell->y < height-1) {
        curCell->y++; sOut.erase(*curCell); sFront.insert(*curCell); curCell->y--;
    }
    if (curCell->y > 1) {
        curCell->y--; sOut.erase(*curCell); sFront.insert(*curCell); curCell->y++;
    }

    while (sFront.size()>0) {
        setRandomPos(sFront,pos);
        *curCell=*pos;
        sIn.insert(*pos);
        sFront.erase(pos);

        if (curCell->x < width-1) {
            curCell->x++;
            if (sOut.erase(*curCell)!=0) sFront.insert(*curCell);
            curCell->x--;
        }
        if (curCell->x > 1) {
            curCell->x--;
            if (sOut.erase(*curCell)!=0) sFront.insert(*curCell);
            curCell->x++;
        }
        if (curCell->y < height-1) {
            curCell->y++;
            if (sOut.erase(*curCell)!=0) sFront.insert(*curCell);
            curCell->y--;
        }
        if (curCell->y > 1) {
            curCell->y--;
            if (sOut.erase(*curCell)!=0) sFront.insert(*curCell);
            curCell->y++;
        }

        bool neighbours[4];
        if (curCell->x < width-1) {
            curCell->x++;
            if (sIn.find(*curCell)==sIn.end()) {
                neighbours[0]=false;
            } else {
                neighbours[0]=true;
            }
            curCell->x--;
        } else neighbours[0]=false;
        if (curCell->y < height-1) {
            curCell->y++;
            if (sIn.find(*curCell)==sIn.end()) {
                neighbours[1]=false;
            } else {
                neighbours[1]=true;
            }
            curCell->y--;
        } else neighbours[1]=false;
        if (curCell->x > 1) {
            curCell->x--;
            if (sIn.find(*curCell)==sIn.end()) {
                neighbours[2]=false;
            } else {
                neighbours[2]=true;
            }
            curCell->x++;
        } else neighbours[2]=false;
        if (curCell->y > 1) {
            curCell->y--;
            if (sIn.find(*curCell)==sIn.end()) {
                neighbours[3]=false;
            } else {
                neighbours[3]=true;
            }
            curCell->y++;
        } else neighbours[3]=false;
        if (neighbours[0] || neighbours[1] || neighbours[2] || neighbours[3]) {
            size_t rand = (int)(getRnd() * 4);
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
                (*maze)[curCell->x][curCell->y].crushWall(EAST);
                (*maze)[curCell->x+1][curCell->y].crushWall(WEST);
            } else if (rand==1) {
                (*maze)[curCell->x][curCell->y].crushWall(SOUTH);
                (*maze)[curCell->x][curCell->y+1].crushWall(NORTH);
            } else if (rand==2) {
                (*maze)[curCell->x][curCell->y].crushWall(WEST);
                (*maze)[curCell->x-1][curCell->y].crushWall(EAST);
            } else if (rand==3) {
                (*maze)[curCell->x][curCell->y].crushWall(NORTH);
                (*maze)[curCell->x][curCell->y-1].crushWall(SOUTH);
            }
        }
    }

    delete curCell;
    sIn.clear();
    sOut.clear();
    sFront.clear();
    return SUCCESS;
}

inline void cAlgorithmPrim::setRandomPos(set<cellPos>& cont, set<cellPos>::iterator& iter) {
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
