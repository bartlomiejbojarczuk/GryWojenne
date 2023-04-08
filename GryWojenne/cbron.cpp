#include "cbron.h"
#include "cpocisk.h"

CBron::CBron()
{

}

bool CBron::czy_zastrzele(QString kto, QString do_kogo)
{

    if(kto=="Żołnierz")
    {
        if(do_kogo=="Żołnierz" || do_kogo=="Armata")
            return true;
    }


    if(kto=="Armata")
        return true;
    if(kto=="Czolg")
        if(do_kogo=="Samolot")
            return false;
    if(kto=="Samolot" && do_kogo=="Samolot")
        return false;
    return true;

}

void CBron::strzel(QString kto, QString do_kogo)
{
    if(czy_zastrzele(kto,do_kogo))
    {
        if(do_kogo=="Żołnierz")
            pocisk=new CZwykly;
        if(do_kogo=="Czolg" || do_kogo=="Armata")
            pocisk=new CPrzeciwpancerny;
        if(do_kogo=="Samolot")
                pocisk=new CPrzeciwlotniczy;
        suma_obrazen=pocisk->obrazenia();
    }
    else
        suma_obrazen=0;
}








