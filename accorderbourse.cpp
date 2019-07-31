#include "accorderbourse.h"
#include "ui_bourse.h"
#include<QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QSqlQueryModel>
#include "typebourse.h"
#include "ConnexionDatabase.h"
AccorderBourse::AccorderBourse(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AccorderBourse)
{
    ui->setupUi(this);
    ui->comboBox->addItem("20000");
    ui->comboBox->addItem("40000");
    con = new DatabaseConnection();
    this->idet = 0;
    this->idetB = 0;
}

AccorderBourse::~AccorderBourse()
{
    delete ui;
}
void AccorderBourse::loadtabview(){
    DatabaseConnection *con = new DatabaseConnection();
    QString sql="SELECT * FROM etudiant where id  not in (SELECT idet  FROM boursier ) ";
    QSqlQueryModel *QSM = new QSqlQueryModel();
    QSqlQuery rep  =con->executeQuery(sql);
    if(rep.next()){
        QSM->setQuery(rep);
        ui->tableView->setModel(QSM);
    }
}

void AccorderBourse::on_pushButton_2_clicked()
{
    this->loadtabview();
}
void AccorderBourse::loadTypeBourse()
{


}
void AccorderBourse::loadEtudiantBoursier()
{
   // ConnexionDatabase *con = new ConnexionDatabase();
    QString sql="SELECT *  FROM etudiant l,boursier b,type_bourses t where l.id = b.idet AND b.idbourse = t.id";
    QSqlQueryModel *QSM = new QSqlQueryModel();
    QSqlQuery rep  =this->con->executeQuery(sql);
    if(rep.next()){
        QSM->setQuery(rep);
        ui->tableView_2->setModel(QSM);

    }

}

void AccorderBourse::on_pushButton_3_clicked()
{
    this->loadEtudiantBoursier();
}

void AccorderBourse::on_pushButton_clicked()
{
     //ConnexionDatabase *con = new ConnexionDatabase();
    QString sql = "INSERT INTO boursier (idet,idbourse) VALUES (:idet,:idbourse)";

    //con->executeUpdate(sql);
    QSqlQuery QSM;
    QSM.prepare(sql);
    QSM.bindValue(":idet",this->idet);
    if(ui->comboBox->currentText() == "20000")
    {
      QSM.bindValue(":idbourse",1);
    }
    else{
       QSM.bindValue(":idbourse",2);
    }
    //QSM.bindValue(":idb",c.getIdB());
    QSM.exec();
   // this->loadEtudiantBoursier();
    //this->loadtabview();
   // cout<<c.getIdB()<<endl;
}



void AccorderBourse::on_tableView_doubleClicked(const QModelIndex &index)
{
    //QModelIndexList indexlist = ui->tableView->selectionModel()->selectedRows();
    //6
  // cout<< index.data(2).toString().toStdString() <<endl;

   //ConnexionDatabase *con = new ConnexionDatabase();


   QString sql = "SELECT *  FROM etudiant where id = "+index.data(0).toString()+" ";

   //con->executeUpdate(sql);
  // QString s = index.data(0).toString();
   QSqlQuery QSM = this->con->executeQuery(sql);
   //QSM.exec(sql);
   //QSM.bindValue(":id",index.data(0).toString());
   //.exec();
   while (QSM.next()) {
       ui->Tmat->setText(QSM.value("matricule").toString());
       ui->Tnom->setText(QSM.value("nom").toString());
       ui->Tprenom->setText(QSM.value("prenom").toString());
       ui->Ttel->setText(QSM.value("tel").toString());
       ui->textEdit->setText(QSM.value("datenaiss").toString());
       ui->Temail->setText(QSM.value("email").toString());
       this->idet = QSM.value("id").toInt();
   }

}

void AccorderBourse::on_tableView_2_doubleClicked(const QModelIndex &index)
{
     this->idetB = index.data(0).toInt();
    cout<< this->idetB <<endl;
}

void AccorderBourse::on_pushButton_4_clicked()
{
    //ui->tableView->selectionModel()->selectedRows();
    QString sql = "DELETE  FROM boursier  where idet = "+QString::number(this->idetB)+" ";
    cout<<QString::number(this->idetB).toStdString()<<endl;
    this->con->executeUpdate(sql);
   // QString s = index.data(0).toString();
    //QSqlQuery QSM;
    //QSM.exec(sql);

}

void AccorderBourse::on_tableView_2_clicked(const QModelIndex &index)
{
     this->idetB = index.data(0).toInt();
}
