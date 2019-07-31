#include "ConnexionDatabase.h"
#include<QtSql/QtSql>
#include<QtSql/QSqlDatabase>
#include<QtSql/QSqlQuery>
#include <QMessageBox>
#include <iostream>
using namespace std;

ConnexionDatabase::ConnexionDatabase()
{
    this->getConexion();
}

void ConnexionDatabase::getConexion()
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
QSqlQuery ConnexionDatabase::executeQuery(QString sql)
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
void ConnexionDatabase::executeUpdate(QString sql)
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
