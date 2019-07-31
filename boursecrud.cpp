#include "boursecrud.h"
#include "ui_boursecrud.h"
#include<QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QSqlQueryModel>
#include "typebourse.h"
#include "ConnexionDatabase.h"
Boursecrud::Boursecrud(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Boursecrud)
{
    ui->setupUi(this);
    ui->comboBox->installEventFilter(this);
    /*ui->comboBox->addItem("Demi-pension");
    ui->comboBox->addItem("Pension complète");*/
    this->idet = 0;
    this->idBourse = 0;
    this->idTypeBourse = 0;
    ui->lineEdit_Matricule->setEnabled(false);
    ui->lineEdit_Nom->setEnabled(false);
    ui->lineEdit_prenom->setEnabled(false);
    ui->lineEdit_Email->setEnabled(false);
    ui->lineEdit_Tel->setEnabled(false);
    ui->lineEdit_datenaiss->setEnabled(false);

    ui->pushButton->setEnabled(false);
    ui->UpdateBourse->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
}

Boursecrud::~Boursecrud()
{
    delete ui;
}
void Boursecrud::loadtabview(){
    //DatabaseConnection *con = new DatabaseConnection();
    QString sql="SELECT * FROM etudiant et,boursier b where et.id=b.idet AND b.idbourse is null";
    QSqlQueryModel *QSM = new QSqlQueryModel();
    QSqlQuery rep  =this->con.executeQuery(sql);
    if(rep.next()){
        QSM->setQuery(rep);
        ui->tableView->setModel(QSM);
    }
}

void Boursecrud::on_pushButton_2_clicked()
{
    this->loadtabview();
    this->loadTypeBourse();
    this->loadEtudiantBoursier();
}
void Boursecrud::loadTypeBourse()
{
    ui->comboBox->clear();

        QString sql="SELECT * FROM type_bourses";
        QSqlQuery rep = this->con.executeQuery(sql);
        do{
            /*typeBourse typb;
            QString id  = rep.value("id").toString();

            typb.setId(id.toInt());
            cout<<typb.getId()<<endl;
            typb.setLibelle(rep.value("libelle").toString());
            //typb.setMontant(rep.value("montant").toInt());
            this->VectorTypeB.push_back(typb);*/
            ui->comboBox->addItem(rep.value("libelle").toString());
        }while(rep.next());

}
void Boursecrud::loadEtudiantBoursier()
{
    //DatabaseConnection *con = new DatabaseConnection();
    QString sql="SELECT *  FROM etudiant l,boursier b where l.id = b.idet AND b.idbourse in (SELECT id FROM bourses )";
    QSqlQueryModel *QSM = new QSqlQueryModel();
    QSqlQuery rep  =this->con.executeQuery(sql);
    if(rep.next()){
        QSM->setQuery(rep);
        ui->tableView_2->setModel(QSM);

    }

}

void Boursecrud::on_pushButton_3_clicked()
{
    this->loadEtudiantBoursier();
}

void Boursecrud::on_pushButton_clicked()
{

    QString sql = "INSERT INTO bourses (montant,idtype) VALUES (20000,:idtype)";
    QString sql1 = "INSERT INTO bourses (montant,idtype) VALUES (40000,:idtype)";
    /*QString sql2 = "UPDATE boursier SET idbourse=16 where id = \'"+QString::number(this->idet)+"\' ";
      con.executeUpdate(sql2);*/
    QSqlQuery QSM;
    QSqlQuery QSM1;
    QSqlQuery QSM2;
    QSM.prepare(sql);
    QSM1.prepare(sql1);


    if(ui->comboBox->currentText() == "Demi-pension ")
    {
      QSM.bindValue(":idtype",1);
      QSM.exec();
      this->idBourse = QSM.lastInsertId().toInt();
      cout<<QString::number(this->idBourse).toStdString()<<endl;
      cout<<QString::number(this->idet).toStdString()<<endl;
      QString sql2 = "UPDATE boursier SET idbourse=\'"+QString::number(this->idBourse)+"\' where idet = "+QString::number(this->idet)+" ";
      QSM2.prepare(sql2);
      QSM2.exec();
        con.executeUpdate(sql2);
    }
    else if(ui->comboBox->currentText() == "Pension complète "){
       QSM1.bindValue(":idtype",2);
       QSM1.exec();
       this->idBourse = QSM.lastInsertId().toInt();
       cout<<QString::number(this->idBourse).toStdString()<<endl;
       cout<<QString::number(this->idet).toStdString()<<endl;
       QString sql2 = "UPDATE boursier SET idbourse=\'"+QString::number(this->idBourse)+"\' where idet = "+QString::number(this->idet)+" ";
         con.executeUpdate(sql2);

    }
    QFile file("Bourse.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;
    QTextStream flux(&file);
    flux.setCodec("UTF-8");
    flux << ui->lineEdit_Matricule->text()<<"  "<< ui->lineEdit_Nom->text()<<"  "<< ui->lineEdit_prenom->text()<<"  "<< ui->comboBox->currentText() << endl;

    QMessageBox::information(this,"Bourse","Bourse attribuée avec succès");
}



void Boursecrud::on_tableView_doubleClicked(const QModelIndex &index)
{
    ui->comboBox->clear();

    ui->pushButton->setEnabled(true);
    ui->UpdateBourse->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);

   QString sql = "SELECT *  FROM etudiant where id = "+index.data(0).toString()+" ";
   QSqlQuery QSM = this->con.executeQuery(sql);
   while (QSM.next()) {
       ui->lineEdit_Matricule->setText(QSM.value("matricule").toString());
       ui->lineEdit_Nom->setText(QSM.value("nom").toString());
       ui->lineEdit_prenom->setText(QSM.value("prenom").toString());
       ui->lineEdit_Tel->setText(QSM.value("tel").toString());
       this->etudiantTel = QSM.value("tel").toString();
       ui->lineEdit_datenaiss->setText(QSM.value("datenaiss").toString());
       ui->lineEdit_Email->setText(QSM.value("email").toString());
       this->idet = QSM.value("id").toInt();
       if(QFile::exists(this->picDir+"/"+this->etudiantTel))
       {
           ui->rpLabel_2->setText("<img src=\"file:///"+this->picDir+"/"+this->etudiantTel+"\" alt=\"Image read error!\" height=\"128\" width=\"128\" />");
       }
   }

}

