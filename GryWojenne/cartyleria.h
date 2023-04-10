#ifndef CARTYLERIA_H
#define CARTYLERIA_H

#include "cjednostka.h"




//!
/*!
 *  \class CArtyleria
 *  \brief Klasa CArtyleria reprezentuje jednostkę typu CArtyleria
 *  Klasa implementuje metody i parametry charakterystyczne dla jednostki typu artyleri
 */
class CArtyleria : public CJednostka
{
public:
    //! Konstruktor klasy CArtyleria
    /*!
     */
    CArtyleria();

    //! Destruktor klasy CArtyleria
    /*!
     */
    ~CArtyleria();
    //! Konstruktor klasy CArtyleria
    /*!
     * \param strona_konfliktu parametr określający stronę konfliktu, do drużyny której będzie należała Artyleria
     */
    CArtyleria(QString strona_konfliktu);

    //!  Implementacja metody wirtualnej odpowiadająca za przeprowadzenie ataku w trakcie potyczki przez obiekty klasy CArtyleria
    /*!
     */
    void atakuj();

    //!  Implementacja metody wirtualnej odpowiedzialna za określenie wartości o jaką zostanie przesunięta Artyleria
    /*!
     * \return wartość o jaką zostanie przemieszczona jednostka
     */
    int ruch();

    //!  Implementacja metody wirtualnej odpowiedzialna za określenie wartości o jaką zostanie przesunięta jednostka w sposób losowy
    /*!
     * \return wartość o jaką zostanie przemieszczona jednostka
     */
    int losowy_ruch();

private:
    //! Implementacja metody wirtualnej odpowiadająca za wygenerowanie zdarzenia losowego charakterystycznego dla typu jednostki
    /*!
     * \param wylosowano parametr przechowujący liczbową wartość losową, na podstawie której generowane są zdarzenia losowe
     */
    void zdarzenie(double wylosowano);

    int amunicja;  //!< parametr określający zapas amunicji w składzie jednostki typu Artyleria

    //! Metoda odpowiedzialna za zwiększenie zapasu amunicji w składzie jednostki typu Artyleria
    /*!
     */
    void dostawa_amunicji();

    //! Metoda realizująca zdarzenie losowe - wybuch w składzie amunicji
    /*!
     * W wyniku wybuchu jednostka ulega destrukcji, jednostki będące w zasięgu wybuchu odnoszą obrażenia
     */
    void wybuch_w_skladzie_amunicji();





};
#endif // CARTYLERIA_H
