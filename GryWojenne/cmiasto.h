#ifndef CMIASTO_H
#define CMIASTO_H

#include "cteren.h"

class CMiasto : public CTeren
{
public:
    //! Konstruktor klasy CMiasto
    /*!
     */
    CMiasto();

    //! Destruktor klasy CMiasto
    /*!
     */
    ~CMiasto();

    //! Metoda wprowadzająca do rozgrywki czynnik losowy wynikający z terenu - Miasto
    /*!
     *
     */
    void przeszkodz(double wylosowano);

private:

    //! Metoda wprowadzająca do rozgrywki czynnik losowy w postaci utworzenia wieżowca
    /*!
     *
     */
    void tworz_wiezowiec();
    bool wybudowano; //!< parametr przechowujący informację czy na terenie Miasta wybudowano wieżowiec
};

#endif // CMIASTO_H
