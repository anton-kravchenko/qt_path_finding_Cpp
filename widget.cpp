#include "widget.h"
#include "ui_widget.h"
#include "choose_buttons.h"
#include "widget.h"
#include "surface_states.h"
#include "connector.h"


Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    number = counter++;
    ui->setupUi(this);

    weight = -1;
    state = EMPTY;

}

int Widget::counter = 0;

void Widget::setImagesObjet(Images* images)
{
    this->images = images;
    ui->imageButton->setPixmap(*images->getPixMap(EMPTY));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::setImage(int s)
{
    ui->imageButton->setPixmap(*images->getPixMap(s));
}

void Widget::setState(int s)
{

    if(GO != choose_buttons::place_now)
    {
        state = s;
        ui->imageButton->setPixmap(*images->getPixMap(s));

        if(START == s)
        {
            Connector::sendStart(number);
        }
        if(FINISH == s)
        {
            Connector::sendFinish(number);
        }

    }else{
        Connector::findPath();
    }

}

void Widget::mousePressEvent ( QMouseEvent * event )

{
    emit clicked();
    setState(choose_buttons::place_now);
}
