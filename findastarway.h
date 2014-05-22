#ifndef FINDASTARWAY_H
#define FINDASTARWAY_H
#include "widget.h"
#include "surface_states.h"
#include "item.h"
using namespace std;
class FindAStarWay
{
    vector<Item*> *openList;
    vector<Item*> *closedList;
    vector<Item*> *fullList;

    int calcF(Item*);
    int manhattanWayLength(Item *);
    int calcG(Item*, Item*);

    Item* findMin();

    void addNeighbours(Widget**, Item *);
    void removeElement(vector<Item *> *, Item*);
    bool findAt(vector<Item*>, Item*);


    int dir[9];
    int start;
    int finish;
public:
    void reconstructWay(Widget**);

    FindAStarWay();
    void findAStarWay(Widget**,int, int);
};

#endif // FINDASTARWAY_H
