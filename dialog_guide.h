#ifndef DIALOG_GUIDE_H
#define DIALOG_GUIDE_H

#include <QDialog>
#include "mainwindow.h"
namespace Ui {
class Dialog_guide;
}

class Dialog_guide : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_guide(QWidget *parent = nullptr);
    ~Dialog_guide();

private slots:
    void on_pushButton_clicked();

    void on_listView_2_indexesMoved(const QModelIndexList &indexes);

private:
    Ui::Dialog_guide *ui;
};

#endif // DIALOG_GUIDE_H
