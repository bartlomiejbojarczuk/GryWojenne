#include "cpustynia.h"

CPustynia::CPustynia()
{
    this->trudnosc=2;
}

void CPustynia::tworz_wydme()
{
        int x1=losuj(0,500);
        int x2=losuj(0,500);
        int y1=losuj(0,500);
        int y2=losuj(0,500);



        przeszkody.push_back(new CPrzeszkoda("wydma",abs(x2-x1),abs(y2-y1),(x2+x1)/2,(y1+y2)/2));


}

void CPustynia::przeszkodz(double wylosowano)
{
    tworz_wydme();
}








