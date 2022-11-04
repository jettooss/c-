#ifndef DIALOGGUIDE_H
#define DIALOGGUIDE_H

#include <QDialog>

namespace Ui {
class Dialogguide;
}

class Dialogguide : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogguide(QWidget *parent = nullptr);
    ~Dialogguide();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialogguide *ui;
};

#endif // DIALOGGUIDE_H
