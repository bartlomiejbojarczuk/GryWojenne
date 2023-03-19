#ifndef CTEREN_H
#define CTEREN_H

#include <QString>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "cprzeszkoda.h"

class CTeren
{
public:
    CTeren();
    int getTrudnosc();
    std::vector<CPrzeszkoda *> getPrzeszkody();
protected:
    std::vector<CPrzeszkoda*> przeszkody;
    int trudnosc;
    double losuj (int Od, int Do);
    virtual void update_teren(){};
    virtual void blokuj() {};
private:

};

#endif // CTEREN_H
