#ifndef CHAMBRE_H
#define CHAMBRE_H
#include<QString>

class chambre
{
public:
    chambre();
    void setId(int id);
    void setIdB(int idB);
    void setLibelle(QString lib);
    int getId();
    int getIdB();
    QString getlibelle();
    void LoadBatiment();
private:
    int id;
    int ibB;
    QString libelle;
};

#endif // CHAMBRE_H
