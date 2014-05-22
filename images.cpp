#include "images.h"

Images::Images()
{
    pixmaps[0] = new QPixmap(":/start.png");
    pixmaps[1] = new QPixmap(":/finish.png");
    pixmaps[2] = new QPixmap(":/wall.png");
    pixmaps[3] = new QPixmap(":/gras.png");
    pixmaps[4] = new QPixmap(":/waypoint.png");
    pixmaps[5] = new QPixmap(":/gras_openlist.png");
    pixmaps[6] = new QPixmap(":/gras_LEE_parentlist.png");
    pixmaps[7] = new QPixmap(":/waypointLEE.png");
}

QPixmap* Images::getPixMap(int n)
{
    return pixmaps[n];
}
