#include "cteren.h"



CTeren::CTeren()
{

}
double CTeren::losuj(int Od, int Do){
    srand(time(NULL));
    int zakres=Do-Od;
    double losowanie=((rand()%zakres)+Od);
    return losowanie;
}

std::vector<CPrzeszkoda *> CTeren::getPrzeszkody(){
    return przeszkody;
}
