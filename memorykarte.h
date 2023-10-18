#ifndef MEMORYKARTE_H
#define MEMORYKARTE_H

#include <QTableView>
#include <QTableWidget>
#include <QPixmap>

//memorykarte muss von QTableWidgetItem erben um zum Spielfeld hinzugefügt werden zu können
class memorykarte : public QTableWidgetItem
{


public:
    memorykarte(QString = 0,int=0);
    int KartenID =0;
    QPixmap *KartenBild;
    QString Bildnamen;
    bool KarteAufgedeckt = false;
    bool NochimSpiel = true;
    int Positionmerken[2] = {};
};

#endif // MEMORYKARTE_H
