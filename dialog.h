#ifndef DIALOG_H
#define DIALOG_H
#include "databaseconnection.h"
#include <QDialog>
#include "ui_dialog.h"
#include "etudiant.h"
#include "batimentcrud.h"
#include <QCoreApplication>
#include <QApplication>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void LoadAllStudenTab();
    void LoadTypeEtudiant();
    bool eventFilter(QObject *f_object, QEvent *f_event);
    QString picName;
    //QString picDir = QCoreApplication::applicationDirPath()+"/../../Gestion_Sen_University/users/avatar";
    //QString picDir = QApplication::applicationDirPath()+"users/avatar";
    QString picDir = QCoreApplication::applicationDirPath();



private slots:
    void on_pushButton_4_clicked();

    void updateCheckboxes(int comboBoxIndex);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_Cancel_btn_clicked();

    void on_pushButton_2_clicked();

    void on_Delete_btn_clicked();

    void on_Update_btn_clicked();

    void on_Add_Etudiant_clicked();

private:
    Ui::Dialog *ui;
    DatabaseConnection con;
    int idEtudiant;
    int idTypeEtudiant;
    QString etudiantTel;
};
#endif // DIALOG_H
