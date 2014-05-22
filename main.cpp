#include <QApplication>
#include <QHBoxLayout>
#include <QWidget>
#include <QGridLayout>
#include "choose_buttons.h"
#include "surface_states.h"
#include "matrix.h"
#include "findastarway.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget *mainWindow = new QWidget;
    mainWindow->setWindowTitle("matrix");
    mainWindow->maximumWidth();


    QGridLayout *layout = new QGridLayout;
    layout->setSpacing(0);
    layout->setMargin(0);
    layout->setAlignment(Qt::AlignCenter);

    choose_buttons *choose = new choose_buttons;
    layout->addWidget(choose, 0,0);

    QHBoxLayout* hLayouts[HEIGHT];
    for (int i = 0; i < HEIGHT; i++)
        hLayouts[i] = new QHBoxLayout;

    Matrix* m = Matrix::getInstanse();
    Widget** imageButtons = m->getMatrix();

    for(int i = 0; i < HEIGHT; i++)
    {
        for(int j = i*WIDTH; j < i*WIDTH + WIDTH; j++)
        {
            hLayouts[i]->addWidget(imageButtons[j]);
        }
        layout->addLayout(hLayouts[i], i+1, 0);
    }

    for(int i = 0; i < WIDTH * HEIGHT; i+= WIDTH)
        imageButtons[i]->setState(WALL);//left

    for(int i = WIDTH-1; i < WIDTH * HEIGHT; i+= WIDTH)
        imageButtons[i]->setState(WALL);//right

    for(int i = 0; i < WIDTH; i++)
        imageButtons[i]->setState(WALL);//up

    for(int i = WIDTH * (HEIGHT - 1); i < WIDTH * HEIGHT; i++)
        imageButtons[i]->setState(WALL);//down

//    FindAStarWay f;
//    f.findAStarWay(imageButtons, 52, 75);
//    f.reconstructWay(imageButtons);

    mainWindow->setLayout(layout);
    mainWindow->show();
    mainWindow->setFixedSize(mainWindow->size());
    return a.exec();
}
