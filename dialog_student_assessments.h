#ifndef DIALOG_STUDENT_ASSESSMENTS_H
#define DIALOG_STUDENT_ASSESSMENTS_H

#include <QDialog>

#include "mainwindow.h"
namespace Ui {
class Dialog_student_assessments;
}

class Dialog_student_assessments : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_student_assessments(QWidget *parent = nullptr);
    ~Dialog_student_assessments();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::Dialog_student_assessments *ui;
};

#endif // DIALOG_STUDENT_ASSESSMENTS_H
