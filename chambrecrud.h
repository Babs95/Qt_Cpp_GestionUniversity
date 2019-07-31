#ifndef CHAMBRECRUD_H
#define CHAMBRECRUD_H
#include <QVector>
#include "databaseconnection.h"
#include <QDialog>
#include "batiment.h"
namespace Ui {
class Chambrecrud;
}

class Chambrecrud : public QDialog
{
    Q_OBJECT

public:
    explicit Chambrecrud(QWidget *parent = nullptr);
    ~Chambrecrud();
    void loadtabview();
    void loadBatiment();
    bool eventFilter(QObject *f_object, QEvent *f_event);
    bool eventFilterTable(QObject *f_object, QEvent *f_event);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();

    void on_tableViewlogement_doubleClicked(const QModelIndex &index);

    void on_UpdateBtn_clicked();

    void on_Cancel_Btn_clicked();

    void on_Delete_Btn_clicked();

private:
    Ui::Chambrecrud *ui;
    QVector<batiment> Vb;
    int idCh;
    int idBatiment;
    DatabaseConnection con;
};

#endif // CHAMBRECRUD_H
