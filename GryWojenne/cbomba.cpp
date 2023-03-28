#include "cbomba.h"

CBomba::CBomba()
{
    this->masa_trotylu=500;
    this->sila_razenia=100;
}

int CBomba::obrazenia()
{
    return masa_trotylu/100+sila_razenia/10;
}
