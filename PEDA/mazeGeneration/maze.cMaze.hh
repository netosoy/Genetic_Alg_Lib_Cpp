#include "maze.common.hh"
#include "maze.cAlgorithmDFS.hh"
//#include "maze.cAlgorithmPrim.h"
//#include "maze.cAlgorithmKruskal.h"
//#include "maze.cAlgorithmSubdivision.h"
//#include "maze.cAlgorithmBinary.h"

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
        grid          maze;				//matriz de celdas (cCell's)
        //cAlgorithm*   algorithms[5];	//arreglo de tipos de algorithmos
        cAlgorithm* algorithms[1];//<-------------|*
        cMaze         ();
        cMaze         (size_t width, size_t height);	//llama a métodos "init" y "create" para inicializar variable y asignar memoria
        ~cMaze        ();

        size_t getHeight  () {return height;};
        size_t getWidth   () {return width;};

        ERR_ENUM init     ();	//inicializa miembros, 
        ERR_ENUM clear    ();	//libera memoria de matriz de celdas (cCell's)
        ERR_ENUM create   (size_t width, size_t height);	//asigna memoria a matriz de celdas y crea el algoritmo DFS
        //ERR_ENUM generate (ALGORITHMS_ENUM algorithm);
        ERR_ENUM generate ();//<-------------|*
        ERR_ENUM solve    (size_t startX, size_t startY, size_t finishX, size_t finishY, bool visual);
        ERR_ENUM render   ();
};
#endif
