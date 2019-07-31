#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "mainwindow.h"
#include "loger.h"
#include "boursecrud.h"
#include "chambrecrud.h"
#include "dialog.h"
#include "batimentcrud.h"
#include "databaseconnection.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Login *ui;
    MainWindow main;
    Boursecrud bourse;
    loger loog;
    Dialog babs;
    Batimentcrud bat;
    Chambrecrud chambr;
    DatabaseConnection *con;
    QString loginuser;
};

#endif // LOGIN_H
