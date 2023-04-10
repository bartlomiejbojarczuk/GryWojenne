#ifndef CZWYKLY_H
#define CZWYKLY_H

#include "cpocisk.h"

//!
/*!
 * \class CZwykly
 * \brief Klasa CZwykly reprezentuje pocisk wystrzeliwany przez jednostkę typu CPiechota
 * Klasa reprezentuje pocisk wystrzeliwany przez obiekty typu CPiechota, klasa opisuje parametry pocisku.
 */
class CZwykly : public CPocisk
{
public:
    //! Implementacja metoda wirtualnej zwracającej liczbę obrażeń zadawanych przez pocisk
    /*!
     * \return liczbę zadawanych obrażeń
     */
    int obrazenia();

    //! Konstruktor klasy CZwykly
    /*!
     */
    CZwykly();
};

#endif // CZWYKLY_H
