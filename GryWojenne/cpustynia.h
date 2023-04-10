#ifndef CPUSTYNIA_H
#define CPUSTYNIA_H
#include <vector>
#include <QString>

#include "cteren.h"

//!
/*!
 * \class CPustynia
 * \brief Klasa  reprezentuje teren w postaci Pustyni, na którym rozgrywana jest potyczka
 * Klasa pochodna po klasie CTeren, która reprezentuje Teren typu Pustynia, metoda implementuje wirtualne metody klasy CTeren wykorzystując wartości charakterystyczne dla tego typu terenu.
 */
class CPustynia : public CTeren
{
public:
    //! Konstruktor klasy CPustynia
    /*!
     */
    CPustynia();

    //! Metoda wprowadzająca do rozgrywki czynnik losowy wynikający z terenu - Pustynia
    /*!
     *
     */
    void przeszkodz(double wylosowano);

private:

    //! Metoda wprowadzająca do rozgrywki czynnik losowy w postaci utworzenia wydmy
    /*!
     *
     */
    void tworz_wydme();
};


#endif // CPUSTYNIA_H
