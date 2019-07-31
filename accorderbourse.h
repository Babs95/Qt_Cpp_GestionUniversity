#ifndef ACCORDERBOURSE_H
#define ACCORDERBOURSE_H
#include "typebourse.h"
#include <QDialog>
#include "databaseconnection.h"
namespace Ui {
class AccorderBourse;
}

class AccorderBourse : public QDialog
{
    Q_OBJECT

public:
    explicit AccorderBourse(QWidget *parent = nullptr);
    ~AccorderBourse();
    void loadtabview();
    void loadTypeBourse();
    void loadEtudiantBoursier();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();


    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

private:
    Ui::AccorderBourse *ui;
    int idet;
    int idetB;
    DatabaseConnection *con;

};

#endif // ACCORDERBOURSE_H
