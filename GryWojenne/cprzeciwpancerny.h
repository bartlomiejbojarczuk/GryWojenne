#ifndef CPRZECIWPANCERNY_H
#define CPRZECIWPANCERNY_H

#include "cpocisk.h"

//!
/*!
 * \class CPrzeciwpancerny
 * \brief Klasa CPrzeciwpancerny reprezentuje pocisk, który jest w stanie razić jednostki typu CCzolg
 * Klasa opisuje parametry pocisku przeciwpancernego.
 */
class CPrzeciwpancerny: public CPocisk
{
public:
    //! Implementacja metoda wirtualnej zwracającej liczbę obrażeń zadawanych przez pocisk
    /*!
     * \return liczbę zadawanych obrażeń
     */
    int obrazenia();

    //! Konstruktor klasy CPrzeciwpancerny
    /*!
     */
    CPrzeciwpancerny();
};

#endif // CPRZECIWPANCERNY_H
