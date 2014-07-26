#include "helper.cCell.h"

using namespace std;

#ifndef UNION_H
#define UNION_H

class cUnionFind {
    private:
        inline void     linkSet(cCell* item1, cCell* item2)  {item1->parent = item2;}

    public:
        inline          cUnionFind()                         {}
        inline          ~cUnionFind()                        {}

        inline void     makeSet(cCell* item)                 {item->parent = item;}
        inline void     unionSet(cCell* item1, cCell* item2) {linkSet(findSet(item1),findSet(item2));}
        inline cCell*   findSet(cCell* item)                 {
            if (item == item->parent) {
                return item;
            } else {
                //item->parent = findSet(item->parent);
                //return item->parent;
                return findSet(item->parent);
            }
        }

};
#endif
