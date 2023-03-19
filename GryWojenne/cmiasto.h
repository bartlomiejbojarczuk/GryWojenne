#ifndef CMIASTO_H
#define CMIASTO_H

#include "cteren.h"

class CMiasto : public CTeren
{
public:
    CMiasto();
    void przeszkodz(double wylosowano);

private:
    void tworz_wiezowiec();
    bool wybudowano;
};

#endif // CMIASTO_H
