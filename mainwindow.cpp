#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(!connOpen())
        ui->label->setText("бд не загрузилась");
    else ui->label->setText("все хорошо ");

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_6_clicked()
{

    if (!connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    connOpen();
    QSqlQuery qry;
    connClose();
    this->hide();
    Dialog_group dialog_group;
    dialog_group.setModal(true);
    dialog_group.exec();

}

void MainWindow::on_pushButton_4_clicked()
{
    if (!connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    connOpen();
    QSqlQuery qry;
    connClose();
    this->hide();
    Dialog_student dialog_student;
    dialog_student.setModal(true);
    dialog_student.exec();

}

void MainWindow::on_pushButton_3_clicked()
{
    if (!connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    connOpen();
    QSqlQuery qry;
    connClose();
    this->hide();
    Dialog_student_assessments dialog_student_assessments;
    dialog_student_assessments.setModal(true);
    dialog_student_assessments.exec();
}

void MainWindow::on_pushButton_clicked()
{
    if (!connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    connOpen();
    QSqlQuery qry;
    connClose();
    this->hide();
    Dialogguide dialogguide;
    dialogguide.setModal(true);
    dialogguide.exec();
}

void MainWindow::on_pushButton_8_clicked()
{

            if (!connOpen()){
                qDebug()<<"база данных не открылась ";
                return;
            }
            connOpen();
            QSqlQuery qry;
            connClose();
            this->hide();
            Dialogvv dialogvv;
            dialogvv.setModal(true);
            dialogvv.exec();
}

void MainWindow::on_pushButton_7_clicked()
{
    if (!connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    connOpen();
    QSqlQuery qry;
    connClose();
    this->hide();
    Dialogcredit_book dialogcredit_book;
    dialogcredit_book.setModal(true);
    dialogcredit_book.exec();
}
