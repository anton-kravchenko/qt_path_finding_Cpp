#ifndef ITEM_H
#define ITEM_H
#include "surface_states.h"
#include <vector>
using namespace std;

enum belongTo{NONE = 0, OPEN_LIST = 1, CLOSED_LIST = 2};

class Item
{
public:
    Item();

    int F;
    int H;
    int G;

    int number;
    static int counter;

    Item* parent;
    belongTo belong;

};
struct comporatorH {
  bool operator() (Item* a, Item* b) { return (a->H < b->H);}
};
struct comporatorF {
    bool operator() (Item* a, Item* b) { return (a->F < b->F);}
};
//inline bool operator <(Item a, Item b)
//{
//    return a.G < b.G;
//}
#endif // ITEM_H
