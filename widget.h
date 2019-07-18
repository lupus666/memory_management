#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"progress.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();
    void update();

private slots:
    void on_new_2_clicked();

    void on_single_step_clicked();

    void on_FIFO_clicked(bool checked);

    void on_LRU_clicked(bool checked);

    void on_s_clicked();

    void on_LRU_2_clicked(bool checked);

    void on_new_3_clicked();

private:
    Ui::Widget *ui;
    progress *pro;
    Algorithm ALGORITHM;
};

#endif // WIDGET_H
