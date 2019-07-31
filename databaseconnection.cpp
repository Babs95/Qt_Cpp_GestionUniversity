#include "databaseconnection.h"
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include <QMessageBox>
#include <iostream>
DatabaseConnection::DatabaseConnection()
{
    this->getConexion();
}
void DatabaseConnection::getConexion()
{
     this->db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost");
    db.setUserName("postgres");
    db.setPassword("renard64");
    db.setDatabaseName("Qt");
    if(db.isOpen()){
    }
    else{
        db.open();
    }

}
QSqlQuery DatabaseConnection::executeQuery(QString sql)
{
    QSqlQuery requet;
    if(db.isOpen()){
        //this->getConexion();
        requet.exec(sql);
       // this->db.close();
       }
    else{
        db.open();
        requet.exec(sql);

    }

       return requet;


}
void DatabaseConnection::executeUpdate(QString sql)
{
      QSqlQuery requet;
      if(db.isOpen()){
          //this->getConexion();
          requet.exec(sql);
         // this->db.close();
         }
      else{
          db.open();
          requet.exec(sql);
      }
}
