#include "batimentcrud.h"
#include "ui_batimentcrud.h"
#include<QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QSqlQueryModel>
#include "databaseconnection.h"
using namespace std;
Batimentcrud::Batimentcrud(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Batimentcrud)
{
    ui->setupUi(this);
    this->IdBat=0;


}

Batimentcrud::~Batimentcrud()
{
    delete ui;
}

void Batimentcrud::on_pushButton_3_clicked()
{
    QString sql = "INSERT INTO batiment (libelle) VALUES (\'"+ui->lineEdit->text()+"\')";
     this->con.executeUpdate(sql);
    this->loadtabview();
    ui->lineEdit->setText("");
        QFile file("batiment.txt");
        if (!file.open(QIODevice::Append | QIODevice::Text))
            return;
        QTextStream flux(&file);
        flux.setCodec("UTF-8");
        // Écriture dans le fichier
        flux << ui->lineEdit->text()<< endl;
        QMessageBox::information(this,"Batiment","Batiment crée avec succès");
}
void Batimentcrud::loadtabview(){
    QString sql="SELECT * FROM batiment";
    QSqlQueryModel *QSM = new QSqlQueryModel();
    QSM->setQuery(this->con.executeQuery(sql));
    ui->tableView2->setModel(QSM);
}

void Batimentcrud::on_pushButton_4_clicked()
{
    this->loadtabview();
}

void Batimentcrud::on_tableView2_doubleClicked(const QModelIndex &index)
{
   QString sql = "SELECT *  FROM batiment where id = "+index.data(0).toString()+" ";
   QSqlQuery QSM = this->con.executeQuery(sql);
   while (QSM.next()) {
       ui->lineEdit->setText(QSM.value("libelle").toString());
       this->IdBat = QSM.value("id").toInt();
   }
   cout<<QString::number(this->IdBat).toStdString()<<endl;
}

void Batimentcrud::on_pushButton_2_clicked()
{
    QString sql = "DELETE FROM batiment  where id = "+QString::number(this->IdBat)+" ";
    cout<<QString::number(this->IdBat).toStdString()<<endl;
    this->con.executeQuery(sql);
    loadtabview();
    ui->lineEdit->setText("");
}

void Batimentcrud::on_pushButton_clicked()
{
    QString sql = "UPDATE batiment  SET libelle=\'"+ui->lineEdit->text()+"\' where id = "+QString::number(this->IdBat)+" ";
    this->con.executeUpdate(sql);
    loadtabview();
}
