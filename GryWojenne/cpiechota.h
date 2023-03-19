#ifndef CPIECHOTA_H
#define CPIECHOTA_H

#include "cjednostka.h"

class CPiechota : public CJednostka
{
public:
    CPiechota ();
    CPiechota (QString strona_konfliktu);
    ~CPiechota();
    void zdarzenie(double wylosowano){};

private:
    int morale;
    bool panika;
    //void atakuj ();
    //int ruch();
    //int losowy_ruch();
    void uciekaj();
    void jakie_morale();
    void choroba();
    void zachoruj();
    int ile_czolgow(std::vector<CJednostka *> oddzial);
    int ile_armat(std::vector<CJednostka *> oddzial);
    bool zdrowy;

};

#endif // CPIECHOTA_H
