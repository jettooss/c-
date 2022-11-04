#include "dialogcredit_book.h"
#include "ui_dialogcredit_book.h"
MainWindow *h33;
Dialogcredit_book::Dialogcredit_book(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogcredit_book)
{
    ui->setupUi(this);
}

Dialogcredit_book::~Dialogcredit_book()
{
    delete ui;
}

void Dialogcredit_book::on_pushButton_clicked()
{
    h33=new MainWindow(this);
    h33->show();
}

void Dialogcredit_book::on_pushButton_2_clicked()
{
    MainWindow conn;
    QString Institute,Specialization,Group,date,simak,surname,name,midname,idbook;

       Specialization=ui->lineEdit_cpesal->text();
       Group=ui->lineEdit_group->text();
       date=ui->lineEdit_date->text();
       idbook=ui->lineEdit_book->text();
       Institute=ui->lineEdit_instut->text();
       surname=ui->lineEdit_surname->text();
       name=ui->lineEdit_name->text();
       midname=ui->lineEdit_midname->text();
       simak=ui->lineEdit_simak->text();
       qDebug()<<Institute ;
       qDebug()<<Specialization ;
       qDebug()<<date ;
        qDebug()<<idbook ;
       qDebug()<<surname ;
       qDebug()<<name ;
       qDebug()<<midname ;
       qDebug()<<Group ;
       qDebug()<<simak ;


       QSqlQueryModel * modal=new QSqlQueryModel();
       QSqlQuery* qry=new QSqlQuery(conn.db);
       qry->prepare("SELECT subject.subjects AS Предмет ,student_assessments4.teacher AS Преподаватель  ,estimation.ratingn  AS оценка ,student_assessments4.date_text AS Дата From Student2 INNER JOIN student_assessments4 on student_assessments4.credit_book=Student2.№credit_book INNER JOIN estimation on estimation.rating_code=student_assessments4.rating_code INNER JOIN Groups on Groups.group_id=Student2.group_idd INNER JOIN subject on subject.item_code=student_assessments4.item_code  where   term='"+simak+"' AND №credit_book='"+idbook+"' ");
       qry->exec();
       modal->setQuery(*qry);
       qDebug()<<(modal->rowCount());
       ui->tableView->setModel(modal);

}
