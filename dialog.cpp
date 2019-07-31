#include "dialog.h"
#include "ui_dialog.h"
#include<QtSql>
#include<QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QSqlQueryModel>
#include "databaseconnection.h"
#include <QMessageBox>
#include "etudiant.h"
#include <QMetaObject>
#include <QObject>
#include <QFileDialog>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
 {
    ui->setupUi(this);
    //ui->Date->setSpecialValueText( " " );
    //ui->Date->setDate( QDate::fromString( "01/01/0001", "dd/MM/yyyy" ) );
     ui->comboBoxTypeEtudiant->installEventFilter(this);
    ui->Label_Adresse->setVisible(false);
    ui->adresselineEdit->setVisible(false);
     //QMetaObject::connect(ui->comboBoxTypeEtudiant, &QComboBox::currentIndexChanged, this, &Dialog::updateCheckboxes );
     this->idEtudiant=0;
     //QObject::connect(ui->comboBoxTypeEtudiant, &QComboBox::currentIndexChanged, this, &Dialog::updateCheckboxes);
    //QObject::connect(ui->comboBoxTypeEtudiant, SIGNAL (&QComboBox::currentIndexChanged),this, SLOT (&Dialog::updateCheckboxes));
    this->idTypeEtudiant=0;

 }

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::LoadTypeEtudiant(){
    ui->comboBoxTypeEtudiant->clear();
        QString sql="SELECT * FROM type_etudiant";
        QSqlQuery QSM = this->con.executeQuery(sql);
        do{
            QString vid  = QSM.value("id").toString();

            ui->comboBoxTypeEtudiant->addItem(QSM.value("libelle").toString());
        }while(QSM.next());
}

void Dialog::on_Add_Etudiant_clicked()
{
    if (this->picName != "")
    {

        QString to = this->picDir+"/"+ui->lineEdit_Tel->text();

        if (QFile::exists(to))
        {
            QFile::remove(to);
        }

        QFile::copy(this->picName, to);
        this->picName = "";
    }

    QString sql = "INSERT INTO etudiant (matricule,nom,prenom,datenaiss,email,tel) VALUES (\'"+ui->lineEdit_Matricule->text()+"\',\'"+ui->lineEdit_Nom->text()+"\',\'"+ui->lineEdit_prenom->text()+"\',\'"
    +ui->Date->date().toString("dd/MM/yyyy")+"\',\'"+ui->lineEdit_email->text()+"\',\'"+ui->lineEdit_Tel->text()+"\')";
    QSqlQuery rep  = con.executeQuery(sql);
    //this->idEtudiant =rep.lastInsertId();
    this->idEtudiant = rep.lastInsertId().toInt();
    cout<<QString::number(this->idEtudiant).toStdString()<<endl;

    QString sql3 = "INSERT INTO non_boursier (idet,adresse) VALUES (:idet,\'"+ui->adresselineEdit->text()+"\') ";
    QString sql2 = "INSERT INTO boursier (idet,idbourse) VALUES (:idet,null)";

    QSqlQuery QSM;
    QSqlQuery QSM1;
    QSM.prepare(sql2);
    QSM.bindValue(":idet",this->idEtudiant);
    QSM1.prepare(sql3);
    QSM1.bindValue(":idet",this->idEtudiant);
    if(ui->comboBoxTypeEtudiant->currentText() == "Boursier")
    {

        QSM.exec();
    }
    else{

        QSM1.exec();
    }
    QFile file("Etudiant.txt");
        if (!file.open(QIODevice::Append | QIODevice::Text))
            return;
        QTextStream flux(&file);
        flux.setCodec("UTF-8");
        flux << ui->lineEdit_Matricule->text() <<"  "<< ui->lineEdit_Nom->text() <<"  "<< ui->lineEdit_prenom->text() <<"  "<< ui->lineEdit_Tel->text()<<"  "<< ui->comboBoxTypeEtudiant->currentText() << endl;
        QMessageBox::information(this,"Etudianr","Etudiant ajouté avec succès");
    LoadAllStudenTab();
    on_Cancel_btn_clicked();



}


void Dialog::LoadAllStudenTab(){
    QString sql="SELECT * FROM etudiant";
    QSqlQueryModel *QSM = new QSqlQueryModel();
    QSqlQuery rep  =this->con.executeQuery(sql);
    if(rep.next()){
        QSM->setQuery(rep);
        ui->tableView->setModel(QSM);

    }

}

void Dialog::on_pushButton_4_clicked()
{
     LoadAllStudenTab();
     LoadTypeEtudiant();
}
bool Dialog::eventFilter(QObject *f_object, QEvent *f_event){
    if(f_object == ui->comboBoxTypeEtudiant){
        if(f_event->type() == QEvent::ChildAdded){

            if(ui->comboBoxTypeEtudiant->currentText() == "Boursier"){
                ui->Label_Adresse->setVisible(false);
                ui->adresselineEdit->setVisible(false);

            }else if(ui->comboBoxTypeEtudiant->currentText() == "Non_Boursier") {
                ui->Label_Adresse->setVisible(true);
                ui->adresselineEdit->setVisible(true);

            }
        }
        return false;
    }
    return false;
}
void Dialog::updateCheckboxes(int comboBoxIndex)
{
    switch( comboBoxIndex )
    {
        case 0:
              // enable checkboxes base on selection of first item in combobox
                ui->Label_Adresse->setVisible(false);
                ui->adresselineEdit->setVisible(false);
              break;

        case 1:
              // enable checkboxes base on selection of second item in combobox
                ui->Label_Adresse->setVisible(true);
                ui->adresselineEdit->setVisible(true);
              break;

        // etc.
        default:
              break;
    }
}

