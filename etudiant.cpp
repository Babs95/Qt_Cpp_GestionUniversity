#include "etudiant.h"

Etudiant::Etudiant()
{

}
QString Etudiant::getNom()
{
    return  this->nom;
}
QString Etudiant::getPreNom()
{
    return this->prenom;
}
QString Etudiant::getDatenaisse()
{
    return this->datnaiss;
}
QString Etudiant::getEmail()
{
    return  this->Email;
}
QString Etudiant::gettel()
{
    return this->tel;
}
QString Etudiant::getMatricul()
{
    return this->matricul;
}
int Etudiant::getid()
{
    return this->id;
}
void Etudiant::SetNom(QString nom)
{
    this->nom = nom;
}
void Etudiant::setPreNom(QString prenom)
{
    this->prenom = prenom;
}
void Etudiant::setDatenaisse(QString date)
{
    this->datnaiss = date;
}
void Etudiant::settel(QString tel)
{
    this->tel = tel;
}
void Etudiant::setid(int id)
{
    this->id = id;
}

void Etudiant::SetMatricul(QString nom)
{
    this->matricul = nom;
}
void Etudiant::setEmail(QString Email)
{
    this->Email = Email;
}

