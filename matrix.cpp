#include "matrix.h"

Matrix::Matrix()
{
    images = new Images;
    for(int i = 0; i < HEIGHT * WIDTH; i++)
    {
        imageButtons[i] = new Widget;
        imageButtons[i]->setImagesObjet(images);

    }
}


Matrix* Matrix::m = 0;

Matrix* Matrix::getInstanse()
{
    if(0 == m)
    {
        m =  new Matrix;
    }
        return m;
}

Widget** Matrix::getMatrix()
{
    return imageButtons;
}

void Matrix::setStart(int n)
{
    start = n;
}

void Matrix::setFinish(int n)
{
    finish = n;
}
