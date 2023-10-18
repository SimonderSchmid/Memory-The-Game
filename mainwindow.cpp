#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPixmap>
#include <QDebug>
#include <QDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Memory");
    setFixedSize(600,600); //Feste fenstergröße
    connect(ui->button, SIGNAL(clicked()), this, SLOT(openSecondWindow())); //Öffnen des Spielfenster durch Button Klick


    //Hinzufügen des Hintergrunds für den Startbildschirm
    QPixmap pix("C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/Background2.jpg");
    ui->pic1_label->setPixmap(pix.scaled(600,600)); //Skalieren

    //Main Title
    QPixmap pix2("C:/Users/sidam/OneDrive - bwedu/Studium/MenschMaschine/Memory/Title.png");
    ui->pic2_label->setPixmap(pix2.scaled(600,300));






}

MainWindow::~MainWindow()
{
    delete ui;
    delete Regeldialog;

}

void MainWindow::openSecondWindow()
{

    //In dieser Funktion wird geprüft ob in jeder Eingabe ein Name eingegeben worden ist.
    //Die Anzahl Namen muss mit der Anzahl von der Auswahl des Radiobuttons übereinstimmen.
    if(Anzahlspieler==2)
    {
    if(Spielername2.size()!=0 && Spielername1.size()!=0)
        {
            f = new fenster(nullptr,Spielername1,Spielername2,Spielername3,Spielername4, Anzahlspieler);     //Öffnen des Spielfensters
            f->show();
        }
    }

    if(Anzahlspieler==3)
    {
    if(Spielername2.size()!=0 && Spielername1.size()!=0 && Spielername3.size()!=0)
        {
            fenster *f = new fenster(nullptr,Spielername1,Spielername2,Spielername3,Spielername4, Anzahlspieler);     //Öffnen des Spielfensters
            f->show();
        }
    }

    if(Anzahlspieler==4)
    {
    if(Spielername2.size()!=0 && Spielername1.size()!=0 && Spielername3.size()!=0 && Spielername4.size()!=0)
        {
            fenster *f = new fenster(nullptr,Spielername1,Spielername2,Spielername3,Spielername4, Anzahlspieler);     //Öffnen des Spielfensters
            f->show();
        }
    }

}




void MainWindow::on_actionSpielregeln_triggered() //Wenn Spielregeln gedrückt dann Dialog mit SPielregeln öffnen
{

    Regeldialog = new QDialog;
    Regeldialog->setModal(true);
        Regeldialog->setWindowTitle("Spielregeln");
    Regeldialog->setFixedSize(480,500);
    Form.setupUi(Regeldialog);
    Regeldialog->show();

}

//Man wählt die Anzahl der Spieler aus, entweder 2,3 oder4.  Je nachdem werden dann die Eingabefelder eneabled.
void MainWindow::on_radioButton_2Spieler_clicked()
{
    ui->Spielereingabe1->setEnabled(true);
    ui->Spielereingabe2->setEnabled(true);
    ui->Spielereingabe3->setEnabled(false);
    ui->Spielereingabe4->setEnabled(false);
    Anzahlspieler = 2;
}


void MainWindow::on_radioButton_3Spieler_clicked()
{
    ui->Spielereingabe1->setEnabled(true);
    ui->Spielereingabe2->setEnabled(true);
    ui->Spielereingabe3->setEnabled(true);
    ui->Spielereingabe4->setEnabled(false);
        Anzahlspieler = 3;
}


void MainWindow::on_radioButton_4Spieler_clicked()
{
    ui->Spielereingabe1->setEnabled(true);
    ui->Spielereingabe2->setEnabled(true);
    ui->Spielereingabe3->setEnabled(true);
    ui->Spielereingabe4->setEnabled(true);
        Anzahlspieler = 4;
}



void MainWindow::on_Spielereingabe1_textChanged(const QString &arg1) //Speichert den Spielernamen ab
{
    Spielername1 = arg1;
    //qDebug() << Spielername1;
}


void MainWindow::on_Spielereingabe2_textChanged(const QString &arg1) //Speichert den Spielernamen ab
{
    Spielername2 = arg1;
    //qDebug() << Spielername2;
}


void MainWindow::on_Spielereingabe3_textChanged(const QString &arg1)//Speichert den Spielernamen ab
{
    Spielername3 = arg1;
    //qDebug() << Spielername3;
}


void MainWindow::on_Spielereingabe4_textChanged(const QString &arg1)//Speichert den Spielernamen ab
{
    Spielername4 = arg1;
    //qDebug() << Spielername4;
}

