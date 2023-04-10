#include "cpiechota.h"

#include <QDebug>

CPiechota::CPiechota(QString strona_konfliktu)
{
    this->doswiadczenie=1;
    this->mobilnosc=50;
    this->morale=100;
    this->pancerz=2;
    this->nazwa="Żołnierz";
    this->sila_ataku=50;
    this->szybkosc=50;
    this->wytrzymalosc=20;
    this->zasieg=25;
    this->zycie=50;
    this->PozycjaX=0;
    this->PozycjaY=0;
    this->frakcja=strona_konfliktu;
    this->zdrowy=true;
    this->panika=false;

}

CPiechota::~CPiechota(){

qDebug()<<"Destruktor piechota!";
}

void CPiechota::zdarzenie(double wylosowano)
{   qDebug()<<"Zdarzenie Piechota";
    if(wylosowano<5 && wylosowano>2)
        choroba();
    else
        if (zdrowy && wylosowano>7)
        otruj();
}

void CPiechota::atakuj(){
    if(!zdrowy)
        zycie-=10;
    if(!mam_kogo_atakowac()){
         znajdz_jednostke(wrogowie);
    }

    if(panika)
        uciekaj();

    else{
    jakie_morale();
    if(in_range(jednostka_do_ataku))
    {   qDebug()<<"Piechota sprawdza zasieg: ";
        strzal();}
    else
        przemiesc_sie();}

}


int CPiechota::ruch()
{

        return szybkosc*mobilnosc/100;

}


int CPiechota::losowy_ruch()
{

    return losuj(0,szybkosc*mobilnosc/100);
}

void CPiechota::uciekaj()
{   int PosX,PosY;


     do{
        PosX=this->PozycjaX-losowy_ruch();
        PosY=this->PozycjaY+losowy_ruch();
    } while (!moge_zajac_miejsce(PosX,PosY)) ;

    this->PozycjaX=PosX;
    this->PozycjaY=PosY;
}

void CPiechota::jakie_morale()
{
    double losowanie=losuj(0,10);
    int roznica_liczebnosci=this->wrogowie.size()-this->swoi.size();
       this->morale-=roznica_liczebnosci*5;
    if(this->morale<100)
        this->morale+=roznica_liczebnosci*10;
    if(ile_czolgow(this->swoi)+ile_czolgow(this->wrogowie)>3)
        this->morale-=15;
    if(ile_armat(this->swoi)+ile_armat(this->wrogowie)>2)
        this->morale-=10;

    if(this->morale<50)
        if(losowanie<4)
           this->panika=true;

    if(this->morale<20)
            this->panika=true;

    if(this->panika)
        this->message+=this->nazwa+" "+this->frakcja+" spanikował! \n";
}

void CPiechota::choroba()
{
    this->zycie=0;
    this->death=1;
    this->message+=this->nazwa+" "+this->frakcja+" zaraził się dyzenterią \n";
}

void CPiechota::otruj()
{
    this->zdrowy=0;
    this->message+=this->nazwa+" "+this->frakcja+" został otruty \n";
}

int CPiechota::ile_czolgow(std::vector<CJednostka *> oddzial)
{
    int czolgi=0;
    for(int i=0;i<oddzial.size();i++)
       { if(oddzial[i]->getNazwa()=="Czolg")
            czolgi++;}
    return czolgi;
}

int CPiechota::ile_armat(std::vector<CJednostka*> oddzial)
{
    int armaty=0;
    for(int i=0;i<oddzial.size();i++)
    {if(oddzial[i]->getNazwa()=="Armata")
            armaty++;}
    return armaty;
}
