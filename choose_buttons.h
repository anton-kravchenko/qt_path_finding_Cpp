#ifndef CHOOSE_BUTTONS_H
#define CHOOSE_BUTTONS_H

#include <QDialog>
#include <surface_states.h>

namespace Ui {
class choose_buttons;
}

class choose_buttons : public QDialog
{
    Q_OBJECT

public:
    explicit choose_buttons(QWidget *parent = 0);
    ~choose_buttons();

    static int place_now;

private slots:

    void on_start_box_clicked();

    void on_finish_box_clicked();

    void on_wall_button_clicked();

    void on_empty_button_clicked();

    void on_go_button_clicked();

    void on_clearButton_clicked();

    void on_aStarCheckBox_clicked();

    void on_LEE_checkBox_clicked();

private:
    Ui::choose_buttons *ui;
};

#endif // CHOOSE_BUTTONS_H
