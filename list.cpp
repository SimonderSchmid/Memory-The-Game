#include "list.h"
#include <QDebug>



void list::addelement(QString input)
{

    spielerptr a,b;

    if (help == NULL)
    {
        help = new spieler;
        help->spielername = input;

        help->prev = NULL;
        help->next = NULL;
    }

    else
    {
        b=help;
        while(b->next!=NULL){b=b->next;}
        a = new spieler;
        a->spielername = input;
        a->next = NULL;
        b->next=a;
        a->prev = b;
    }
    aktuellerSpieler=help;
}

list::~list()
{
    spielerptr b;
    while (help != NULL)
    {
        b = help;
        help = help->next;
        delete b;

    }
}

QString list::output()
{
    spielerptr a;
    a = aktuellerSpieler;


    return a->spielername;


}

void list::nextelement()
{

    if(aktuellerSpieler->next==NULL)
    {
        aktuellerSpieler = help;
    }
    else
    {
        aktuellerSpieler=aktuellerSpieler->next;
    }

}

void list::erhöhePaare()
{
    aktuellerSpieler->gesammeltepaare++;
}

int list::getanzahlPaare()
{
    return aktuellerSpieler->gesammeltepaare;
}

int list::getHighestPoints()
{
    spielerptr a=help;
    int Paare;
    Paare=a->gesammeltepaare;
    while(a->next != 0)
    {
        a=a->next;
        if(a->gesammeltepaare > Paare)
            Paare=a->gesammeltepaare;
    }

    return Paare;
}

int list::getacutalPoints()
{
    return aktuellerSpieler->gesammeltepaare;
}

QString list::getWinnername()
{

    spielerptr a=help;
    spielerptr b=help;
    int Paare;

    Paare=a->gesammeltepaare;
    while(a->next != 0)
    {
        a=a->next;
        if(a->gesammeltepaare > Paare)
        {
            Paare=a->gesammeltepaare;
            b=a;
        }

    }

    return b->spielername;
}




