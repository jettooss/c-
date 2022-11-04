#include "dialog_student_assessments.h"
#include "ui_dialog_student_assessments.h"
#include <QMessageBox>

MainWindow *h4;

Dialog_student_assessments::Dialog_student_assessments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_student_assessments)
{
    ui->setupUi(this);

}


Dialog_student_assessments::~Dialog_student_assessments()
{
    delete ui;
}


void Dialog_student_assessments::on_pushButton_7_clicked()
{
    MainWindow conn;
    QString credit_book,term,item_code,code_of_the_type_of_reporting,rating_code,date_text,teacher;
    credit_book=ui->lineEdit_credit_book_2->text();
    term=ui->lineEdit_surname_2->text();
    item_code=ui->lineEdit_name_2->text();
    code_of_the_type_of_reporting=ui->lineEdit_Middle_name_2->text();
    rating_code=ui->lineEdit_6->text();
    date_text=ui->lineEdit_group_idd_2->text();
    teacher=ui->lineEdit_group_idd_3->text();



    if (!conn.connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into student_assessments4 (credit_book,term,item_code,code_of_the_type_of_reporting,rating_code,date_text,teacher) values('"+credit_book+"','"+term+"','"+item_code+"','"+code_of_the_type_of_reporting+"','"+rating_code+"','"+date_text+"','"+teacher+"') ");
    if (qry.exec())
    {
        QMessageBox::critical(this,tr("save"),tr("saved"));
        conn.connClose();


    }
    else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
}

void Dialog_student_assessments::on_pushButton_5_clicked()
{   int count=0;

    qDebug()<<count;

    h4=new MainWindow(this);
    h4->show();





}



void Dialog_student_assessments::on_pushButton_4_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db);
    qry->prepare("select * from student_assessments4");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}

void Dialog_student_assessments::on_pushButton_6_clicked()
{
    MainWindow conn;
    QString credit_book,term,item_code,code_of_the_type_of_reporting,rating_code,date_text,teacher;
    credit_book=ui->lineEdit_credit_book_2->text();
    term=ui->lineEdit_surname_2->text();
    item_code=ui->lineEdit_name_2->text();
    code_of_the_type_of_reporting=ui->lineEdit_Middle_name_2->text();
    rating_code=ui->lineEdit_6->text();
    date_text=ui->lineEdit_group_idd_2->text();
    teacher=ui->lineEdit_group_idd_3->text();

    if (!conn.connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update student_assessments4 set credit_book='"+credit_book+"',term='"+term+"',item_code='"+item_code+"',code_of_the_type_of_reporting='"+code_of_the_type_of_reporting+"',rating_code='"+rating_code+"',date_text='"+date_text+"',teacher='"+teacher+"' where credit_book='"+credit_book+"' AND term='"+term+"'");
    if (qry.exec())
    {
        QMessageBox::critical(this,tr("Добавлено"),tr("сохранено"));
        conn.connClose();


    }
    else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
}

void Dialog_student_assessments::on_pushButton_8_clicked()
{
    MainWindow conn;
    QString credit_book,term,item_code,code_of_the_type_of_reporting,rating_code,date_text,teacher;
    credit_book=ui->lineEdit_credit_book_2->text();
    term=ui->lineEdit_surname_2->text();
    item_code=ui->lineEdit_name_2->text();
    code_of_the_type_of_reporting=ui->lineEdit_Middle_name_2->text();
    rating_code=ui->lineEdit_6->text();
    date_text=ui->lineEdit_group_idd_2->text();
    teacher=ui->lineEdit_group_idd_3->text();
    if (!conn.connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from student_assessments4 where credit_book='"+credit_book+"' AND term='"+term+"' ");
    if (qry.exec())
    {
        QMessageBox::critical(this,tr("удалить "),tr("удалить"));
        conn.connClose();


    }
    else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
}


