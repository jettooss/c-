#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QtDebug>
#include <QFileInfo>
#include "dialog_group.h"
#include "dialog_student.h"
#include "dialog_student_assessments.h"
#include "dialogguide.h"
#include "dialogvv.h"
#include "dialogcredit_book.h"




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:
    QSqlDatabase db;
    void connClose()
    {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {

        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:\\Users\\PC\\Desktop\\df.db");
        if(!db.open())
        {
            qDebug()<<("возникли проблемы с подключением БД");
            return false;
        }
        else {
            qDebug()<<("нет ошибок  с БД ");
            return true;
        }

    }


private slots:
    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::MainWindow *ui;

    QSqlTableModel *model;




};
#endif // MAINWINDOW_H
