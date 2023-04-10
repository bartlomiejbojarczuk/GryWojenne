#ifndef CPOTYCZKA_H
#define CPOTYCZKA_H

#include <stdlib.h>
#include <vector>
#include <QString>
#include <QDebug>
#include <QObject>

#include "ctimer.h"
#include "cjednostka.h"
#include "cteren.h"
#include "cprzeszkoda.h"
#include "battlewindow.h"
#include "cpiechota.h"
#include "cczolg.h"
#include "cartyleria.h"
#include "cczynnik_losowy.h"


//!
/*!
 * \class CPotyczka
 * \brief Klasa definiuje metody odpowiedzialne za sterowanie potyczką,
 * Klasa CPotyczka odpowiada za realizację potyczki pomiędzy dwiema stronami
 */
class CPotyczka: public QObject
{
    Q_OBJECT

public:

    //! Konstruktor klasy CPotyczka
    /*!
     */
    CPotyczka();
    //! Destruktor klasy CPocisk
    /*!
     */
    ~CPotyczka();

    //! Metoda zwracająca vector jednostek należących do odziału NATO
    /*!
     * \return jednostki_NATO
     */
    std::vector<CJednostka*> getJednostki_NATO () const;

    //! Metoda zwracająca vector jednostek należących do odziału ISIS
    /*!
     * \return jednostki_ISIS
     */
    std::vector<CJednostka*> getJednostki_ISIS () const;

    //! Metoda odpowiedzialna za utworzenie oddziałów, które będą brały udział w potyczce
    /*!
     * \param dodane_jednostki vector przechowujący jednostki dodane na ekranie definiowania składów oddziałóW
     * \param frakcja strona konfliktu, po której będzie walczył oddział
     */
    void tworz_oddzial(std::vector<QString> dodane_jednostki, QString frakcja);

    QString tekst; //!< parametr przechowujący treść wyświetlanych wiadomości
    bool finished=false; //!< parametr określający czy potyczka została zakończona
    CTeren* teren_walk; //!< parametr przechowujący wskaźnik do terenu, na którym rozgrywana jest potyczka
    std::vector<CPrzeszkoda*> przeszkody_w_potyczce; //!< parametr przechowujący wskaźniki do przeszkód, które występują w potyczce

protected:
    battlewindow* okno_potyczki; //!< parametr przechowujący wskaźnik do okna, w którym rozgrywa się potyczka
    CCzynnik_losowy* czynnik_losowy; //!< parametr przechowujący wskaźnik do czynnika losowego występującego w potyczce


private:

    //! Metoda odpowiedzialna za wygenerowanie wiadomości informującej użytkownika o rezultacie potyczki
    /*!
     */
    void result();

    int licznik; //!< parametr przechowujący informacje o numerze tury
    CTimer* timer; //!< parametr przechowujący wskaźnik do obiektu typu CTimer sterującego potyczką
    std::vector<CJednostka*> jednostki_NATO; //!< parametr przechowujący wskaźniki do jednostek biorących udział w potyczce po stronie NATO
    std::vector<CJednostka*> jednostki_ISIS; //!< parametr przechowujący wskaźniki do jednostek biorących udział w potyczce po stronie ISIS

    //! Metoda odpowiedzialna za rozmieszczenie jedenostek na planszy
    /*!
     * \param jednostki_do_rozmieszczenia vector wskaźników do obiektów typu CJednostka, które mają zostać rozmieszczone na planszy
     * \param frakcja strona konfliktu po stronie której będą walczyć rozmieszczane jednostki
     */
    void rozmiesc_jednostki(std::vector<CJednostka*> jednostki_do_rozmieszczenia, QString frakcja);

    //! Metoda weryfikująca które jednostki poległy w trakcie trwania tury
    /*!
     */
    void sprawdz_kto_polegl(std::vector<CJednostka*> &jednostki_do_przegladu);

    //! Metoda odpowiedzialna za wygenerowanie zdarzenia losowego
    /*!
     */
    void pech();

    //! Metoda pobierająca wiadomości do wyświetlenia użytkownikowi
    /*!
     * \param jednostka parametr przechowujący wskaźnik do obiektu typu CJednostka, od której pobierane będą wiadomości
     */
    void pobierz_wiadomosci(CJednostka *jednostka);

    //! Metoda odpowiedzialna za odświeżenie widoku na planszy
    /*!
     */
    void update_window();

    //! Metoda odpowiedzialna za aktualizację parametrów jednostek ISIS
    /*!
     * \param jednostka wskaźnik do jednostki, której parametry mają zostać zaktualizowane
     */
    void update_jednostki_ISIS(CJednostka *jednostka);

    //! Metoda odpowiedzialna za aktualizację parametrów jednostek NATO
    /*!
     * \param jednostka wskaźnik do jednostki, której parametry mają zostać zaktualizowane
     */
    void update_jednostki_NATO (CJednostka *jednostka);

private slots:

    //! Metoda odpowiedzialna za aktualizację statusu i przebiegu potyczki
    /*!
     */
    void update ();
};

#endif // CPOTYCZKA_H
