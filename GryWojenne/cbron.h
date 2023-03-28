#ifndef CBRON_H
#define CBRON_H
#include <QString>
#include "cpocisk.h"
#include "czwykly.h"
#include "cprzeciwlotniczy.h"
#include "cprzeciwpancerny.h"
#include "cbomba.h"

class CBron
{
public:
    CBron();
    ~CBron();
    void strzel(QString kto, QString do_kogo);
    bool czy_zastzele(QString czym, QString do_kogo);
    int suma_obrazen;
    CPocisk* pocisk;


};

#endif // CBRON_H
