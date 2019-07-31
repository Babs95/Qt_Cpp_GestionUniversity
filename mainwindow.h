#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "loger.h"
#include "boursecrud.h"
#include "dialog.h"
#include "batimentcrud.h"
#include "chambrecrud.h"

using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_actionCRUD_ETUDIANT_triggered();

    void on_actionCRUD_BOURSE_triggered();

    void on_actionCRUD_LOGEMENT_triggered();

    void on_actionCRUD_CHAMBRE_triggered();

    void on_actionCRUD_BATIMENT_triggered();

private:
    Ui::MainWindow *ui;
    Boursecrud bourse;
    loger loog;
    Dialog babs;
    Batimentcrud bat;
    Chambrecrud chambr;

};

#endif // MAINWINDOW_H
