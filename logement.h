#ifndef LOGEMENT_H
#define LOGEMENT_H
#include<QString>

class logement
{
public:
    logement();
    void setId(int id){this->id = id;}
    void setLibelle(QString lib){this->libelle = lib;}
    int getId(){return  this->id;}
    QString getLibelle(){return  this->libelle;}
private:
    int id;
    QString libelle;
};

#endif // LOGEMENT_H
