#include "dialog_group.h"
#include "ui_dialog_group.h"

#include <QMessageBox>
#include <mainwindow.h>
MainWindow *h3;
Dialog_group::Dialog_group(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_group)
{
    ui->setupUi(this);
    MainWindow conn;
    if(!conn.connOpen())
        ui->label->setText("проблемы");
    else ui->label->setText("все гуд");
}

Dialog_group::~Dialog_group()
{
    delete ui;
}

void Dialog_group::on_pushButton_clicked()
{
    MainWindow conn;
    QString group_id,specialization,Institute;
    Institute=ui->lineEdit_Institute->text();
    specialization=ui->lineEdit_specialization->text();
    group_id=ui->lineEdit_group_id->text();

    if (!conn.connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into Groups (group_id,Institute,specialization) values('"+group_id+"','"+specialization+"','"+Institute+"') ");
    if (qry.exec())
    {
        QMessageBox::critical(this,tr("save"),tr("saved"));
        conn.connClose();


    }
    else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
}

void Dialog_group::on_pushButton_4_clicked()
{
    MainWindow conn;
    QString group_id,specialization,Institute;
    Institute=ui->lineEdit_Institute->text();
    specialization=ui->lineEdit_specialization->text();
    group_id=ui->lineEdit_group_id->text();
    if (!conn.connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update Groups set group_id='"+group_id+"',specialization='"+specialization+"',Institute='"+Institute+"'where group_id='"+group_id+"'");
    if (qry.exec())
    {
        QMessageBox::critical(this,tr("Добавлено"),tr("сохранено"));
        conn.connClose();


    }
    else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
}


void Dialog_group::on_pushButton_3_clicked()
{
    MainWindow conn;
    QString group_id,specialization,Institute;
    Institute=ui->lineEdit_Institute->text();
    specialization=ui->lineEdit_specialization->text();
    group_id=ui->lineEdit_group_id->text();
    if (!conn.connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from Groups where group_id='"+group_id+"'");
    if (qry.exec())
    {
        QMessageBox::critical(this,tr("удалить "),tr("удалить"));
        conn.connClose();


    }
    else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());

}

void Dialog_group::on_pushButton_5_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db);
    qry->prepare("select * from Groups");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}

void Dialog_group::on_pushButton_7_clicked()
{




    QSqlQuery qry;

    h3=new MainWindow(this);
    h3->show();

}
