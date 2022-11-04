#ifndef DIALOGCREDIT_BOOK_H
#define DIALOGCREDIT_BOOK_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class Dialogcredit_book;
}

class Dialogcredit_book : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogcredit_book(QWidget *parent = nullptr);
    ~Dialogcredit_book();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Dialogcredit_book *ui;
};

#endif // DIALOGCREDIT_BOOK_H
