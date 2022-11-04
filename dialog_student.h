#ifndef DIALOG_STUDENT_H
#define DIALOG_STUDENT_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class Dialog_student;
}

class Dialog_student : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_student(QWidget *parent = nullptr);
    ~Dialog_student();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Dialog_student *ui;

};

#endif // DIALOG_STUDENT_H
