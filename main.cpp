#include "mainwindow.h"
#include "login.h"
#include<iostream>
#include <QMessageBox>
using namespace std;
#include <QApplication>
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
     MainWindow w;
    w.show();
    //Login log;
    //log.show();

    return a.exec();
}
