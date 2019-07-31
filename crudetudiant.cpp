#include "crudetudiant.h"
#include "ui_Crudetudiant.h"
#include<QtSql>
#include<QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QSqlQueryModel>
#include "connexiondatabase.h"
#include <QMessageBox>
#include "etudiant.h"

CRUDETUDIANT::CRUDETUDIANT(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CRUDETUDIANT)
 {
    ui->setupUi(this);
   // ListE = new  classListe();


 }

CRUDETUDIANT::~CRUDETUDIANT()
{
    delete ui;
}

void CRUDETUDIANT::on_pushButton_clicked()
{
    ConnexionDatabase *con = new ConnexionDatabase();
    Etudiant *et = new Etudiant();
    et->settel(ui->Ttel->toPlainText());
    et->setPreNom(ui->Tprenom->toPlainText());
    et->SetNom(ui->Tnom->toPlainText());
    et->SetMatricul(ui->Tmat->toPlainText());
    et->setDatenaisse(ui->Date->date().toString("dd/MM/yyyy"));
    et->setEmail(ui->Temail->toPlainText());
    this->ListE->addT(et);
    ui->Ttel->clear();
    ui->Tprenom->clear();
    ui->Tnom->clear();
    ui->Tmat->clear();
    ui->Temail->clear();
    QString sql = "INSERT INTO etudiant (matricule,nom,prenom,datenaiss,email,tel) VALUES (\'"+et->getMatricul()+"\',\'"+et->getNom()+"\',\'"+et->getPreNom()+"\',\'"
    +et->getDatenaisse()+"\',\'"+et->getEmail()+"\',\'"+et->gettel()+"\')";
    con->executeUpdate(sql);
    loadtabview();
 // QMessageBox::information(this,"info",ui->Date->date().toString("dd/MM/yyyy"));


}

void CRUDETUDIANT::on_pushButton_3_clicked()
{
    ConnexionDatabase *con = new ConnexionDatabase();


        lists *T2 = ListE->getT();
        while (T2!= nullptr) {
            Etudiant *et = T2->T;
            QMessageBox::information(this,"info",et->getNom());
          QString sql = "INSERT INTO etudiant (matricule,nom,prenom,datenaiss,email,tel) VALUES (\'"+et->getMatricul()+"\',\'"+et->getNom()+"\',\'"+et->getPreNom()+"\',\'"
                  +et->getDatenaisse()+"\',\'"+et->getEmail()+"\',\'"+et->gettel()+"\')";
          con->executeUpdate(sql);

            T2= T2->suiv;
        }

}
void CRUDETUDIANT::loadtabview(){
    ConnexionDatabase *con = new ConnexionDatabase();
    QString sql="SELECT * FROM etudiant";
    QSqlQueryModel *QSM = new QSqlQueryModel();
    QSqlQuery rep  =con->executeQuery(sql);
    if(rep.next()){
        QSM->setQuery(rep);
        ui->tableView->setModel(QSM);
    }

}

void CRUDETUDIANT::on_pushButton_4_clicked()
{
     loadtabview();
}
