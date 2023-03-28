#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <qglobal.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::randomize(int low, int high)
{
    return rand()%((high+1)-low)+low;
}

void MainWindow::on_wyjscie_clicked()
{
    exit (1);
}


void MainWindow::on_Rozpocznij_potyczke_clicked()
{
    if(sprawdz()){
    qDebug()<<"Przycisk Rozpocznij";
    CPotyczka *potyczka=new CPotyczka;
    potyczka->tworz_oddzial(dodane_jednostki_ISIS,"ISIS");
    qDebug()<<"Stworzono oddzial ISIS: "<<jednostki_ISIS_String;
    potyczka->tworz_oddzial(dodane_jednostki_NATO,"NATO");
    qDebug()<<"Stworzono oddzial NATAO: "<<jednostki_NATO_String;
    potyczka->teren_walk=daj_teren();

}
}

CTeren* MainWindow::daj_teren(){
        CTeren* Teren;
        QString teren=ui->comboBox_3->currentText();
        if(teren=="Pustynia")
           Teren=new CPustynia;
        if(teren=="Miasto")
           Teren=new CMiasto;
        return Teren;
}

void MainWindow::on_dodaj_jednostke_Button_clicked()
{
    QString jednostka=ui->comboBox_2->currentText();
    QString frakcja=ui->comboBox->currentText();
    int ile=ui->spinBox->value();

    if(frakcja=="ISIS"){

        for(int j=1;j<=ile;j++){
        dodane_jednostki_ISIS.push_back(jednostka);
        jednostki_ISIS_String=jednostki_ISIS_String+jednostka+"\n";
        }
            ui->textBrowser_2->setText(jednostki_ISIS_String);
            ile_jednostek_ISIS+=ile;
        }

        else{
        for(int j=1;j<=ile;j++){
        dodane_jednostki_NATO.push_back(jednostka);
        jednostki_NATO_String=jednostki_NATO_String+jednostka+"\n";
        }
            ui->textBrowser->setText(jednostki_NATO_String);
            ile_jednostek_NATO+=ile;
        }


}


void MainWindow::on_LosujButton_clicked()
{
    {
        on_kasuj_oddzialy_clicked();

        int liczebnosc_ISIS=randomize(1,5);
        int liczebnosc_NATO=randomize(1,5);
        ile_jednostek_ISIS=0;
        ile_jednostek_NATO=0;
        for(int i=0;i<liczebnosc_ISIS;i++)
        {
            int k=randomize(1,3);
            switch (k) {
            case 1:
                dodane_jednostki_ISIS.push_back("Piechota");
                jednostki_ISIS_String=jednostki_ISIS_String+"Piechota"+"\n";
                break;
            case 2:
                dodane_jednostki_ISIS.push_back("Artyleria");
                jednostki_ISIS_String=jednostki_ISIS_String+"Artyleria"+"\n";
                break;
            case 3:
                dodane_jednostki_ISIS.push_back("Czolg");
                jednostki_ISIS_String=jednostki_ISIS_String+"Czolg"+"\n";
                break;
            case 4:
                dodane_jednostki_ISIS.push_back("Lotnictwo");
                jednostki_ISIS_String=jednostki_ISIS_String+"Lotnictwo"+"\n";
                break;
            }
            ile_jednostek_ISIS++;
        }

        for(int i=0;i<liczebnosc_NATO;i++)
        {
            int k=randomize(1,3);
            switch (k) {
            case 1:
                dodane_jednostki_NATO.push_back("Piechota");
                jednostki_NATO_String=jednostki_NATO_String+"Piechota"+"\n";
                break;
            case 2:
                dodane_jednostki_NATO.push_back("Artyleria");
                jednostki_NATO_String=jednostki_NATO_String+"Artyleria"+"\n";
                break;
            case 3:
                dodane_jednostki_NATO.push_back("Czolg");
                jednostki_NATO_String=jednostki_NATO_String+"Czolg"+"\n";
                break;
            case 4:
                dodane_jednostki_NATO.push_back("Lotnictwo");
                jednostki_NATO_String=jednostki_NATO_String+"Lotnictwo"+"\n";
                break;
            }

            ile_jednostek_NATO++;
        }
    ui->textBrowser->setText(jednostki_NATO_String);
    ui->textBrowser_2->setText(jednostki_ISIS_String);

    }

}


void MainWindow::on_kasuj_oddzialy_clicked()
{
    ui->textBrowser->clear();
    ui->textBrowser_2->clear();
    dodane_jednostki_ISIS.clear();
    dodane_jednostki_NATO.clear();
    jednostki_ISIS_String="";
    jednostki_NATO_String="";
    ile_jednostek_ISIS=0;
    ile_jednostek_NATO=0;

}


bool MainWindow::sprawdz(){
    if(ile_jednostek_ISIS>5 ||  ile_jednostek_NATO>5)
    {
        msgBox.setWindowTitle("UWAGA!");
        msgBox.setInformativeText("Liczba jednostek w oddziale powinna wynosić nie więcej niż 5!");
        msgBox.exec();
        on_kasuj_oddzialy_clicked();
        return 0;

    }
    if(ile_jednostek_ISIS==0 ||  ile_jednostek_NATO==0)
    {
        msgBox.setWindowTitle("UWAGA!");
        msgBox.setInformativeText("Oddział nie może być pusty!");
        msgBox.exec();
        on_kasuj_oddzialy_clicked();
        return 0;

    }
    return 1;
}

