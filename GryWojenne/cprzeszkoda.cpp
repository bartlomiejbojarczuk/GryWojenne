#include "cprzeszkoda.h"

CPrzeszkoda::CPrzeszkoda()
{

}
CPrzeszkoda::CPrzeszkoda(QString co, int szer, int wys, int x, int y){
    this->nazwa=co;
    this->szerokosc=szer;
    this->wysokosc=wys;
    this->Posx=x;
    this->Posy=y;
}

int CPrzeszkoda::getPosx()
{
    return Posx;
}

int CPrzeszkoda::getPosy(){
    return Posy;
}

QString CPrzeszkoda::getNazwa(){
    return nazwa;
}

int CPrzeszkoda::getSzerokosc(){
    return szerokosc;
}

int CPrzeszkoda::getWysokosc(){
    return wysokosc;
}
