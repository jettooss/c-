#ifndef DIALOGVV_H
#define DIALOGVV_H

#include <QDialog>
 #include "mainwindow.h"
namespace Ui {
class Dialogvv;
}

class Dialogvv : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogvv(QWidget *parent = nullptr);
    ~Dialogvv();


    Ui::Dialogvv *ui;



private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // DIALOGVV_H
