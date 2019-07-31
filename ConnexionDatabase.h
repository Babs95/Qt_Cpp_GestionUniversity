#ifndef CONNEXIONDATABASE_H
#define CONNEXIONDATABASE_H
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include <QMessageBox>
#include <iostream>
using namespace std;
class ConnexionDatabase
{
public:
    ConnexionDatabase();
    void getConexion();
    QSqlQuery executeQuery(QString sql);
    void executeUpdate(QString sql);
private:
    QSqlDatabase db;

};

#endif // CONNEXIONDATABASE_H
