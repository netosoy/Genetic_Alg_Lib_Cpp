#include "helper.common.h"

using namespace std;

#ifndef RECT_H
#define RECT_H

class cRect {
    public:
        int top;
        int left;
        int right;
        int bottom;

        cRect  ()                                         {};
        cRect  (cRect& rect);
        cRect  (int top, int left, int right, int bottom);
        ~cRect ()                                         {};

        inline void create(int top, int left, int right, int bottom);
        inline int height()                               {return bottom-top;};
        inline int width()                                {return right-left;};
};
#endif
