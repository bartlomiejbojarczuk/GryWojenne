#ifndef CCZYNNIK_LOSOWY_H
#define CCZYNNIK_LOSOWY_H
#include <QDebug>
#include<cstdlib>
#include<ctime>
#include "cjednostka.h"
#include "cteren.h"

class CCzynnik_losowy
{
public:
    CCzynnik_losowy();
    void losuj_czynnik_pogodowy();
    void losuj_czynnik_losowy(std::vector<CJednostka*> &jednostki, CTeren * teren);
protected:
    int numer;

};


#endif // CCZYNNIK_LOSOWY_H
