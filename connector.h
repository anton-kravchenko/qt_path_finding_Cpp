#ifndef CONNECTOR_H
#define CONNECTOR_H
#include "matrix.h"
#include "findway.h"
#include "findastarway.h"
class Connector
{
    Connector();
public:
    static Matrix* m;
    static FindWay *findWay;
    static FindAStarWay *findAStarWay;

    static bool showAStarWay;
    static bool showLeeWay;

    static void sendStart(int);
    static void sendFinish(int);

    static void clear();
    static void findPath();
};

#endif // CONNECTOR_H
