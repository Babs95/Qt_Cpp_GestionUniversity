#ifndef ETUDIANT_H
#define ETUDIANT_H
#include<QString>
#include <deque>
using namespace std;
class Etudiant
{
public:
    Etudiant();
    QString getNom();
    QString getPreNom();
    QString getDatenaisse();
    QString gettel();
    QString getMatricul();
    QString getEmail();
    int getid();
    bool  getisboursier();
    bool getisloger();
    void SetNom(QString nom);
    void SetMatricul(QString nom);
    void setPreNom(QString prenom);
    void setDatenaisse(QString date);
    void settel(QString tel);
    void setEmail(QString Email);
    void setid(int id);


private:
    QString nom;
    QString prenom;
    QString datnaiss;
    QString tel;
    QString adress;
    QString matricul;
    QString Email;
    int id;
    
};

#endif // ETUDIANT_H
