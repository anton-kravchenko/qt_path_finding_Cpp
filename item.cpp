#include "item.h"

Item::Item()
{
    number = counter++;
    belong = NONE;
}
inline bool operator <(Item&, Item&);
int Item::counter = 0;

