#include "chambre.h"

chambre::chambre()
{

}
int chambre::getId()
{
    return this->id;
}
void chambre::setId(int id)
{
    this->id = id;
}
int chambre::getIdB()
{
    return this->ibB;
}
void chambre::setIdB(int idB)
{
    this->ibB = idB;
}
QString chambre::getlibelle()
{
    return  this->libelle;
}
void chambre::setLibelle(QString lib)
{
    this->libelle = lib;
}
