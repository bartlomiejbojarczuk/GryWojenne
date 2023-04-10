#ifndef CPRZECIWLOTNICZY_H
#define CPRZECIWLOTNICZY_H

#include "cpocisk.h"

//!
/*!
 * \class CPrzeciwlotniczy
 * \brief Klasa opisuje parametry pocisku przeciwlotniczy.
 * Klasa CPrzeciwlotniczy reprezentuje pocisk, który jest w stanie razić jednostki typu CLotnictwo
 */
class CPrzeciwlotniczy : public CPocisk
{
public:
    //! Konstruktor klasy CPrzeciwlotniczy
    /*!
     */
    CPrzeciwlotniczy();

    //! Implementacja metoda wirtualnej zwracającej liczbę obrażeń zadawanych przez pocisk
    /*!
     * \return liczbę zadawanych obrażeń
     */
    int obrazenia();

};

#endif // CPRZECIWLOTNICZY_H
