#include "loger.h"
#include "ui_loger.h"
#include<QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QSqlQueryModel>
#include "databaseconnection.h"
using namespace std;
loger::loger(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::loger)
{
    ui->setupUi(this);
    ui->comboBox->installEventFilter(this);
    this->idetb = 0;
    this->idLogement = 0;
    this->idChambre = 0;
    ui->lineEdit_Matricule->setEnabled(false);
    ui->lineEdit_Nom->setEnabled(false);
    ui->lineEdit_prenom->setEnabled(false);
    ui->lineEdit_Email->setEnabled(false);
    ui->lineEdit_Tel->setEnabled(false);
    ui->lineEdit_datenaiss->setEnabled(false);

    ui->pushButton->setEnabled(false);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
}

loger::~loger()
{
    delete ui;
}
void loger::loadtabview(){

      QString sql="SELECT * FROM etudiant et,boursier b where et.id=b.idet and b.idbourse is not null and et.id not in (SELECT idet FROM loger)";
    QSqlQueryModel *QSM = new QSqlQueryModel();
    QSM->setQuery(con.executeQuery(sql));
    ui->TEtuBousier->setModel(QSM);
}
void loger::LoadEtudiantLoger(){
    QString sql="SELECT * FROM etudiant et,loger lo where et.id=lo.idet AND et.id in (SELECT idet FROM loger) ";
    QSqlQueryModel *QSM = new QSqlQueryModel();
    QSM->setQuery(con.executeQuery(sql));
    ui->TEtLoger->setModel(QSM);
}


void loger::on_TEtuBousier_doubleClicked(const QModelIndex &index)
{
    ui->comboBox->clear();
    ui->pushButton->setEnabled(true);
    ui->pushButton_4->setEnabled(false);
    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(false);
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
       this->idetb = QSM.value("id").toInt();
       if(QFile::exists(this->picDir+"/"+this->etudiantTel))
       {
           ui->rpLabel_2->setText("<img src=\"file:///"+this->picDir+"/"+this->etudiantTel+"\" alt=\"Image read error!\" height=\"128\" width=\"128\" />");
       }
   }
}
void loger::loadlogement(){
    ui->comboBox->clear();
    QString sql="SELECT * FROM chambre";
    QSqlQuery QSM = this->con.executeQuery(sql);
    do{
        chambre b;
        QString vid  = QSM.value("id").toString();

        b.setId(vid.toInt());
        cout<<b.getId()<<endl;
        b.setLibelle(QSM.value("libelle").toString());
        this->VectorChambre.push_back(b);
        ui->comboBox->addItem(QSM.value("libelle").toString());
    }while(QSM.next());
}

void loger::on_pushButton_3_clicked()
{
    this->loadtabview();
    this->loadlogement();
    this->LoadEtudiantLoger();
}

void loger::on_pushButton_clicked()
{
    chambre c;
    for (int i = 0; i<this->VectorChambre.size();i++) {
        chambre b = VectorChambre[i];
       cout<<b.getId()<<endl;
        QString lb = ui->comboBox->currentText();
        if(b.getlibelle() == lb){
            c.setId(b.getId());
        }
    }

    //QString lb = ui->comboBox->currentText();

    QString sql = "INSERT INTO logement (idch) VALUES (:idch)";
    QSqlQuery QSM;
    QSM.prepare(sql);
    QSM.bindValue(":idch",c.getId());
    QSM.exec();
    this->idLogement = QSM.lastInsertId().toInt();
    QString sql2 = "INSERT INTO loger (idet,idlogement) VALUES (\'"+QString::number(this->idetb)+"\',\'"+QString::number(this->idLogement)+"\')";
    con.executeQuery(sql2);

    QFile file("Loger.txt");
    if (!file.open(QIODevice::Append | QIODevice::Text))
        return;
    QTextStream flux(&file);
    flux.setCodec("UTF-8");
    flux << ui->lineEdit_Matricule->text()<<"  "<< ui->lineEdit_Nom->text()<<"  "<< ui->lineEdit_prenom->text()<<"  "<< ui->comboBox->currentText() << endl;
    QMessageBox::information(this,"Logement","Boursier loger avec succès");
}

void loger::on_TEtLoger_clicked(const QModelIndex &index)
{
    ui->pushButton->setEnabled(false);
    ui->pushButton_4->setEnabled(true);
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(true);

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
        this->idetb = QSM.value("id").toInt();
        if(QFile::exists(this->picDir+"/"+this->etudiantTel))
        {
            ui->rpLabel_2->setText("<img src=\"file:///"+this->picDir+"/"+this->etudiantTel+"\" alt=\"Image read error!\" height=\"128\" width=\"128\" />");
        }
    }
    QString sql2 = "SELECT *  FROM loger where idet = "+QString::number(this->idetb)+" ";
    QSqlQuery QSM2 = this->con.executeQuery(sql2);
    while (QSM2.next()) {
        this->idLogement = QSM2.value("idlogement").toInt();
    }

    QString sql3 = "SELECT *  FROM logement where id = "+QString::number(this->idLogement)+" ";
    QSqlQuery QSM3 = this->con.executeQuery(sql3);
    while (QSM3.next()) {
        this->idChambre = QSM3.value("idch").toInt();
    }

    QString sql4 = "SELECT *  FROM chambre where id = "+QString::number(this->idChambre)+" ";
    QSqlQuery QSM4 = this->con.executeQuery(sql4);
    while (QSM4.next()) {
        ui->comboBox->setCurrentText(QSM4.value("libelle").toString());

    }
    cout<<QString::number(this->idetb).toStdString()<<endl;
    cout<<QString::number(this->idLogement).toStdString()<<endl;
    cout<<QString::number(this->idChambre).toStdString()<<endl;
}
bool loger::eventFilter(QObject *f_object, QEvent *f_event){
    if(f_object == ui->comboBox){
        if(f_event->type() == QEvent::MouseButtonPress){
            loadlogement();
        }
        return false;
    }
    return false;
}
