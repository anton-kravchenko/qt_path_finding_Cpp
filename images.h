#ifndef IMAGES_H
#define IMAGES_H
#include <QPixmap>
class Images
{
    QPixmap* pixmaps[8];
public:
    Images();
    QPixmap *getPixMap(int);
};

#endif // IMAGES_H
