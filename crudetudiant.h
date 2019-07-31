#ifndef CRUDETUDIANT_H
#define CRUDETUDIANT_H
#include "connexiondatabase.h"
#include <QDialog>
#include "classliste.h"
#include "ui_Crudetudiant.h"
using namespace std;
namespace Ui {
class CRUDETUDIANT;
}

class CRUDETUDIANT : public QDialog
{
    Q_OBJECT

public:
    explicit CRUDETUDIANT(QWidget *parent = nullptr);
    ~CRUDETUDIANT();
    void loadtabview();

private slots:
void on_pushButton_clicked();

void on_pushButton_3_clicked();

void on_pushButton_4_clicked();

private:
    Ui::CRUDETUDIANT *ui;
    ConnexionDatabase *con;
    classListe *ListE = new classListe();
};
#endif // CRUDETUDIANT_H
