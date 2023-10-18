#ifndef FENSTER_H
#define FENSTER_H

#include <QWidget>
#include <QLabel>
#include <QTimer>
#include "spieler.h"
#include <QTableWidget>
#include "memorykarte.h"
#include "list.h"
#include <QtMultimedia>




namespace Ui {
class fenster;
}

class fenster : public QWidget
{
    Q_OBJECT

public:
    explicit fenster(QWidget *parent = nullptr, QString S1=0, QString S2=0, QString S3=0,QString S4=0,int Anzahlspieler = 0);
    ~fenster();



    spieler Spieler1;
    spieler Spieler2;
    spieler Spieler3;
    spieler Spieler4;
    int anzahlspieler=0;
    void spiel();

public slots:
    void zellegeklicktslot(int c,int d);
    void timerslot();

private:
    Ui::fenster *ui;
    QTableWidget *spielfeld;
    memorykarte *karten[18];
    QTimer *KartenUmdrehen;
    int AnzahlUmgedrehteKarten=0;
    memorykarte KartenaufdecktID[2]={};
    bool Paaraufgedeckt = false;
    int PaareInsgesamt = 0;
    bool ersterZug=true;
    QLabel *Spielerpaarelabel[4];
    int Arraywert=0;
    QMediaPlayer *GameSound;
    QAudioOutput *audioOutput;
    QMediaPlayer *cashRegisterSound;
    QPixmap *Reifen;
    QPixmap *pix;
    QPixmap *LorBeerBlatt;


    //Hier wird die instanz der Klasse list erstellt. Und anschließend die Knoten des Typs Spieler dynamisch erstellt.
    list Spieler;


};

#endif // FENSTER_H
