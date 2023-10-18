#ifndef SPIELER_H
#define SPIELER_H
#include <QWidget>

//Einfaches struct für die Spieler. Diese werden in einer Liste verkettet und während des Spielverlaufs wird die Liste abgelaufen.
struct spieler
{

    QString spielername="";
    int gesammeltepaare=0;

    struct spieler *next=NULL;
    struct spieler *prev = NULL;
};
typedef spieler* spielerptr;


#endif // SPIELER_H
