#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QLabel>
#include "surface_states.h"
#include "images.h"
namespace Ui {
class Widget;
#define ONE
}

class Widget : public QWidget
{
    Q_OBJECT
signals:
    void clicked();

public:
    Images* images;
//    QPixmap* pixmaps[8];
    static int counter;
    int number;

    int state;
    int weight;


    void setImage(int);

    explicit Widget(QWidget *parent = 0);
    void mousePressEvent(QMouseEvent *);

    void setState(int);
    void setImagesObjet(Images *);
    ~Widget();

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
