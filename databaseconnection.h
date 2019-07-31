#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include <QMessageBox>
#include <iostream>
class DatabaseConnection
{
public:
    DatabaseConnection();
    void getConexion();
    QSqlQuery executeQuery(QString sql);
    void executeUpdate(QString sql);
private:
    QSqlDatabase db;
};

#endif // DATABASECONNECTION_H
