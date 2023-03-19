#ifndef CPRZESZKODA_H
#define CPRZESZKODA_H

#include <QString>

class CPrzeszkoda
{
public:
    CPrzeszkoda();
    CPrzeszkoda(QString co, int szer, int wys, int x, int y);
    int getPosx();
    int getPosy();
    int getSzerokosc();
    int getWysokosc();
    QString getNazwa();
private:
    QString nazwa;
    int Posx;
    int Posy;
    int szerokosc;
    int wysokosc;
};

#endif // CPRZESZKODA_H
