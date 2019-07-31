#ifndef ADDLOGEMENT_H
#define ADDLOGEMENT_H
#include "batiment.h"
#include <QDialog>
#include <QVector>
#include"ConnexionDatabase.h"
using namespace std;
namespace Ui {
class addlogement;
}

class addlogement : public QDialog
{
    Q_OBJECT

public:
    explicit addlogement(QWidget *parent = nullptr);
    ~addlogement();
    void loadtabview();
    void loadBatiment();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::addlogement *ui;
    QVector<batiment> Vb;
    ConnexionDatabase con;
};

#endif // ADDLOGEMENT_H
