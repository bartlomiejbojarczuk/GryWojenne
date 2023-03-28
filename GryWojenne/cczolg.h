#ifndef CCZOLG_H
#define CCZOLG_H

#include "cjednostka.h"
#include <QDebug>

class CCzolg : public CJednostka
{
public:
    CCzolg(QString strona_konfliktu);
    CCzolg();
   ~CCzolg();
    void zdarzenie(double wylosowano);

    void atakuj ();
 private:
    int zapas_paliwa;
    int ruch();
    int losowy_ruch();
    bool sprawny=true;
    void uszkodzenie_armaty();

};

#endif // CCZOLG_H
