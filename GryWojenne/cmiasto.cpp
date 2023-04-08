#include "cmiasto.h"

CMiasto::CMiasto()
{
    this->trudnosc=1;
    this->wybudowano=0;
}


void CMiasto::tworz_wiezowiec()
{
        int x1=losuj(0,500);
        int x2=losuj(0,500);
        int y1=losuj(0,500);
        int y2=losuj(0,500);



        przeszkody.push_back(new CPrzeszkoda("wiezowiec",abs(x2-x1),abs(y2-y1),(x2+x1)/2,(y1+y2)/2));
        this->wybudowano=1;


}
void CMiasto::przeszkodz(double wylosowano)
{
tworz_wiezowiec();
}
