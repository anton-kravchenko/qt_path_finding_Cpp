#include "findastarway.h"

FindAStarWay::FindAStarWay()
{
    openList = new vector<Item*>;
    openList->reserve(WIDTH * HEIGHT * 10);

    closedList = new vector<Item*>;
    closedList->reserve(WIDTH * HEIGHT * 10);

    fullList = new vector<Item*>;
    fullList->reserve(WIDTH * HEIGHT);
    for(int i = 0; i < WIDTH*HEIGHT; i++)
        fullList->push_back(new Item);

    dir[7] = -WIDTH -1; //up->left
    dir[0] = -WIDTH;    //up
    dir[1] = -WIDTH + 1;//up->right

    dir[3] = WIDTH + 1; //down->right
    dir[4] = WIDTH;     //down
    dir[5] = WIDTH-1;   //down->left

    dir[2] = 1;         //right
    dir[6] = -1;        //left

    dir[8] = -WIDTH; // need ic cicle to add diagonal tiles
}


int FindAStarWay::calcF(Item *a)
{
    return a->G + a->H;
}

int FindAStarWay::manhattanWayLength(Item* a)
{
    int heigth = (a->number / WIDTH) - (finish / WIDTH);
    int width = (a->number % WIDTH) - (finish % WIDTH);

    if (heigth < 0)
        heigth*= -1;
    if( width < 0)
        width*= -1;

    return 10* (heigth + width);
}

int FindAStarWay::calcG(Item *item, Item *parent)
{
    int d = item->number - parent->number;
    if(d < 0) d*=-1;
    switch(d)
    {

    case WIDTH:                                 //UP DOWN
    case 1: return orthogonalTile + parent->G; //RIGHT LEFT

                                                    //add G of parent to calculate full weigth of point

    case WIDTH-1:                                   //DIAGONAL DOWN LEFT-RIGHT
    case WIDTH+1: return diagonalTile + parent->G;  //DIAGONAL DOWN RIGHT-LEFT
    }
}


Item* FindAStarWay::findMin()
{
//    Item* min = *(openList->begin());
//    for(vector<Item*>::iterator i = openList->begin()+1; i != openList->end(); i++ )
//    {
//        if(min->F > (*i)->F)
//            min = *i;
//    }
//    return min;

    comporatorF compF;

    sort(openList->begin(),openList->end(), compF);
    return *openList->begin();
}

void FindAStarWay::removeElement(vector<Item*> *v, Item* item)
{
    for(vector<Item*>::iterator i = openList->begin(); i != v->end(); i++)
        if(item == *i)
        {
            v->erase(i);
            return;
        }
}


void FindAStarWay::addNeighbours(Widget** grid, Item *parent)
{
    vector<Item*> v;
    int number = parent->number;
//up  //up->right   //right   //down->right   //down   //down->left   //left   //up->left
    for(int i = 0; i < 8; i++)
    {
        if(WALL != grid[number + dir[i]]->state)
        {
            if(CLOSED_LIST != fullList->at(i)->belong)
                if(1 == i%2)
                {
                    if((WALL != grid[number + dir[i-1]]->state) && (WALL != grid[number + dir[i+1]]->state))
                        v.push_back(fullList->at(number + dir[i]));
                }else v.push_back(fullList->at(number + dir[i]));;
        }
    }
        for(vector<Item*>::iterator i = v.begin(); i != v.end(); i++)
        {
            if(CLOSED_LIST != (*i)->belong)
            if(OPEN_LIST == (*i)->belong)
            {
                if(calcG(*i, parent) < (*i)->G)
                {
                    (*i)->G = calcG(*i, parent);
                    (*i)->H = manhattanWayLength(*i);
                    (*i)->F = calcF(*i);
                }
            }else{
                (*i)->parent = parent;
                (*i)->H = manhattanWayLength(*i);
                (*i)->G = calcG(*i, parent);
                (*i)->F = calcF(*i);
                openList->push_back(*i);
                if(grid[(*i)->number]->state != WAYPOINT)
                grid[(*i)->number]->setImage(GRAS_OPENLIST);
                (*i)->belong = OPEN_LIST;
            }

        }


}

void FindAStarWay::findAStarWay(Widget **grid, int a, int b)
{
    this->start = a;
    this->finish = b;

    Item* current = fullList->at(a);
    current->G = 0;
//    current->H = manhattanWayLength(current);
    current->H = 0;
//    current->F = calcF(current);
    current->F = 0;
    current->belong = OPEN_LIST;
    current->parent = 0;

    openList->push_back(current);

    while(1 != openList->empty())
    {
        current = findMin();
        if(b == current->number) //method to recreate path
            return;

        removeElement(openList, current);
        closedList->push_back(current);
        current->belong = CLOSED_LIST;

        addNeighbours(grid, current);

    }
}

void FindAStarWay::reconstructWay(Widget** grid)
{
    Item* current = closedList->at(closedList->size()-1);
    while(0 != current->parent)
    {
        grid[current->number]->setImage(WAY_POINT);
        current = current->parent;
    }
    grid[current->number]->setImage(START_POINT);
    grid[this->finish]->setImage(FINISH_POINT);
    openList->clear();
    closedList->clear();
    fullList->clear();
}
