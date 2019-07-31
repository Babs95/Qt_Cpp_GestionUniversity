#ifndef MAINGENERAL_H
#define MAINGENERAL_H

#include <QDialog>
#include "loger.h"
#include "accorderbourse.h"
#include "addbatiment.h"
#include "addlogement.h"
#include "mainwindow.h"
#include "dialog.h"

namespace Ui {
class Maingeneral;
}

class Maingeneral : public QDialog
{
    Q_OBJECT

public:
    explicit Maingeneral(QWidget *parent = nullptr);
    ~Maingeneral();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Maingeneral *ui;
    MainWindow w;
    AccorderBourse a;
    Addbatiment ab;
    addlogement al;
    loger lg;
    Dialog babs;

};

#endif // MAINGENERAL_H
