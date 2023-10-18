#include "fenster.h"
#include "ui_fenster.h"
#include "mainwindow.h"
#include <QDebug>
#include <QHeaderView>
#include <QTableView>


QString Bildnamen[]= {"C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/mercedes.jpg","C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/redbull.jpg",
                     "C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/safety.jpg","C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/verstappen.jpg",
                     "C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/vettel.jpg","C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/bulle.jpg",
                     "C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/Ferarri.jpg","C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/hamilton.jpg",
                     "C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/lauda.jpg"};


fenster::fenster(QWidget *parent,QString Spielername1, QString Spielername2, QString Spielername3,QString Spielername4, int Anzahlspieler) :
    QWidget(parent),
    ui(new Ui::fenster)
{
    ui->setupUi(this);
    setWindowTitle("Memory");

    setFixedSize(1200,900);



    Spielerpaarelabel[0]= ui->Spieler1PaareAnzeige;
    Spielerpaarelabel[1]= ui->Spieler2PaareAnzeige;
    Spielerpaarelabel[2]= ui->Spieler3PaareAnzeige;
    Spielerpaarelabel[3]= ui->Spieler4PaareAnzeige;
    Spielerpaarelabel[0]->setText(QString::number(0));
    Spielerpaarelabel[1]->setText(QString::number(0));
    Spielerpaarelabel[2]->setText(QString::number(0));
    Spielerpaarelabel[3]->setText(QString::number(0));



    Reifen = new QPixmap;
    Reifen->load("C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/tyre.png");
    ui->ReifenLabel1->setPixmap(Reifen->scaled(100,100));
    ui->ReifenLabel1_2->setPixmap(Reifen->scaled(100,100));
    ui->ReifenLabel1_3->setPixmap(Reifen->scaled(100,100));
    ui->ReifenLabel1_4->setPixmap(Reifen->scaled(100,100));

    //importieren Lorbeerblat, welches erscheint wennt der Gewinner bekanntgegeben wird.
    LorBeerBlatt = new QPixmap;
    LorBeerBlatt->load("C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/lorbeer.png");
    ui->LorBeerBlattLabel->setPixmap(LorBeerBlatt->scaled(200,200));
    ui->LorBeerBlattLabel_3->setPixmap(LorBeerBlatt->scaled(200,200));
    ui->LorBeerBlattLabel->hide();
    ui->LorBeerBlattLabel_3->hide();




    //Hinzufügen des Hintergrunds des Spielfelds
    pix= new QPixmap;
    pix->load("C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/F1Background.jpg");
    ui->pic2_label->setPixmap(pix->scaled(1200,900)); //Skalieren

    anzahlspieler = Anzahlspieler;
    ui->GewinnerButton->hide();


    //Hintergrundmusik
    GameSound=new QMediaPlayer;
    audioOutput = new QAudioOutput;
    GameSound->setAudioOutput(audioOutput);
    connect(GameSound, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    GameSound->setSource(QUrl::fromLocalFile("C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/f1sound.mp3"));
    audioOutput->setVolume(50);
    GameSound->play();

    //Sound wenn ein Paar aufgedeckt wird.
    cashRegisterSound=new QMediaPlayer;
    audioOutput = new QAudioOutput;
    cashRegisterSound->setAudioOutput(audioOutput);
    connect(cashRegisterSound, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    cashRegisterSound->setSource(QUrl::fromLocalFile("C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/cashRegister.mp3"));
    audioOutput->setVolume(50);





    QString Spielerarray[4]; //Array mit den Spielernamen füllen
    Spielerarray[0]=Spielername1;
    Spielerarray[1]=Spielername2;
    Spielerarray[2]=Spielername3;
    Spielerarray[3]=Spielername4;

    //Die Displayanzeigen der SPielernamen festlegen
    ui->Spieler1NameAnzeige->setText(Spielername1);
    ui->Spieler2NameAnzeige->setText(Spielername2);
    ui->Spieler3NameAnzeige->setText(Spielername3);
    ui->Spieler4NameAnzeige->setText(Spielername4);

    //Nur so viele Spielernamen anzeigen wie auch tatsächlich spielen.
    if(anzahlspieler == 2){
        ui->Spieler3NameAnzeige->hide();
        ui->Spieler4NameAnzeige->hide();
        ui->Spieler3PaareAnzeige->hide();
        ui->Spieler4PaareAnzeige->hide();
    }
    else if (anzahlspieler == 3){
        ui->Spieler4NameAnzeige->hide();
        ui->Spieler4PaareAnzeige->hide();
    }


    ui->Spieler1NameAnzeige->setText(Spielername1);
    ui->Spieler2NameAnzeige->setText(Spielername2);
    ui->Spieler3NameAnzeige->setText(Spielername3);
    ui->Spieler4NameAnzeige->setText(Spielername4);


    //Die Liste wird mit der Anzahl der Spieler befüllt.
    for(int i=0; i<anzahlspieler;i++)
    {
        Spieler.addelement(Spielerarray[i]);
    }

    //Test für den Output der Spieler
    /*Spieler.output();
    qDebug()<< Spieler.getanzahlPaare();
    Spieler.nextelement();
    Spieler.erhöhePaare(); Spieler.erhöhePaare();
    Spieler.output();
    qDebug()<< Spieler.getanzahlPaare();*/





    //Spielfeld erstellen
    spielfeld = new QTableWidget(6,3,this);
    spielfeld->horizontalHeader()->hide();
    spielfeld->verticalHeader()->hide();
    spielfeld->setGeometry(370,2,400,600);

    //Gitternetz ausblenden
    spielfeld->setShowGrid(false);
    //die Blaue Auswahl deaktivieren
    spielfeld->setSelectionMode(QTableWidget::NoSelection);

    //die Höhe und Breite der Zellen setzen
    for (int zeile = 0; zeile < 6; zeile++)
        spielfeld->setRowHeight(zeile, 150);
    for (int spalte = 0; spalte < 3; spalte++)
        spielfeld->setColumnWidth(spalte, 150);

    //die Größe anpassen
    spielfeld->resize(455, 905);

    //Jetzt werden die Memorykarten erstellt
    int bildZaehler =0;

    //Das Array wird mit den erstellten Memorykarten gefüllt.
    for (int schleife = 0; schleife < 18; schleife++)
    {
        karten[schleife] = new memorykarte(Bildnamen[bildZaehler], bildZaehler);
        if ((schleife + 1) % 2 == 0)
            bildZaehler++;
    }

    //Das Array mit den Karten mischen. Karten müssen Random auf dem Spielfeld angeordnet sein.
    std::random_shuffle(std::begin(karten),std::end(karten));



    //die Größe der Icons/Spielkarten auf dem Spielfeld einstellen
    spielfeld->setIconSize(QSize(150,150));

    //die Karten in das Spielfeld einfügen.
    for (int zeile = 0; zeile < 6; zeile++)
           for (int spalte = 0; spalte < 3; spalte++)
           {
               spielfeld->setItem(zeile, spalte, karten[(spalte * 6) + zeile]);
           }


    //Wenn eine Karten im Spielfeld angeklickt wurde wird die funktion "zellegeklicktslot" ausfeführt.
    QObject::connect(spielfeld, SIGNAL(cellClicked(int,int)), this, SLOT(zellegeklicktslot(int,int)) );

    //Wird der Gewinnerbutton gedrückt, wird das Spiel beendet.
    QObject::connect(ui->GewinnerButton,&QPushButton::clicked, this, &fenster::close );


    //Timer. Wenn dieser  abgelaufen ist werden die Karten wieder umgedreht.
    KartenUmdrehen = new QTimer();
    KartenUmdrehen->setSingleShot(true);
    QObject::connect(KartenUmdrehen, &QTimer::timeout,this, &fenster::timerslot);


    //Ausführen der spiel funktion. Mit dieser wird auch das SPiel gestartet.
    spiel();
}



//Alle dynamische erstellten Variablen müssen wieder abgebaut werden.
fenster::~fenster()
{
    delete ui;
    delete Reifen;
    delete KartenUmdrehen;
    delete pix;
    delete GameSound;
    delete audioOutput;
    delete cashRegisterSound;
    delete spielfeld;
    delete LorBeerBlatt;


}

//Diese Funktion ist für den Ablauf des Spiels zuständig.
void fenster::spiel()
{
    if(ersterZug==true){
        qDebug()<< "Spieler" << Spieler.output() << "ist am der Reihe";
        ui->SpielerAmZugAnzeige_2->setText(Spieler.output());
    }

    else
    {
        //Wenn ein Paar aufgedeckt wurden, ertönt ein laut und der Spieler darf nochmal aufdecken.
        if(Paaraufgedeckt==true)
        {
            cashRegisterSound->play();

            if(Arraywert==anzahlspieler)
                Arraywert=0;

            Spieler.erhöhePaare();
            qDebug()<< "Spieler" << Spieler.output() << "nochmal" << Arraywert;
            ui->SpielerAmZugAnzeige_2->setText(Spieler.output());
            Spielerpaarelabel[Arraywert]->setText(QString::number(Spieler.getacutalPoints()));


        }

        else
        {
            //Sollte kein Paar aufgedeckt werden, gehen ein Element unserer Spielerliste weiter.
            Spieler.nextelement();
            qDebug()<< "Spieler" << Spieler.output() << "ist dran";
            ui->SpielerAmZugAnzeige_2->setText(Spieler.output());


            if(Arraywert==anzahlspieler-1)
                Arraywert=0;

            else
                Arraywert++;

        }
    }

    //Hier wird abgefragt ob das Spiel vorbei ist (alle Paare aufgedeckt). Wenn ja wird dies auf dem Display ausgegeben. Außerdem erscheint
    //ein Button, mit dem das Spiel beendet werden kann.
    if(PaareInsgesamt==9)
    {
        qDebug()<< "Spiel zu Ende. Gewonnen hat" << Spieler.getWinnername() << "mit" << Spieler.getHighestPoints() << "Paaren";
        ui->GewinnerButton->setText(Spieler.getWinnername());
        ui->GewinnerButton->show(); 
        GameSound->stop();
        spielfeld->hide();
        ui->LorBeerBlattLabel->show();
        ui->LorBeerBlattLabel_3->show();
        ui->SpielerAmZugAnzeige_2->hide();
        ui->SpielerAmZugAnzeige->hide();



    }
}



//Wenn Zelle im Spielfeld angeklickt wird
void fenster::zellegeklicktslot(int zeile, int spalte)
{


    //Ist die angeklickte Karten im SPiel, oder schon aufgedeckt, oder wurden schon 2 Karten aufgedeckt
    if(AnzahlUmgedrehteKarten<2 && karten[(spalte*6)+zeile]->NochimSpiel == true && karten[(spalte*6)+zeile]->KarteAufgedeckt == false && !KartenUmdrehen->isActive())
    {

    //Das passende Bild auswählen und als Icon anzeigen lassen.
    QString help = karten[(spalte*6)+zeile]->Bildnamen;
    karten[(spalte*6)+zeile]->setIcon(QIcon(QPixmap(help)));
    karten[(spalte*6)+zeile]->KarteAufgedeckt=true;
    AnzahlUmgedrehteKarten++;
    KartenaufdecktID[AnzahlUmgedrehteKarten-1].KartenID = karten[(spalte*6)+zeile]->KartenID;
    KartenaufdecktID[AnzahlUmgedrehteKarten-1].Positionmerken[AnzahlUmgedrehteKarten-1] = (spalte*6)+zeile;
    //qDebug()<< KartenaufdecktID[AnzahlUmgedrehteKarten-1].Positionmerken[AnzahlUmgedrehteKarten-1];
    ersterZug=false;
    }

    //Wenn beide Karten aufgedeckt wurden
    if(AnzahlUmgedrehteKarten==2)
    {
        AnzahlUmgedrehteKarten=0;

        //Haben beide Karten die gleich KardenID?
        if(KartenaufdecktID[0].KartenID==KartenaufdecktID[1].KartenID)
        {
            cashRegisterSound->stop();
            //KartenaufgedecktID wird nur mit negativen werten besetzt damit sie nicht in die if Bedingung gelangen
            KartenaufdecktID[0].KartenID=-1; KartenaufdecktID[1].KartenID=-2;
            Paaraufgedeckt = true;
            PaareInsgesamt++;
            //Die Karten müssen aus dem Spiel genommen werden. Können nun nicht mehr geöffnet werden.
            karten[KartenaufdecktID[0].Positionmerken[0]]->NochimSpiel = false;
            karten[KartenaufdecktID[1].Positionmerken[1]]->NochimSpiel = false;
            karten[KartenaufdecktID[0].Positionmerken[0]]->setIcon(QIcon(QPixmap("C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/hakengruen.jpg")));
            karten[KartenaufdecktID[1].Positionmerken[1]]->setIcon(QIcon(QPixmap("C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/hakengruen.jpg")));
        }

        //Beide Karten haben eine unterschiedliche ID. Also wieder umdrehen.
        else{
            Paaraufgedeckt=false;
            KartenUmdrehen->start(1500);
        }

    //Start des Spiels durch aufruf der Spiel funktion
    spiel();

    }


}

void fenster::timerslot(){
    //Test, Karten werden nach ablauf der Zeit wieder zum F1 logo zurückgedreht
    //karten[17]->setIcon(QIcon(QPixmap("C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/f1logo.png")));
    karten[KartenaufdecktID[0].Positionmerken[0]]->setIcon(QIcon(QPixmap("C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/f1logo.png")));
    karten[KartenaufdecktID[1].Positionmerken[1]]->setIcon(QIcon(QPixmap("C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/f1logo.png")));
    karten[KartenaufdecktID[0].Positionmerken[0]]->KarteAufgedeckt=false;
    karten[KartenaufdecktID[1].Positionmerken[1]]->KarteAufgedeckt=false;
}
