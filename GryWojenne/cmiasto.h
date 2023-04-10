#ifndef CMIASTO_H
#define CMIASTO_H

#include "cteren.h"

//!
/*!
 * \class CMiasto
 * \brief reprezentuje teren w postaci Miasta, na którym rozgrywana jest potyczka
 *  Klasa pochodna po klasie CTeren, która reprezentuje Teren typu Miasto, metoda implementuje wirtualne metody klasy CTeren wykorzystując wartości charakterystyczne dla tego typu terenu.
 */
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
