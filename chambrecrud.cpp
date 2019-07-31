#include "chambrecrud.h"
#include "ui_chambrecrud.h"
#include "chambre.h"
#include "batiment.h"
#include<QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QSqlQueryModel>
#include "databaseconnection.h"
#include <vector>
#include <iostream>

using namespace std;
Chambrecrud::Chambrecrud(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chambrecrud)
{
    ui->setupUi(this);
    ui->comboBox->installEventFilter(this);
    //ui->tableViewlogement->viewport()->installEventFilter(this);
    this->idCh = 0;
    this->idBatiment = 0;
}

Chambrecrud::~Chambrecrud()
{
    delete ui;
}
void Chambrecrud::loadtabview(){
    QString sql="SELECT * FROM chambre";
    QSqlQueryModel *QSM = new QSqlQueryModel();
    QSqlQuery rep  = this->con.executeQuery(sql);
    if(rep.next()){
        QSM->setQuery(rep);
        ui->tableViewlogement->setModel(QSM);
    }
}
void Chambrecrud::loadBatiment(){
ui->comboBox->clear();

    QString sql="SELECT * FROM batiment";
    QSqlQuery QSM = this->con.executeQuery(sql);
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

void Chambrecrud::on_pushButton_clicked()
{
    chambre c;
    c.setLibelle(ui->lineEdit->text());
    for (int i = 0; i<this->Vb.size();i++) {
        batiment b = Vb[i];
       cout<<b.getId()<<endl;
        QString lb = ui->comboBox->currentText();
        if(b.getLibelle() == lb){
            cout<<"dans le if"<<endl;
            c.setIdB(b.getId());
        }
    }
    QString sql = "INSERT INTO chambre (libelle,idbat) VALUES (:lib,:idb)";
    QSqlQuery QSM;
    QSM.prepare(sql);
    QSM.bindValue(":lib",ui->lineEdit->text());
    QSM.bindValue(":idb",c.getIdB());
    QSM.exec();
    cout<<c.getIdB()<<endl;

    //this->loadtabview();
        QFile file("Chambre.txt");
        if (!file.open(QIODevice::Append | QIODevice::Text))
            return;
        QTextStream flux(&file);
        flux.setCodec("UTF-8");
        flux << ui->lineEdit->text()    <<"  "<<      ui->comboBox->currentText() << endl;

    ui->lineEdit->clear();
    QMessageBox::information(this,"Chambre","Chambre crée avec succès");


}

void Chambrecrud::on_pushButton_4_clicked()
{
    this->loadtabview();
    this->loadBatiment();
}

bool Chambrecrud::eventFilter(QObject *f_object, QEvent *f_event){
    if(f_object == ui->comboBox){
        if(f_event->type() == QEvent::MouseButtonPress){
            loadBatiment();
            loadtabview();
        }
        return false;
    }
    return false;
}
/*bool Chambrecrud::eventFilterTable(QObject *f_object, QEvent *f_event){
    if(f_object == ui->tableViewlogement){
        if(f_event->type() == QEvent::ApplicationStateChange){
            loadtabview();
        }
        return false;
    }
    return false;
}*/

void Chambrecrud::on_tableViewlogement_doubleClicked(const QModelIndex &index)
{

    QString sql = "SELECT *  FROM chambre where id = "+index.data(0).toString()+" ";
    QSqlQuery QSM = this->con.executeQuery(sql);
    while (QSM.next()) {
        ui->lineEdit->setText(QSM.value("libelle").toString());
        this->idCh = QSM.value("id").toInt();
        this->idBatiment = QSM.value("idbat").toInt();
    }
    QString sql1 = "SELECT *  FROM batiment where id = "+QString::number(this->idBatiment)+" ";
    QSqlQuery QSM2 = this->con.executeQuery(sql1);
    while (QSM2.next()) {
        ui->comboBox->setCurrentText(QSM2.value("libelle").toString());

    }
    cout<<QString::number(this->idCh).toStdString()<<endl;
    cout<<QString::number(this->idBatiment).toStdString()<<endl;
}

void Chambrecrud::on_Delete_Btn_clicked()
{
    QString sql = "DELETE FROM chambre  where id = "+QString::number(this->idCh)+" ";
    cout<<QString::number(this->idCh).toStdString()<<endl;
    this->con.executeQuery(sql);
    loadtabview();
    on_Cancel_Btn_clicked();
}

void Chambrecrud::on_UpdateBtn_clicked()
{
    chambre c;
    for (int i = 0; i<this->Vb.size();i++) {
        batiment b = Vb[i];
       cout<<b.getId()<<endl;
        QString lb = ui->comboBox->currentText();
        if(b.getLibelle() == lb){
            cout<<"dans le if"<<endl;
            c.setIdB(b.getId());
        }
    }
    this->idBatiment = c.getIdB();
    QString sql = "UPDATE chambre  SET libelle=\'"+ui->lineEdit->text()+"\',idbat="+QString::number(this->idBatiment)+" where id = "+QString::number(this->idCh)+" ";
    this->con.executeUpdate(sql);
    loadtabview();
    on_Cancel_Btn_clicked();
}

void Chambrecrud::on_Cancel_Btn_clicked()
{
    ui->lineEdit->setText("");
    ui->comboBox->clear();
}


