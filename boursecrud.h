#ifndef BOURSECRUD_H
#define BOURSECRUD_H
#include "typebourse.h"
#include "databaseconnection.h"
#include <QDialog>
#include <QCoreApplication>
#include <QVector>
namespace Ui {
class Boursecrud;
}

class Boursecrud : public QDialog
{
    Q_OBJECT

public:
    explicit Boursecrud(QWidget *parent = nullptr);
    ~Boursecrud();
    void loadtabview();
    void loadTypeBourse();
    void loadEtudiantBoursier();
    bool eventFilter(QObject *f_object, QEvent *f_event);
    QString picName;
    QString picDir = QCoreApplication::applicationDirPath();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_tableView_2_doubleClicked(const QModelIndex &index);

    void on_UpdateBourse_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::Boursecrud *ui;
    int idet;
    int idBourse;
    int idTypeBourse;
    QString etudiantTel;
    QVector<typeBourse> VectorTypeB;
    DatabaseConnection con;
};

#endif // BOURSECRUD_H
