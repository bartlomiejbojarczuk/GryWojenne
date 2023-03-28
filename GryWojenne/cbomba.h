#ifndef CBOMBA_H
#define CBOMBA_H

#include "cpocisk.h"

class CBomba : public CPocisk
{
public:
    CBomba();
    int obrazenia();
private:
    int masa_trotylu;

};

#endif // CBOMBA_H
