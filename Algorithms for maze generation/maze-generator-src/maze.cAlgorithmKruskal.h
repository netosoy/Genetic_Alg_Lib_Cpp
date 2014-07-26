#include "helper.cUnionFind.h"
#include "maze.cAlgorithm.h"
#include <list>

using namespace std;

#ifndef ALGORITHM_KRUS_H
#define ALGORITHM_KRUS_H

class cAlgorithmKruskal : public cAlgorithm {
    private:
        enum direction {
            HORIZONTAL,
            VERTICAL
        };

        class wall {
            public:
                size_t x;
                size_t y;
                direction dir;

                inline friend bool operator < (const wall& m1, const wall& m2) {
                    return (((m1.x*64) + m1.y)+m1.dir < ((m2.x*64) + m2.y)+m2.dir) ? true : false;
                }
        };
        inline void setRandomPos(list<wall>& cont, list<wall>::iterator& iter);

        cUnionFind             family;
        list<wall>             walls;
        list<wall>::iterator   iter;

    public:
        cAlgorithmKruskal  ()                {};
        cAlgorithmKruskal  (grid* srcMaze)   {};
        ~cAlgorithmKruskal ()                {};

        ERR_ENUM generate();
};
#endif
