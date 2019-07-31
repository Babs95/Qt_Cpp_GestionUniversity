#include "addlogement.h"
#include "chambre.h"
#include "batiment.h"
#include "ui_addlogement.h"
#include<QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QSqlQueryModel>
#include "ConnexionDatabase.h"
#include <vector>
#include <iostream>
using namespace std;
addlogement::addlogement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addlogement)
{
    ui->setupUi(this);

    this->loadBatiment();
    //con = new ConnexionDatabase();
}

addlogement::~addlogement()
{
    delete ui;
}
void addlogement::loadtabview(){
    ConnexionDatabase *con = new ConnexionDatabase();
    QString sql="SELECT * FROM chambre";
    QSqlQueryModel *QSM = new QSqlQueryModel();
    QSqlQuery rep  = con->executeQuery(sql);
    if(rep.next()){
        QSM->setQuery(rep);
        ui->tableViewlogement->setModel(QSM);
    }
}
void addlogement::loadBatiment(){

    //ConnexionDatabase *con = new ConnexionDatabase();
    QString sql="SELECT * FROM batiment";
    QSqlQuery QSM = this->con.executeQuery(sql);
    //QSM->setQuery(con->executeQuery(sql));
    do{
        batiment b;
        QString vid  = QSM.value("id").toString();

        b.setId(vid.toInt());
        cout<<b.getId()<<endl;
        b.setLibelle(QSM.value("libelle").toString());
        this->Vb.push_back(b);
        ui->comboBox->addItem(QSM.value("libelle").toString());
    }while(QSM.next());

}

void addlogement::on_pushButton_clicked()
{
    //ConnexionDatabase *con  = new ConnexionDatabase();
    chambre c;
    c.setLibelle(ui->textEdit->toPlainText());
    for (int i = 0; i<this->Vb.size();i++) {
        batiment b = Vb[i];
       cout<<b.getId()<<endl;
        QString lb = ui->comboBox->currentText();

        //cout<< lb.toStdString() << "les truc du combo" <<endl;
        //cout<< b.getLibelle().toStdString()<<endl;
        if(b.getLibelle() == lb){
            cout<<"dans le if"<<endl;
            c.setIdB(b.getId());
            //cout<<b.getId()<<endl;
            //cout<<c.getIdB()<<endl;
        }
    }
    QString s;

    // s = QString::number(c.getIdB());
   // QString sql = "INSERT INTO chambre (libelle,idbat) VALUES (\'"+ui->textEdit->toPlainText()+"\',"+QString::number(c.getIdB())+")";
    QString sql = "INSERT INTO chambre (libelle,idbat) VALUES (:lib,:idb)";

    //con->executeUpdate(sql);
    QSqlQuery QSM;
    QSM.prepare(sql);
    QSM.bindValue(":lib",ui->textEdit->toPlainText());
    QSM.bindValue(":idb",c.getIdB());
    QSM.exec();
    cout<<c.getIdB()<<endl;

    //this->loadtabview();
    ui->textEdit->clear();


}

void addlogement::on_pushButton_4_clicked()
{
    this->loadtabview();
}
