#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loger.h"
#include "accorderbourse.h"
#include "addbatiment.h"
#include "addlogement.h"
#include "dialog.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
 {
    ui->setupUi(this);



 }

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionCRUD_ETUDIANT_triggered()
{
    this->babs.show();
}

void MainWindow::on_actionCRUD_BOURSE_triggered()
{
    this->bourse.show();
}

void MainWindow::on_actionCRUD_LOGEMENT_triggered()
{
    this->loog.show();
}

void MainWindow::on_actionCRUD_CHAMBRE_triggered()
{
    this->chambr.show();
}

void MainWindow::on_actionCRUD_BATIMENT_triggered()
{
    this->bat.show();
}
