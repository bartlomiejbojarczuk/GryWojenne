#ifndef CPUSTYNIA_H
#define CPUSTYNIA_H
#include <vector>
#include <QString>

#include "cteren.h"

class CPustynia : public CTeren
{
public:
    CPustynia();

    void przeszkodz(double wylosowano);

private:
    void tworz_wydme();
};


#endif // CPUSTYNIA_H
