#ifndef DIALOG_GROUP_H
#define DIALOG_GROUP_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class Dialog_group;
}

class Dialog_group : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_group(QWidget *parent = nullptr);
    ~Dialog_group();
//signals:
//    void firstWindow();  // Сигнал для первого окна на открытие

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::Dialog_group *ui;
//    MainWindow *h2;
};

#endif // DIALOG_GROUP_H
