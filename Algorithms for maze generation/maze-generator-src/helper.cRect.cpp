#include "helper.cRect.h"

cRect::cRect(int top,int left, int right, int bottom) {
    create(top,left,right,bottom);
}

cRect::cRect(cRect& rect) {
    top=rect.top;
    left=rect.left;
    right=rect.right;
    bottom=rect.bottom;
}

inline void cRect::create(int top,int left, int right, int bottom) {
    this->top=top;
    this->left=left;
    this->right=right;
    this->bottom=bottom;
}
