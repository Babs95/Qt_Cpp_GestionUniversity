#include "login.h"
#include "ui_login.h"
#include <QPixmap>
#include<QSqlDatabase>
#include<QtSql/QSqlQuery>
#include<QSqlQueryModel>
#include "databaseconnection.h"
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    QPixmap pix("D:/COURS/3EME ANNEE/COURS C++/Gestion_Sen_University/images/logo.jpg");
    ui->LogoLabel->setPixmap(pix);
    con = new DatabaseConnection();
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    //Load();

    //DatabaseConnection *con  = new DatabaseConnection();
    QString login = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString sql = "SELECT * FROM utilisareur WHERE login='"+ login +"' and password='"+ password +"' ";
    QSqlQuery qry = this->con->executeQuery(sql);;

     if(qry.next()){
        this->loginuser= qry.value("login").toString();
        cout<<this->loginuser.toStdString()<<endl;

        if (this->loginuser == "admin") {
                //hide();
                this->main.show();
            }
        if (this->loginuser == "bourse") {
                //hide();
                this->bourse.show();
            }
        if (this->loginuser == "logement") {
                //hide();
                this->loog.show();
            }
        if (this->loginuser == "etudiant") {
                //hide();
                this->babs.show();
            }

        }
    else {
        QMessageBox::information(this,"Login","Login ou mot de passe incorrect");
    }
}
