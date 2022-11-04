#include "dialog_student.h"
#include "ui_dialog_student.h"

#include <QMessageBox>
MainWindow *h2;
Dialog_student::Dialog_student(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_student)
{
    ui->setupUi(this);
}

Dialog_student::~Dialog_student()
{
    delete ui;
}

void Dialog_student::on_pushButton_clicked()
{
    MainWindow conn;
    QString credit_book,surname,name,Middle_name,Year_of_admission,group_idd;
    credit_book=ui->lineEdit_credit_book->text();
    surname=ui->lineEdit_surname->text();
    name=ui->lineEdit_name->text();
    Middle_name=ui->lineEdit_Middle_name->text();
    Year_of_admission=ui->lineEdit_5->text();
    group_idd=ui->lineEdit_group_idd->text();

    if (!conn.connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("insert into Student2 (№credit_book,surname,name_,Middle_name,Year_of_admission,group_idd) values('"+credit_book+"','"+surname+"','"+name+"','"+Middle_name+"','"+Year_of_admission+"','"+group_idd+"') ");
    if (qry.exec())
    {
        QMessageBox::critical(this,tr("save"),tr("saved"));
        conn.connClose();


    }
    else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
}

void Dialog_student::on_pushButton_2_clicked()
{
    MainWindow conn;
    QString credit_book,surname,name,Middle_name,Year_of_admission,group_idd;
    credit_book=ui->lineEdit_credit_book->text();
    surname=ui->lineEdit_surname->text();
    name=ui->lineEdit_name->text();
    Middle_name=ui->lineEdit_Middle_name->text();
    Year_of_admission=ui->lineEdit_5->text();
    group_idd=ui->lineEdit_group_idd->text();

    if (!conn.connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("update Student2 set №credit_book='"+credit_book+"',surname='"+surname+"',name_='"+name+"',Middle_name='"+Middle_name+"',Year_of_admission='"+Year_of_admission+"',group_idd='"+group_idd+"' where №credit_book='"+credit_book+"'");
    if (qry.exec())
    {
        QMessageBox::critical(this,tr("Добавлено"),tr("сохранено"));
        conn.connClose();


    }
    else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
}

void Dialog_student::on_pushButton_3_clicked()
{
    MainWindow conn;
    QString credit_book,surname,name,Middle_name,Year_of_admission,group_idd;
    credit_book=ui->lineEdit_credit_book->text();
    surname=ui->lineEdit_surname->text();
    name=ui->lineEdit_name->text();
    Middle_name=ui->lineEdit_Middle_name->text();
    Year_of_admission=ui->lineEdit_5->text();
    group_idd=ui->lineEdit_group_idd->text();
    if (!conn.connOpen()){
        qDebug()<<"база данных не открылась ";
        return;
    }
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("Delete from Student2 where №credit_book='"+credit_book+"'");
    if (qry.exec())
    {
        QMessageBox::critical(this,tr("удалить "),tr("удалить"));
        conn.connClose();


    }
    else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
}

void Dialog_student::on_pushButton_4_clicked()
{
    MainWindow conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db);
    qry->prepare("select * from Student2");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}

void Dialog_student::on_pushButton_5_clicked()
{
;
        QSqlQuery qry;

        h2=new MainWindow(this);
        h2->show();

}
