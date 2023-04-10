#ifndef CCZYNNIK_LOSOWY_H
#define CCZYNNIK_LOSOWY_H
#include <QDebug>
#include<cstdlib>
#include<ctime>
#include "cjednostka.h"
#include "cteren.h"

//!
/*!
 * \class CCzynnik_losowy
 * \brief Opisuje zdarzenia losowe, które mogą się pojawić w trakcie trwania potyczki
 * Klasa implementuje metody i parametry związane ze zdarzeniami losowymi, które mogą się pojawić w trakcie trwania potyczki
 */
class CCzynnik_losowy
{
public:

    //! Konstruktor klasy CCzynnik_losowy
    /*!
     */
    CCzynnik_losowy();

    //! Destruktor klasy CCzynnik_losowy
    /*!
     */
    ~CCzynnik_losowy();


    //! Metoda odpwiedzialna za wygenerowanie czynnika losowego w rozgrywce
    /*!
     * \param jednostki parametr przechowujący wskaźnik do vectora obiektów klasy CJednostka
     * \param teren parametr przechowujący wskaźnik do terenu rozgrywki
     */
    void losuj_czynnik_losowy(std::vector<CJednostka*> &jednostki, CTeren * teren);


};


#endif // CCZYNNIK_LOSOWY_H
