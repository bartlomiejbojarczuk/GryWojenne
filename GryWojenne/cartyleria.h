#ifndef CARTYLERIA_H
#define CARTYLERIA_H

#include "cjednostka.h"





class CArtyleria : public CJednostka
{
public:
    CArtyleria();
    ~CArtyleria();
    CArtyleria(QString strona_konfliktu);
    void atakuj();
    int ruch();
    int losowy_ruch();
private:
    void zdarzenie(double wylosowano);
    int amunicja;
    void dostawa_amunicji();
    void wybuch_w_skladzie_amunicji();





};
#endif // CARTYLERIA_H
