#include "cczolg.h"
#include <QDebug>

CCzolg::CCzolg(){

}

CCzolg::~CCzolg()
{
qDebug()<<"Destruktor czołg!";
}

void CCzolg::zdarzenie(double wylosowano)
{   if(wylosowano>5)
    uszkodzenie_armaty();

}


CCzolg::CCzolg(QString strona_konfliktu)
{
    this->doswiadczenie=1;
    this->mobilnosc=25;
    this->pancerz=50;
    this->nazwa="Czolg";
    this->sila_ataku=30;
    this->szybkosc=200;
    this->wytrzymalosc=250;
    this->zasieg=75;
    this->zycie=500;
    this->PozycjaX=50;
    this->PozycjaY=50;
    this->zapas_paliwa=100;
    this->frakcja=strona_konfliktu;


}


void CCzolg::atakuj () {

    qDebug()<<"Czolg atakuje";
    if(!mam_kogo_atakowac()){
         qDebug()<<"CZOLG !mam kogo atakować";
         znajdz_jednostke(wrogowie);
         qDebug()<<"CZOLG Znalazłem cel:" <<jednostka_do_ataku->getNazwa();
    }

    if(in_range(jednostka_do_ataku))
    {   qDebug()<<"Czolg sprawdza zasieg: ";
        strzal();
        qDebug()<<" CZOLG wystrzeliłem";}
    else
    {   if(sprawny){
                qDebug()<<" CZOLG jestem sprawny, bede jechał";
        przemiesc_sie();
        zapas_paliwa-=10;
            qDebug()<<"CZOLG Jestem coraz bliżej ";
            }
    }
}

int CCzolg::ruch()
{
    if(zapas_paliwa>0){
        return szybkosc*mobilnosc/100;
    }
    else return 0;
}


int CCzolg::losowy_ruch()
{
     if(zapas_paliwa>0)
         return losuj(0,szybkosc*mobilnosc/100);
}

void CCzolg::uszkodzenie_armaty()
{   if(sprawny){
    this->sprawny=0;
    message+=this->nazwa+" "+this->frakcja+" uszkodził gąsiennice \n";
}}

