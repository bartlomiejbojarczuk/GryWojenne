#ifndef CBRON_H
#define CBRON_H
#include <QString>
#include "cpocisk.h"
#include "czwykly.h"
#include "cprzeciwlotniczy.h"
#include "cprzeciwpancerny.h"

class CBron
{
public:
    //! Konstruktor klasy CBron
    /*!
     */
    CBron();

    //! Destruktor klasy CBron
    /*!
     */
    ~CBron();

    //! Metoda odpowiedzialna za wystrzelenie pocisku z Broni
    /*!
     * \param kto parametr określający kto strzela
     * \param do_kogo parametr określający do kogo strzelamy
     */
    void strzel(QString kto, QString do_kogo);

    //! Metoda weryfikująca czy możliwe jest dokonanie strzału
    /*!
     * \param kto parametr określający kto strzela
     * \param do_kogo parametr określający do kogo strzelamy
     *
     * \return zwraca true jeżeli możliwe jest wykonanie strzału
     */
    bool czy_zastrzele(QString kto, QString do_kogo);

    int suma_obrazen; //!< parametr określający sumę obrażeń, które ponosi jednostka będąca przedmiotem ataku

    CPocisk* pocisk; //!< parametr przechowujący wskaźnik do obiektu typu CPocisk wystrzeliwany przez CBron

};

#endif // CBRON_H
