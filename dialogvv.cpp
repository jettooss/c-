#include "dialogvv.h"
#include "ui_dialogvv.h"
#include <QMessageBox>
#include <mainwindow.h>
MainWindow *mDialog;
Dialogvv::Dialogvv(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialogvv)
{
    ui->setupUi(this);
//    MainWindow conn;
//    QString inst;
//    QString credit_book,surname,name,Middle_name,Year_of_admission,group_idd;
//    QSqlQueryModel * modal2=new QSqlQueryModel();
//    QSqlQuery* qry2=new QSqlQuery(conn.db);
//    qry2->prepare("select Institute from Groups");
//    qry2->exec();
//    modal2->setQuery(*qry2);

//    ui->comboBox->setModel(modal2);
//    qDebug()<<(modal2->rowCount());

}

Dialogvv::~Dialogvv()
{
    delete ui;
}


void Dialogvv::on_pushButton_clicked()
{
    MainWindow conn;
    QString Institute,discipline,Examiner,Specialization,Group,Type,Term;
       discipline=ui->lineEdit_subjects->text();
       Examiner=ui->lineEdit_teacher->text();
       Specialization=ui->lineEdit_specialization->text();
       Group=ui->lineEdit_group_idd->text();
       Type=ui->lineEdit_tip->text();
       Term=ui->lineEdit_simak->text();
       Institute=ui->lineEdit_eHu->text();

       qDebug()<<Institute ;
       qDebug()<<discipline ;
       qDebug()<<Examiner ;
       qDebug()<<Specialization ;
       qDebug()<<Group ;
       qDebug()<<Type ;
       qDebug()<<Term ;




//       QSqlQueryModel * modal1=new QSqlQueryModel();
//       QSqlQuery* qry1=new QSqlQuery(conn.db);
//       qry1->prepare("SELECT Student2.name_ AS имя ,Student2.surname AS фамилия,Student2.Middle_name AS отчество ,Student2.№credit_book AS №зачетка ,estimation.ratingn  AS оценка  From Student2 "
//                     "INNER JOIN student_assessments4 on student_assessments4.credit_book=Student2.№credit_book"
//                     "INNER JOIN estimation on estimation.rating_code=student_assessments4.rating_code"
//                     "INNER JOIN Groups on Groups.group_id=Student2.group_idd"
////                     "where group_idd = 'Б0911ПРИ' AND teacher = 'Белозеров' AND term='1' AND specialization='ПРИ';");
//       "where group_idd = '"+Group+"' AND teacher = '"+Examiner+"' AND term='"+Term+"' AND specialization='"+Specialization+"'");
//       qry->prepare("SELECT Student2.name_,Student2.surname ,Student2.Middle_name  ,Student2.№credit_book  ,estimation.ratingn From Student2 "
//                    "INNER JOIN student_assessments4 on student_assessments4.credit_book=Student2.№credit_book"
//                    "INNER JOIN estimation on estimation.rating_code=student_assessments4.rating_code"
//                    "INNER JOIN Groups on Groups.group_id=Student2.group_idd"
//                    "where group_idd = Б0911ПРИ AND teacher = Белозеров AND term=1 AND specialization=ПРИ");

//       qry1->exec();
//       modal1->setQuery(*qry1);
//       qDebug()<<(modal1->rowCount());
       QSqlQueryModel * modal=new QSqlQueryModel();
       QSqlQuery* qry=new QSqlQuery(conn.db);
       qry->prepare("SELECT Student2.name_ AS имя ,Student2.surname AS фамилия,Student2.Middle_name AS отчество ,Student2.№credit_book AS №зачетка ,estimation.ratingn  AS оценка  From Student2 INNER JOIN student_assessments4 on student_assessments4.credit_book=Student2.№credit_book  INNER JOIN estimation on estimation.rating_code=student_assessments4.rating_code INNER JOIN Groups on Groups.group_id=Student2.group_idd INNER JOIN subject on subject.item_code=student_assessments4.item_code INNER JOIN  type_of_reporting on type_of_reporting.code_of_the_type_of_reporting=student_assessments4.code_of_the_type_of_reporting where group_idd = '"+Group+"' AND teacher = '"+Examiner+"' AND term='"+Term+"'   AND subjects='"+discipline+"'  AND type_of_reporting.code_of_the_type_of_reporting='"+Type+"'");
       qry->exec();
       modal->setQuery(*qry);
       qDebug()<<(modal->rowCount());
       ui->tableView->setModel(modal);
//AND specialization='"+Specialization+"' AND subjects='"+discipline+"' AND Institute='"+Institute+"' AND term='"+Term+"'
//    if (!conn.connOpen()){
//        qDebug()<<"база данных не открылась ";
//        return;
//    }
//    conn.connOpen();
//    QSqlQuery qry;
//    qry.prepare("insert into student_assessments4 (№credit_book,term,item_code,code_of_the_type_of_reporting,rating_code,date_text,teacher) values('"+credit_book+"','"+term+"','"+item_code+"','"+code_of_the_type_of_reporting+"','"+rating_code+"','"+date_text+"','"+teacher+"') ");
//    if (qry.exec())
//    {
//        QMessageBox::critical(this,tr("save"),tr("saved"));
//        conn.connClose();


//    }
//  else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
}



void Dialogvv::on_pushButton_2_clicked()
{
    mDialog = new  MainWindow(this); // allocated space for a new MyDialog
                                         // while also giving a parent class of
    mDialog->show();                                    // this, the MainWindow class

     // call the show method on the object
}
