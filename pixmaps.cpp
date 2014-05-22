#include "pixmaps.h"

Pixmaps::Pixmaps()
{
}

QPixmap* Pixmaps::pixmaps[3] = {new QPixmap(":/gras.png"), new QPixmap(":/wall.png")};

Pixmaps::~Pixmaps()
{
    delete pixmaps[0];
    delete pixmaps[1];
    delete pixmaps[2];
}
