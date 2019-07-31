#include "addbatiment.h"
#include "ui_batiment.h"
#include<QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QSqlQueryModel>
#include "connexiondatabase.h"
Addbatiment::Addbatiment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Addbatiment)
{
    ui->setupUi(this);
    con  = new ConnexionDatabase();
    this->IdBat=0;

}

Addbatiment::~Addbatiment()
{
    delete ui;
}

void Addbatiment::on_pushButton_3_clicked()
{
     ConnexionDatabase *con  = new ConnexionDatabase();
    //QMessageBox::information(this,"info",'');
    QString sql = "INSERT INTO batiment (libelle) VALUES (\'"+ui->lineEdit->text()+"\')";
     con->executeUpdate(sql);
    this->loadtabview();
}
void Addbatiment::loadtabview(){
    ConnexionDatabase *con  = new ConnexionDatabase();
    QString sql="SELECT * FROM batiment";
    QSqlQueryModel *QSM = new QSqlQueryModel();
    QSM->setQuery(con->executeQuery(sql));
    ui->tableView2->setModel(QSM);
}

void Addbatiment::on_pushButton_4_clicked()
{
    this->loadtabview();
}

void Addbatiment::on_tableView2_doubleClicked(const QModelIndex &index)
{
   QString sql = "SELECT *  FROM batiment where id = "+index.data(0).toString()+" ";
   QSqlQuery QSM = this->con->executeQuery(sql);
   while (QSM.next()) {
       ui->lineEdit->setText(QSM.value("libelle").toString());
       this->IdBat = QSM.value("id").toInt();
   }
   cout<<QString::number(this->IdBat).toStdString()<<endl;
}

void Addbatiment::on_pushButton_2_clicked()
{
    QString sql = "DELETE FROM batiment  where id = "+QString::number(this->IdBat)+" ";
    cout<<QString::number(this->IdBat).toStdString()<<endl;
    this->con->executeUpdate(sql);
    loadtabview();
    ui->lineEdit->setText("");
}

void Addbatiment::on_pushButton_clicked()
{
    QString sql = "UPDATE batiment  SET libelle=\'"+ui->lineEdit->text()+"\' where id = "+QString::number(this->IdBat)+" ";
    this->con->executeUpdate(sql);
    loadtabview();
}
