#ifndef MATRIX_H
#define MATRIX_H
#include "widget.h"
#include "images.h"
class Matrix
{
    static Matrix* m;
    Matrix();
    void initButtons();


public:

    Widget* imageButtons[HEIGHT * WIDTH];
    Images* images;
    int start;
    int finish;
    void setStart(int);
    void setFinish(int);

    static Matrix* getInstanse();
    Widget **getMatrix();
};

#endif // MATRIX_H
