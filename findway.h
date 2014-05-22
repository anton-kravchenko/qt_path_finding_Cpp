
#ifndef FINDPATH_H_
#define FINDPATH_H_
#include "widget.h"
struct Point
{
    int x;
    int y;
};

class FindWay {
public:

    int length;
    int** grid;
    Point* way[];

    int dx[4];
    int dy[4];
    int dir[4];

    FindWay();
    bool find_path(Widget**,int,int);
    void setWeight(Widget**,int, bool&, int&);
};

#endif /* FINDPATH_H_ */
