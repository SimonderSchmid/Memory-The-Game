#ifndef LIST_H
#define LIST_H
#include "spieler.h"




class list
{
private:

    spielerptr help=NULL;
    spielerptr aktuellerSpieler=NULL;



public:


    ~list();
    void addelement(QString);

    void searchelement();

    QString output();

    void nextelement();

    void erhöhePaare();

    int getanzahlPaare();

    int getHighestPoints();

    int getacutalPoints();

    QString getWinnername();
};

#endif // LIST_H