void Boursecrud::on_tableView_2_doubleClicked(const QModelIndex &index)
{
    ui->pushButton->setEnabled(false);
    ui->UpdateBourse->setEnabled(true);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    QString sql = "SELECT *  FROM etudiant where id = "+index.data(0).toString()+" ";
    QSqlQuery QSM = this->con.executeQuery(sql);
    while (QSM.next()) {
        ui->lineEdit_Matricule->setText(QSM.value("matricule").toString());
        ui->lineEdit_Nom->setText(QSM.value("nom").toString());
        ui->lineEdit_prenom->setText(QSM.value("prenom").toString());
        ui->lineEdit_Tel->setText(QSM.value("tel").toString());
        this->etudiantTel = QSM.value("tel").toString();
        ui->lineEdit_datenaiss->setText(QSM.value("datenaiss").toString());
        ui->lineEdit_Email->setText(QSM.value("email").toString());
        this->idet = QSM.value("id").toInt();
        if(QFile::exists(this->picDir+"/"+this->etudiantTel))
        {
            ui->rpLabel_2->setText("<img src=\"file:///"+this->picDir+"/"+this->etudiantTel+"\" alt=\"Image read error!\" height=\"128\" width=\"128\" />");
        }
    }

    QString sql2 = "SELECT *  FROM boursier where idet = "+QString::number(this->idet)+" ";
    QSqlQuery QSM2 = this->con.executeQuery(sql2);
    while (QSM2.next()) {
        this->idBourse = QSM2.value("idbourse").toInt();
    }

    QString sql3 = "SELECT *  FROM bourses where id = "+QString::number(this->idBourse)+" ";
    QSqlQuery QSM3 = this->con.executeQuery(sql3);
    while (QSM3.next()) {
        this->idTypeBourse = QSM3.value("idtype").toInt();
    }

    QString sql4 = "SELECT *  FROM type_bourses where id = "+QString::number(this->idTypeBourse)+" ";
    QSqlQuery QSM4 = this->con.executeQuery(sql4);
    while (QSM4.next()) {
        ui->comboBox->setCurrentText(QSM4.value("libelle").toString());

    }
    cout<<QString::number(this->idet).toStdString()<<endl;
    cout<<QString::number(this->idBourse).toStdString()<<endl;
    cout<<QString::number(this->idTypeBourse).toStdString()<<endl;
}

bool Boursecrud::eventFilter(QObject *f_object, QEvent *f_event){
    if(f_object == ui->comboBox){
        if(f_event->type() == QEvent::MouseButtonPress){
            loadTypeBourse();
        }
        return false;
    }
    return false;
}

void Boursecrud::on_UpdateBourse_clicked()
{
    /*typeBourse typ;
    for (int i = 0; i<this->VectorTypeB.size();i++) {
        typeBourse typb = VectorTypeB[i];
       cout<<typb.getId()<<endl;
        QString lb = ui->comboBox->currentText();
        if(typb.getLibelle() == lb){
            cout<<"dans le if"<<endl;
            typ.setId(typb.getId());
        }
    }
    this->idBourse = typ.getId();*/
    QString sql = "UPDATE bourses SET montant=20000,idtype=1 where id = "+QString::number(this->idBourse)+" ";
    QString sql2 = "UPDATE bourses SET montant=40000,idtype=2 where id = "+QString::number(this->idBourse)+" ";
    /*QSqlQuery QSM;
    QSqlQuery QSM2;
    QSM.prepare(sql);
    QSM2.prepare(sql2);*/

    if(ui->comboBox->currentText() == "Demi-pension ")
    {
        //QSM.exec();
        this->con.executeUpdate(sql);
        cout<<QString::number(this->idBourse).toStdString()<<endl;
    }
    else if(ui->comboBox->currentText() == "Pension complète "){
        //QSM2.exec();
        this->con.executeUpdate(sql2);
        cout<<QString::number(this->idBourse).toStdString()<<endl;
    }
    QMessageBox::information(this,"Bourse","Bourse modifier avec succès");
}

void Boursecrud::on_pushButton_5_clicked()
{
    QString sql = "DELETE  FROM bourses  where id = "+QString::number(this->idBourse)+" ";
    cout<<QString::number(this->idBourse).toStdString()<<endl;
     QString sql2 = "UPDATE boursier SET idbourse=null where idet = "+QString::number(this->idet)+" ";
    this->con.executeQuery(sql);
    this->con.executeQuery(sql2);
     QMessageBox::information(this,"Bourse","Bourse annuler avec succès");
}
