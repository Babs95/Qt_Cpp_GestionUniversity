#include "batiment.h"

batiment::batiment()
{

}
int batiment::getId()
{
    return this->id;
}
void batiment::setId(int id)
{
    this->id = id;
}
QString batiment::getLibelle()
{
    return  this->libelle;
}
void batiment::setLibelle(QString lib)
{
    this->libelle = lib;
}
