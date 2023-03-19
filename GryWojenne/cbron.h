#ifndef CBRON_H
#define CBRON_H

#include <QString>

#include "cpocisk.h"

class CBron
{
public:
    CBron();
    ~CBron();
    void strzel(QString kto, QString do_kogo);
    bool czy_zastrzele(QString czym, QString do_kogo);
    int suma_obrazen;
    CPocisk* pocisk;


};

#endif // CBRON_H
