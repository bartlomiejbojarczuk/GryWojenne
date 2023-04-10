#ifndef CCZOLG_H
#define CCZOLG_H

#include "cjednostka.h"
#include <QDebug>


//!
/*!
 * \class CCzolg
 * \brief Klasa CCzolg reprezentuje jednostkę typu CCzolg
 * Klasa implementuje metody i parametry charakterystyczne dla jednostki typu czołg
 */
class CCzolg : public CJednostka
{
public:
    //! Konstruktor klasy CCzolg
    /*!
     */
    CCzolg(QString strona_konfliktu);

    //! Konstruktor klasy CCzolg
    /*!
     */
    CCzolg();

    //! Destruktor klasy CCzolg
    /*!
     */
   ~CCzolg();

    //! Implementacja metody wirtualnej odpowiadająca za wygenerowanie zdarzenia losowego charakterystycznego dla typu jednostki
    /*!
     * \param wylosowano parametr przechowujący liczbową wartość losową, na podstawie której generowane są zdarzenia losowe
     */
    void zdarzenie(double wylosowano);


    //!  Implementacja metody wirtualnej odpowiadająca za przeprowadzenie ataku w trakcie potyczki przez obiekty klasy CCzolg
    /*!
     */
    void atakuj ();
 private:
    int zapas_paliwa; //!< parametr określający zapas paliwa jaki posiada CCzolg


    //!  Implementacja metody wirtualnej odpowiedzialna za określenie wartości o jaką zostanie przesunięta Czolg
    /*!
     * \return wartość o jaką zostanie przemieszczona jednostka
     */
    int ruch();

    //!  Implementacja metody wirtualnej odpowiedzialna za określenie wartości o jaką zostanie przesunięta jednostka w sposób losowy
    /*!
     * \return wartość o jaką zostanie przemieszczona jednostka
     */
    int losowy_ruch();
    bool sprawny=true; //!< parametr określający czy czołg jest sprawny i może kontynuować jazdę

    //!  Metoda  odpowiedzialna za realizację zdarzenia losowego w postaci uszkodzenia armaty
    /*!
     */
    void uszkodzenie_armaty();

};

#endif // CCZOLG_H
