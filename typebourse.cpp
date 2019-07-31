#include "typebourse.h"

typeBourse::typeBourse()
{

}
int typeBourse::getId()
{
    return this->id;
}
void typeBourse::setId(int id)
{
    this->id = id;
}
QString typeBourse::getLibelle()
{
    return  this->libelle;
}
void typeBourse::setLibelle(QString libelle)
{
    this->libelle = libelle;
}
int typeBourse::getMontant()
{
    return this->montant;
}
void typeBourse::setMontant(int montant)
{
    this->montant = montant;
}
