#ifndef BATIMENT_H
#define BATIMENT_H
#include<QString>

class batiment
{
public:
    batiment();
    void setId(int id);
    void setLibelle(QString lib);
    int getId();
    QString getLibelle();
private:
    int id;
    QString libelle;

};

#endif // BATIMENT_H
