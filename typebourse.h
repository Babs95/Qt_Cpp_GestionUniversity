#ifndef TYPEBOURSE_H
#define TYPEBOURSE_H
#include<QString>

class typeBourse
{
public:
    typeBourse();
    int getId();
    QString getLibelle();
    int getMontant();
    void setId(int id);
    void setLibelle(QString libelle);
    void setMontant(int montant);

private:
    int id;
    QString libelle;
    int montant;
};

#endif // TYPEBOURSE_H
