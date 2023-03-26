#ifndef CJEDNOSTKA_H
#define CJEDNOSTKA_H

#include <QString>
#include <QDebug>

#include "cprzeszkoda.h"

class CJednostka
{


public:
    CJednostka();
    virtual ~CJednostka();
    //virtuint silal ~CJednostka();
    virtual void atakuj (){};
    virtual void zdarzenie(double wylosowano){};
    virtual void odejmij_zycie(int ile){};


    void umrzyj();

    QString getNazwa();
    QString getMessage();
    void setMessage(QString tekst);
    QString getFrakcja();
    void setFrakcja(QString strona_konfliktu);

    void setPozycjaX(int x);
    int getPozycjaX();

    void setPozycjaY(int y);
    int getPozycjaY();

    void setWrogowie(std::vector<CJednostka*> jednostki);
    void setSwoi(std::vector<CJednostka*> jednostki);
    void setPrzeszkody(std::vector<CPrzeszkoda*> przeszkody);

    void setJednostkadoAtaku();

    bool getDeath();

    void kto_w_zasiegu(int zas);
    void awansuj();


protected:

    double licz_odleglosc(CJednostka* enemy);
    void znajdz_jednostke(std::vector<CJednostka*> jednostki_wroga);
    void przemiesc_sie();
    virtual int ruch(){};
    virtual int losowy_ruch(){};
    bool moge_zajac_miejsce(int x, int y);
    double losuj(int Od, int Do);
    void strzal();
    bool mam_kogo_atakowac();
    bool in_range(CJednostka* jednostka_do_ataku);
    virtual int punkty_ataku() {};
    virtual int punkty_obrony() {} ;



    QString nazwa;
    QString message;
    QString frakcja;
    int pancerz;
    int sila_ataku;
    int zasieg;
    int doswiadczenie;
    int wytrzymalosc;
    int zycie;
    int szybkosc;
    int mobilnosc;
    int PozycjaX;
    int PozycjaY;
    bool death=false;
    CJednostka* jednostka_do_ataku=NULL;
    std::vector<CJednostka*> wrogowie;
    std::vector<CJednostka*> swoi;
    std::vector<CJednostka*> w_zasiegu;
    std::vector<CPrzeszkoda*> przeszkody;



};

#endif // CJEDNOSTKA_H
