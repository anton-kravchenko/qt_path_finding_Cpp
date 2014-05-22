#include "connector.h"
//#include "matrix.h"
#include "surface_states.h"
Connector::Connector()
{

}

Matrix* Connector::m = 0;
FindWay* Connector::findWay = 0;
FindAStarWay* Connector::findAStarWay = 0;

bool Connector::showAStarWay = true;
bool Connector::showLeeWay = true;

void Connector::sendStart(int start)
{
    if(0 == m)
    {
        m = Matrix::getInstanse();
    }
    m->setStart(start);
}
void Connector::sendFinish(int finish)
{
    if(0 == m )
    {
        m = Matrix::getInstanse();
    }
    m->setFinish(finish);
}
void Connector::clear()
{
    if( 0 == m)
    {
        m->getInstanse();
    }
    for(int i = 0; i < WIDTH*HEIGHT; i++)
    {
        m->getMatrix()[i]->setState(EMPTY);
        m->getMatrix()[i]->weight = -1;
    }

    for(int i = 0; i < WIDTH * HEIGHT; i+= WIDTH)
        m->getMatrix()[i]->setState(WALL);//left

    for(int i = WIDTH-1; i < WIDTH * HEIGHT; i+= WIDTH)
        m->getMatrix()[i]->setState(WALL);//right

    for(int i = 0; i < WIDTH; i++)
        m->getMatrix()[i]->setState(WALL);//up

    for(int i = WIDTH * (HEIGHT - 1); i < WIDTH * HEIGHT; i++)
        m->getMatrix()[i]->setState(WALL);//down

    m->start = 0;
    m->finish = 0;
}

void Connector::findPath()
{
    if(showLeeWay)
    {
        if(0 == findWay)
        {
            findWay = new FindWay;
        }

        findWay->find_path(m->getMatrix(), m->start, m->finish);
    }
    if(showAStarWay)
    {
        delete findAStarWay;
        Item::counter = 0;
        findAStarWay = new FindAStarWay;

        findAStarWay->findAStarWay(m->getMatrix(), m->start, m->finish);
        findAStarWay->reconstructWay(m->getMatrix());
    }
}
