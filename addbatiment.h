#ifndef ADDBATIMENT_H
#define ADDBATIMENT_H
#include "ConnexionDatabase.h"
#include <QDialog>

namespace Ui {
class Addbatiment;
}

class Addbatiment : public QDialog
{
    Q_OBJECT

public:
    explicit Addbatiment(QWidget *parent = nullptr);
    ~Addbatiment();
    void loadtabview();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableView2_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Addbatiment *ui;
    ConnexionDatabase *con;
    int IdBat;
    QString libelleBat;
};

#endif // ADDBATIMENT_H
