#include "maingeneral.h"
#include "ui_maingeneral.h"
#include "loger.h"
#include "accorderbourse.h"
#include "addbatiment.h"
#include "addlogement.h"
#include "mainwindow.h"
#include "dialog.h"
#include <QMessageBox>
Maingeneral::Maingeneral(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Maingeneral)
{
    ui->setupUi(this);

}

Maingeneral::~Maingeneral()
{
    delete ui;
}

void Maingeneral::on_pushButton_clicked()
{

   this->babs.show();
}

void Maingeneral::on_pushButton_2_clicked()
{

    this->lg.show();
}

void Maingeneral::on_pushButton_3_clicked()
{
    this->ab.show();
}

void Maingeneral::on_pushButton_4_clicked()
{
    addlogement a;
    this->al.show();
}

void Maingeneral::on_pushButton_5_clicked()
{
   this->a.show();
}