void Dialog::on_tableView_doubleClicked(const QModelIndex &index)
{
    QString sql = "SELECT *  FROM etudiant where id = "+index.data(0).toString()+" ";
    QSqlQuery QSM = this->con.executeQuery(sql);
    while (QSM.next()) {
        ui->Label_Adresse->setVisible(false);
        ui->adresselineEdit->setVisible(false);
        //ui->lineEdit->setText(QSM.value("libelle").toString());
        ui->lineEdit_Tel->setText(QSM.value("tel").toString());
        this->etudiantTel = QSM.value("tel").toString();
        ui->lineEdit_prenom->setText(QSM.value("prenom").toString());
        ui->lineEdit_Nom->setText(QSM.value("nom").toString());
        ui->lineEdit_Matricule->setText(QSM.value("matricule").toString());
        ui->lineEdit_email->setText(QSM.value("email").toString());
        ui->Date->setDate(QSM.value("datenaiss").toDate());
        ui->comboBoxTypeEtudiant->setCurrentText("Boursier");
        this->idEtudiant= QSM.value("id").toInt();
        if(QFile::exists(this->picDir+"/"+this->etudiantTel))
        {
            ui->rpLabel_2->setText("<img src=\"file:///"+this->picDir+"/"+this->etudiantTel+"\" alt=\"Image read error!\" height=\"128\" width=\"128\" />");
        }
    }

    QString sql1 = "SELECT *  FROM non_boursier where idet = "+QString::number(this->idEtudiant)+" ";
    QSqlQuery QSM2 = this->con.executeQuery(sql1);
    while (QSM2.next()) {
        ui->Label_Adresse->setVisible(true);
        ui->adresselineEdit->setVisible(true);
        ui->adresselineEdit->setText(QSM2.value("adresse").toString());
        ui->comboBoxTypeEtudiant->setCurrentText("Non_Boursier");

    }
    cout<<QString::number(this->idEtudiant).toStdString()<<endl;
    //cout<<QString::number(this->idTypeEtudiant).toStdString()<<endl;
}

void Dialog::on_Cancel_btn_clicked()
{
    ui->lineEdit_Tel->setText("");
    ui->lineEdit_prenom->setText("");
    ui->lineEdit_Nom->setText("");
    ui->lineEdit_Matricule->setText("");
    ui->lineEdit_email->setText("");
    ui->Date->setSpecialValueText( " " );
    ui->Date->setDate( QDate::fromString( "01/01/0001", "dd/MM/yyyy" ) );
    ui->adresselineEdit->setText("");
    ui->rpLabel_2->setText("<img src=\":/images/user.png\" />");
    ui->Label_Adresse->setVisible(false);
    ui->adresselineEdit->setVisible(false);
    ui->comboBoxTypeEtudiant->clear();
}

void Dialog::on_pushButton_2_clicked()
{
    this->picName = QFileDialog::getOpenFileName(this, tr("Open Image"), "/", tr("Image Files (*.png *.jpg *.bmp)"));
    ui->rpLabel_2->setText("<img src=\"file:///"+this->picName+"\" alt=\"Image read error!\" height=\"128\" width=\"128\" />");
}



void Dialog::on_Delete_btn_clicked()
{
    QString sql = "DELETE FROM etudiant  where id = "+QString::number(this->idEtudiant)+" ";
    cout<<QString::number(this->idEtudiant).toStdString()<<endl;
    this->con.executeQuery(sql);
    QString sql1 = "DELETE FROM boursier  where idet = "+QString::number(this->idEtudiant)+" ";
    this->con.executeQuery(sql1);
    QString sql2 = "DELETE FROM non_boursier  where idet = "+QString::number(this->idEtudiant)+" ";
    this->con.executeQuery(sql2);
    QString to = this->picDir+"/"+this->etudiantTel;

    if (QFile::exists(to))
    {
        QFile::remove(to);
    }
    LoadAllStudenTab();
    on_Cancel_btn_clicked();
}

void Dialog::on_Update_btn_clicked()
{
    QString sql = "UPDATE etudiant  SET nom=\'"+ui->lineEdit_Nom->text()+"\',prenom=\'"+ui->lineEdit_prenom->text()+"\',matricule=\'"+ui->lineEdit_Matricule->text()+"\',tel=\'"+ui->lineEdit_Tel->text()+"\',email=\'"+ui->lineEdit_email->text()+"\' where id = "+QString::number(this->idEtudiant)+" ";
    this->con.executeUpdate(sql);
    QString sql2 = "UPDATE non_boursier  SET adresse=\'"+ui->adresselineEdit->text()+"\' where idet = "+QString::number(this->idEtudiant)+" ";
    this->con.executeUpdate(sql2);
    if (this->picName != "")
    {
        QString to = this->picDir+"/"+ui->lineEdit_Tel->text();

        if (QFile::exists(to))
        {
            QFile::remove(to);
        }

        QFile::copy(this->picName, to);
        this->picName = "";
    }
    LoadAllStudenTab();
    on_Cancel_btn_clicked();
}

