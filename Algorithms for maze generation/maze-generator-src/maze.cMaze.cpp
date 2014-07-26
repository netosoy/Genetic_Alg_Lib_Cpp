#include "maze.cMaze.h"

cMaze::cMaze() {
    init();
}

cMaze::cMaze(size_t width, size_t height) {
    init();
    create(width,height);
}

cMaze::~cMaze() {
    clear();
    for (int i=0; i<5; i++) {
      delete algorithms[i];
    }
}

ERR_ENUM cMaze::init() {
    height=0;
    width=0;
    maze=0;
    algorithms[0] = new cAlgorithmBinary;
    algorithms[1] = new cAlgorithmSubdivision;
    algorithms[2] = new cAlgorithmDFS;
    algorithms[3] = new cAlgorithmPrim;
    algorithms[4] = new cAlgorithmKruskal;
    return SUCCESS;
}

ERR_ENUM cMaze::clear() {
    if (width!=0 || height!=0) {
        for (size_t i=0; i<width; i++) {
            delete[] maze[i];
        }
        delete[] maze;
    }
    width=0;
    height=0;
    return SUCCESS;
}

ERR_ENUM cMaze::create(size_t width, size_t height) {
    if (width<=1 || height<=1) return FAILURE;

    if (clear()==SUCCESS) {
        this->width = width;
        this->height = height;
        maze = new cCell*[width];
        for (size_t i=0; i<width; i++) {
            maze[i]=new cCell[height];
        }
        for (size_t i=0; i<5; i++) {
            algorithms[i]->hookMaze(&maze,width,height);
        }
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

ERR_ENUM cMaze::generate(ALGORITHMS_ENUM algorithm) {
    x=99;
    y=99;
    if (algorithms[algorithm]->generate()==SUCCESS) {
        return SUCCESS;
    } else {
        return FAILURE;
    }
}

ERR_ENUM cMaze::solve(size_t startX, size_t startY, size_t finishX, size_t finishY, bool visual) {
    if (height<=1 || width<=1 || maze==0) return FAILURE;

    cellPos curCell;
    stack<cellPos> cellStack;

    curCell.x = startX;
    curCell.y = startY;

    while (curCell.x != finishX || curCell.y != finishY) {
        maze[curCell.x][curCell.y].walkTrack();

        int neighbours[4];
        if (curCell.x < width-1) {
            if (!maze[curCell.x][curCell.y].getWall(EAST)) {
                neighbours[0] = maze[curCell.x+1][curCell.y].getTrack();
            } else neighbours[0]=4;
        } else neighbours[0]=4;
        if (curCell.y < height-1) {
            if (!maze[curCell.x][curCell.y].getWall(SOUTH)) {
                neighbours[1] = maze[curCell.x][curCell.y+1].getTrack();
            } else neighbours[1]=4;
        } else neighbours[1]=4;
        if (curCell.x > 1) {
            if (!maze[curCell.x][curCell.y].getWall(WEST)) {
                neighbours[2] = maze[curCell.x-1][curCell.y].getTrack();
            } else neighbours[2]=4;
        } else neighbours[2]=4;
        if (curCell.y > 1) {
            if (!maze[curCell.x][curCell.y].getWall(NORTH)) {
                neighbours[3] = maze[curCell.x][curCell.y-1].getTrack();
            } else neighbours[3]=4;
        } else neighbours[3]=4;

        //Order of preference - important.
        if (neighbours[0]==0) {
            curCell.x++;
        } else if (neighbours[1]==0) {
            cellStack.push(curCell);
            curCell.y++;
        } else if (neighbours[2]==0) {
            cellStack.push(curCell);
            curCell.x--;
        } else if (neighbours[3]==0) {
            cellStack.push(curCell);
            curCell.y--;
        } else if (neighbours[0]==1) {
            maze[curCell.x][curCell.y].backTrack();
            cellStack.push(curCell);
            curCell.x++;
        } else if (neighbours[1]==1) {
            maze[curCell.x][curCell.y].backTrack();
            cellStack.push(curCell);
            curCell.y++;
        } else if (neighbours[2]==1) {
            maze[curCell.x][curCell.y].backTrack();
            cellStack.push(curCell);
            curCell.x--;
        } else if (neighbours[3]==1) {
            maze[curCell.x][curCell.y].backTrack();
            cellStack.push(curCell);
            curCell.y--;
        } else {
            maze[curCell.x][curCell.y].backTrack();
            curCell = cellStack.top();
            cellStack.pop();
        }

        if (visual) {
          render();
          Sleep(350);
        }
    }

    maze[curCell.x][curCell.y].walkTrack();
    return SUCCESS;
}

ERR_ENUM cMaze::render() {
    int**     canvas;
    if (width<=1 || height<=1 || maze==0) return FAILURE;

    system("cls");

    canvas = new int*[width*2+1];
    for (size_t i=0; i<width*2+1; i++) {
        canvas[i]=new int[height*2+1];
        for (size_t j=0; j<height*2+1; j++) {
            canvas[i][j]=0;
        }
    }

    for (size_t i=1; i<height; i++) {
        for (size_t j=1; j<width; j++) {
            canvas[j*2][i*2] = maze[j][i].getTrack() + 10;
            if (j==x && i==y) {
                canvas[j*2][i*2] = 999;
            }

            if (maze[j][i].getWall(NORTH)) {
                canvas[j*2][i*2-1] = 1;
            }
            if (maze[j][i].getWall(WEST)) {
                canvas[j*2-1][i*2] = 1;
            }
            if (maze[j][i].getWall(SOUTH)) {
                canvas[j*2][i*2+1] = 1;
            }
            if (maze[j][i].getWall(EAST)) {
                canvas[j*2+1][i*2] = 1;
            }
            canvas[j*2-1][i*2-1] = 1;
            canvas[j*2+1][i*2+1] = 1;
            canvas[j*2-1][i*2+1] = 1;
            canvas[j*2+1][i*2-1] = 1;
        }
    }

    for (size_t i=0; i<height*2+1; i++) {
        for (size_t j=0; j<width*2+1; j++) {
            if (canvas[j][i]==1) {
                cout << nounitbuf << BLOCK;
                cout << nounitbuf << BLOCK;
            } else if (canvas[j][i]==11) {
                cout << nounitbuf << PATH;
                cout << nounitbuf << PATH;
            } else if (canvas[j][i]==999) {
                cout << nounitbuf << CURRENT;
                cout << nounitbuf << CURRENT;
            } else if (canvas[j][i]>=12) {
                cout << nounitbuf << BACKTRACK;
                cout << nounitbuf << BACKTRACK;
            } else {
                cout << nounitbuf << SPACE;
                cout << nounitbuf << SPACE;
            }
        }
        cout << nounitbuf << endl;
    }
    cout.flush();
    return SUCCESS;
}
