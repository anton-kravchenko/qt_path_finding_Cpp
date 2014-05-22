#include "choose_buttons.h"
#include "ui_choose_buttons.h"
#include "connector.h"

choose_buttons::choose_buttons(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choose_buttons)
{
    ui->setupUi(this);
    ui->aStarCheckBox->setChecked(true);
    ui->LEE_checkBox->setChecked(true);
}

int choose_buttons::place_now = START;

choose_buttons::~choose_buttons()
{
    delete ui;
}

void choose_buttons::on_start_box_clicked()
{
    place_now = START;
}


void choose_buttons::on_finish_box_clicked()
{
    place_now = FINISH;
}

void choose_buttons::on_wall_button_clicked()
{
    place_now = WALL;
}

void choose_buttons::on_empty_button_clicked()
{
    place_now = EMPTY;
}
void choose_buttons::on_go_button_clicked()
{
    Connector::findPath();
}

void choose_buttons::on_clearButton_clicked()
{
    Connector::clear();
}

void choose_buttons::on_aStarCheckBox_clicked()
{
    if(ui->aStarCheckBox->isChecked())
    {
        Connector::showAStarWay = true;
    }else {
        Connector::showAStarWay = false;
    }
}

void choose_buttons::on_LEE_checkBox_clicked()
{
    if(ui->LEE_checkBox->isChecked())
    {
        Connector::showLeeWay = true;
    }else {
        Connector::showLeeWay = false;
    }
}
