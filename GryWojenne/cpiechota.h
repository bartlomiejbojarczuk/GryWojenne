#ifndef CPIECHOTA_H

#pragma once

#include "cjednostka.h"

//!
/*!
 * \class CPiechota
 * \brief Reprezentuje jednostkę typu piechota
 * Klasa implementuje metody i parametry charakterystyczne dla jednostki typu piechota
 */
class CCzolg;
class CArtyleria;

class CPiechota  :public CJednostka
{
public:
    //! Konstruktor klasy CPiechota
    /*!
     */
    CPiechota ();

    //! Konstruktor klasy CPiechota
    /*!
     */
    CPiechota (QString strona_konfliktu);

    //! Destruktor klasy CPiechota
    /*!
     */
    ~CPiechota();

    //! Implementacja metody wirtualnej odpowiadająca za wygenerowanie zdarzenia losowego charakterystycznego dla typu jednostki
    /*!
     * \param wylosowano parametr przechowujący liczbową wartość losową, na podstawie której generowane są zdarzenia losowe
     */
    void zdarzenie(double wylosowano);

private:

    int morale;  //!< parametr określający morale jednostki typu CPiechota
    bool panika; //!< parametr określający czy jednostka wpadła w panikę

    //!  Implementacja metody wirtualnej odpowiadająca za przeprowadzenie ataku w trakcie potyczki przez obiekty klasy CPiechota
    /*!
     */
    void atakuj ();

    //!  Implementacja metody wirtualnej odpowiedzialna za określenie wartości o jaką zostanie przesunięta jednostka typu CPiechota
    /*!
     * \return wartość o jaką zostanie przemieszczona jednostka
     */
    int ruch();

    //!  Implementacja metody wirtualnej odpowiedzialna za określenie wartości o jaką zostanie przesunięta jednostka w sposób losowy
    /*!
     * \return wartość o jaką zostanie przemieszczona jednostka
     */
    int losowy_ruch();

    //!  Metoda odpowiedzialna za realizację ucieczki jednostki CPiechota po wystąpieniu paniki
    /*!
     */
    void uciekaj();

    //!  Metoda odpowiedzialna za określenie morale jednostki
    /*!
     */
    void jakie_morale();

    //!  Metoda odpowiedzialna za realizację zdarzenia losowego w postaci choroby jednostki
    /*!
     *
     */
    void choroba();

    //!  Metoda odpowiedzialna za realizację zdarzenia losowego w postaci otrucia jednostki
    /*!
     *
     */
    void otruj();

    //!  Metoda zwracająca liczbę czołgów w oddziale
    /*!
     * \param wskaźnik do odziału, w którym określona ma być liczba czołgów
     * \return liczbę czołgów w odziale
     */
    int ile_czolgow(std::vector<CJednostka *> oddzial);

    //!  Metoda zwracająca liczbę armat w oddziale
    /*!
     * \param wskaźnik do odziału, w którym określona ma być liczba armat
     * \return liczbę armat w odziale
     */
    int ile_armat(std::vector<CJednostka *> oddzial);
    bool zdrowy; //!< parametr przechowujący informację, czy jednostka jest zdrowa

};



#endif // CPIECHOTA_H
