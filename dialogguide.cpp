#include "dialogguide.h"
#include "ui_dialogguide.h"
#include <QMessageBox>
#include <mainwindow.h>
MainWindow *h5;
Dialogguide::Dialogguide(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogguide)
{
    ui->setupUi(this);

    MainWindow conn;
    if(!conn.connOpen())
    {
        qDebug()<<"база данных не открылась ";
        return;
    }
    else{
        QSqlQueryModel * modal=new QSqlQueryModel();
        QSqlQuery* qry=new QSqlQuery(conn.db);
        qry->prepare("select * from subject");
        qry->exec();
        modal->setQuery(*qry);
        qDebug()<<(modal->rowCount());
        ui->tableView->setModel(modal);

        QSqlQueryModel * modal1=new QSqlQueryModel();
        QSqlQuery* qry1=new QSqlQuery(conn.db);
        qry1->prepare("select * from estimation");
        qry1->exec();
        modal1->setQuery(*qry1);
        qDebug()<<(modal1->rowCount());
        ui->tableView_2->setModel(modal1);


        QSqlQueryModel * modal2=new QSqlQueryModel();
        QSqlQuery* qry2=new QSqlQuery(conn.db);
        qry2->prepare("select * from type_of_reporting");
        qry2->exec();
        modal2->setQuery(*qry2);
        qDebug()<<(modal2->rowCount());
        ui->tableView_3->setModel(modal2);

        }
}

Dialogguide::~Dialogguide()
{
    delete ui;
}

void Dialogguide::on_pushButton_clicked()
{
    h5=new MainWindow(this);
    h5->show();
}
