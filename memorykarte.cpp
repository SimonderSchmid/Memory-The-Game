#include "memorykarte.h"

memorykarte::memorykarte(QString Bildnamen,int bildZaehler)
{
    KartenID = bildZaehler;
    this->Bildnamen = Bildnamen;
    //KartenBild =new QPixmap;
    //KartenBild->load(Bildnamen);
    this->setIcon(QIcon(QPixmap("C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/f1logo.png"))); //Standardbild einfügen

}
