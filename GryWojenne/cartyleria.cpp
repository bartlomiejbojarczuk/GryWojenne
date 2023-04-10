#include "cartyleria.h"
#include <QDebug>
#include <cstdlib>
#include <ctime>


CArtyleria::CArtyleria(){

}

CArtyleria::~CArtyleria()
{
    qDebug()<<"Destruktor armata";
}

CArtyleria::CArtyleria(QString strona_konfliktu)
{
    this->doswiadczenie=1;
    this->mobilnosc=50;
    this->pancerz=10;
    this->nazwa="Armata";
    this->sila_ataku=500;
    this->wytrzymalosc=100;
    this->zasieg=400;
    this->zycie=500;
    this->PozycjaX=50;
    this->PozycjaY=50;
    this->frakcja=strona_konfliktu;
    this->amunicja=10;

}



void CArtyleria::atakuj(){


    if(!mam_kogo_atakowac()){
        qDebug()<<"!mam kogo atakować";
         znajdz_jednostke(wrogowie);
    }

    if(in_range(jednostka_do_ataku))
       {
        qDebug()<<"Artyleria sprawdza zasieg: ";
        if(amunicja>0)
    {
        strzal();
        amunicja--;}
}
}


void CArtyleria::dostawa_amunicji()
{
    amunicja+=10;

}

void CArtyleria::wybuch_w_skladzie_amunicji()
{
    amunicja=0;
    zycie=0;
    death=1;
    kto_w_zasiegu(75);
    for(int i=0;i<w_zasiegu.size();i++)
        w_zasiegu[i]->odejmij_zycie(100);
}


int CArtyleria::ruch(){

}
int CArtyleria::losowy_ruch(){

}

void CArtyleria::zdarzenie(double wylosowano)
{
    if(wylosowano<5){
        dostawa_amunicji();
        message+=this->nazwa+" "+this->frakcja+" otrzymała dodatkową amunicję \n";
    }
    else{
        wybuch_w_skladzie_amunicji();
        message+="Amunicja w składzie: "+this->nazwa+" "+this->frakcja+" eksplodowała\n";
    }

}
