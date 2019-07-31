#ifndef BATIMENTCRUD_H
#define BATIMENTCRUD_H
#include "databaseconnection.h"
#include <QDialog>

namespace Ui {
class Batimentcrud;
}

class Batimentcrud : public QDialog
{
    Q_OBJECT

public:
    explicit Batimentcrud(QWidget *parent = nullptr);
    ~Batimentcrud();
    void loadtabview();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_tableView2_doubleClicked(const QModelIndex &index);

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Batimentcrud *ui;
    DatabaseConnection con;
    int IdBat;
    QString libelleBat;
};

#endif // BATIMENTCRUD_H
