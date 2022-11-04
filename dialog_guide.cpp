#include "dialog_guide.h"
#include "ui_dialog_guide.h"

#include <QMessageBox>
MainWindow *h5;
Dialog_guide::Dialog_guide(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_guide)
{
    ui->setupUi(this);



}

Dialog_guide::~Dialog_guide()
{
    delete ui;
}

void Dialog_guide::on_pushButton_clicked()
{
    h5=new MainWindow(this);
    h5->show();
}

//    MainWindow conn;
//    QSqlQueryModel * modal=new QSqlQueryModel();
//    conn.connOpen();
//    QSqlQuery* qry=new QSqlQuery(conn.db);
//    qry->prepare("select * from Student2");
//    qry->exec();
//    modal->setQuery(*qry);
//    ui->tableView->setModel(modal);
//    conn.connClose();
//    qDebug()<<(modal->rowCount());
