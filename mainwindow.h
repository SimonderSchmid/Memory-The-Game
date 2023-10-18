#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_Regeln.h"
#include <QMainWindow>
#include "spieler.h"
#include "fenster.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    fenster *f;





private:
    Ui::MainWindow *ui;

    QString Spielername1="";
    QString Spielername2="";
    QString Spielername3="";
    QString Spielername4="";
    int Anzahlspieler = 0;


    QDialog *Regeldialog; //Für den QDialog mit den Spielregeln
    Ui::Form Form;        //Für den QDialog mit den Spielregeln




public slots:
    void openSecondWindow();
private slots:
    void on_Spielereingabe1_textChanged(const QString &arg1);

    void on_actionSpielregeln_triggered(); //Wenn Spielregeln gedrückt dann Dialog mit SPielregeln öffnen
    void on_radioButton_2Spieler_clicked();
    void on_radioButton_3Spieler_clicked();
    void on_radioButton_4Spieler_clicked();
    void on_Spielereingabe2_textChanged(const QString &arg1);
    void on_Spielereingabe3_textChanged(const QString &arg1);
    void on_Spielereingabe4_textChanged(const QString &arg1);
};
#endif // MAINWINDOW_H
