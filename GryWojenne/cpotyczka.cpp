#include "cpotyczka.h"

CPotyczka::CPotyczka()
{
    this->okno_potyczki=new battlewindow;
    okno_potyczki->show();
    qDebug()<<"Potyczka created";
}

CPotyczka::~CPotyczka()
{
}
std::vector<CJednostka *> CPotyczka::getJednostki_ISIS() const{

    return jednostki_ISIS;
}

std::vector<CJednostka *> CPotyczka::getJednostki_NATO() const{
    return jednostki_NATO;
}
