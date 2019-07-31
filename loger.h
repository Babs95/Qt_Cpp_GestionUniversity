#ifndef LOGER_H
#define LOGER_H
#include <QVector>
#include <QDialog>
#include "databaseconnection.h"
#include "chambre.h"
#include <QCoreApplication>
namespace Ui {
class loger;
}

class loger : public QDialog
{
    Q_OBJECT

public:
    explicit loger(QWidget *parent = nullptr);
    ~loger();
    void loadtabview();
    void loadlogement();
    void LoadEtudiantLoger();
    bool eventFilter(QObject *f_object, QEvent *f_event);
    QString picName;
    QString picDir = QCoreApplication::applicationDirPath();

private slots:
    void on_TEtuBousier_doubleClicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_TEtLoger_clicked(const QModelIndex &index);

private:
    Ui::loger *ui;
    DatabaseConnection con;
    int idetb;
    int idLogement;
    int idChambre;
    QString etudiantTel;
    QVector<chambre> VectorChambre;

};

#endif // LOGER_H
