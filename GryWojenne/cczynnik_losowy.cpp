#include "cczynnik_losowy.h"


CCzynnik_losowy::CCzynnik_losowy()
{

}

void CCzynnik_losowy::losuj_czynnik_losowy(std::vector<CJednostka *> &jednostki, CTeren * teren)
{
        int Od=0;
        int Do=10;
        srand(time(NULL));
        double losowanie=((rand()%(Do-Od))+Od);

        if(losowanie==4 || losowanie==7)
            teren->przeszkodz(losowanie);
        else
        {
         int i=rand()%jednostki.size();
            jednostki[i]->zdarzenie(losowanie);
         }

}


