#include "helper.common.hh"

using namespace std;

#ifndef CELL_H
#define CELL_H

class cCell {
    private:
        int     data; //0xTW000000
    public:
        cCell*  parent;

        inline  cCell  ()                             {data = ALL_SIDES; parent = this;};
        inline  cCell  (const int src)                {data = src; parent = this;};
        inline  cCell  (const cCell& src)             {data = src.data; parent = src.parent;};
        inline  ~cCell ()                             {};

        inline ERR_ENUM   buildWall(SIDES_ENUM side)  {data |= side; return SUCCESS;};	//poner un 1, en el lado indicado
        inline ERR_ENUM   crushWall(SIDES_ENUM side)  {data &= ~side; return SUCCESS;};	//poner un 0, en el lado indicado
        inline bool       getWall(SIDES_ENUM side)    {return ((data & side)==side);};	//true si existe pared en el lado indicado

        inline ERR_ENUM   walkTrack()                 {data |= 0x10; return SUCCESS;};
        inline ERR_ENUM   backTrack()                 {data |= 0x20; return SUCCESS;};
        inline int        getTrack()                  {return (data>>4);};
};
#endif
