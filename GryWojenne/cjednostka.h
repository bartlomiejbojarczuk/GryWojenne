#ifndef CJEDNOSTKA_H
#define CJEDNOSTKA_H

#include <QString>
#include <QDebug>
#include <math.h>
#include<cstdlib>
#include<ctime>
#include "cprzeszkoda.h"
#include "cbron.h"


class CBron;

//!
/*!
 * \class CJednostka
 * \brief Klasa abstrakcyjna, po której dziedziczą poszczególne typy jednostek,
 * Klasa definiuje metody wirtualne, które zostaną przysłonięte w implementacji klas pochodnych oraz parametry i metody wspólne dla wszystkich typów jednostek.
 klasa abstrakcyjna, po której dziedziczą poszczególne typy jednostek, definiuje metody wirtualne, które zostaną przysłonięte w implementacji klas pochodnych oraz parametry i metody wspólne dla wszystkich typów jednostek.
*/
class CJednostka
{
public:
    //! Konstruktor klasy CJednostka
    /*!
     */
    CJednostka();

    //!  Destruktor klasy CJednostka
    /*!
     */
    virtual ~CJednostka();


    //!  Metoda wirtualna odpowiadająca za przeprowadzenie ataku w trakcie potyczki przez obiekty klasy CJednostka
    /*!
     */
    virtual void atakuj (){};

    //! Metoda wirtualna odpowiadająca za wygenerowanie zdarzenia losowego dotyczącego jednostki
    /*!
     * \param wylosowano parametr przechowujący liczbową wartość losową, na podstawie której generowane są zdarzenia losowe
     */
    virtual void zdarzenie(double wylosowano){};

    //! Metoda wirtualna redukująca liczbę punktór życia (HP) jednostki po przeprowadzeniu ataku przez przeciwnika
    /*!
     */
    virtual void odejmij_zycie(int ile);

    //! Metoda odpowiadająca za uśmiercenie obiektu klasy CJednostka
    /*!
     *
     */
    void umrzyj();

    //! Getter zwracający nazwę jednostki
    /*!
     *
     */
    QString getNazwa();

    //! Getter zwracający wiadomość pochodzącą od jednostki
    /*!
     * \return treść wiadomości
     */
    QString getMessage();


    //! Setter ustawiający treść wiadomości
    /*!
     * \param tekst treść wiadomości jednostki
     */
    void setMessage(QString tekst);

    //! Getter zwracający frakcję jednostki
    /*!
     * \return nazwa frakcji, do której należy jednostka
     */
    QString getFrakcja();

    //! Setter ustawiający frakcję jednostki
    /*!
     * \param strona_konfliktu parametr typu QString przechowujący nazwę frakcji do odziału której należy jednostka
     */
    void setFrakcja(QString strona_konfliktu);

    //! Setter ustawiający współrzędną x pozycji jednostki
    /*!
     * \param x współrzędna x pozycji jednostki
     */
    void setPozycjaX(int x);

    //! Getter pobierający współrzędną x pozycji jednostki
    /*!
     * \return wartość współrzędnej x pozycji jednostki
     */
    int getPozycjaX();


    //! Setter ustawiający współrzędną y pozycji jednostki
    /*!
     * \param y współrzędna y pozycji jednostki
     */
    void setPozycjaY(int y);

    //! Getter pobierający współrzędną y pozycji jednostki
    /*!
     * \return wartość współrzędnej y pozycji jednostki
     */
    int getPozycjaY();

    //! Setter ustawiający vector przechowujący wskaźniki do wrogich jednostek
    /*!
     * \param jednostki vector wskaźników do obiektów typu CJednostka - przeciwników
     */
    void setWrogowie(std::vector<CJednostka*> jednostki);


    //! Setter ustawiający vector przechowujący wskaźniki do jednostek znajdujących się w odziale jednostki
    /*!
     * \param jednostki vector wskaźników do obiektów typu CJednostka - jednostek znajdujących się w odziale jednostki
     */
    void setSwoi(std::vector<CJednostka*> jednostki);

    //! Setter ustawiający vector przechowujący wskaźniki do przeszkód znajdujących się na planszy
    /*!
     * \param przeszkody vector wskaźników do obiektów typu CPrzeszkoda
     */
    void setPrzeszkody(std::vector<CPrzeszkoda*> przeszkody);


    //! Getter zwracający informacje, czy jednostka żyje
    /*!
     * \return wartość typu boolean w zależności od tego, czy jednostka żyje, czy nie
     */
    bool getDeath();


    //! Metoda ustawiająca wartość parametru w_zasiegu
    /*!
     *  \param zas parametr typu integer przechowujący informacje o zasięgu jednostki
     */
    void kto_w_zasiegu(int zas);

    //! Metoda zwiększająca doświadczenie jednostki
    /*!
     */
    void awansuj();


protected:

    //! Metoda zwracająca informacje o odległości od jednostki przeciwnika
    /*!
     * \param enemy wskaźnik do jednostki przeciwnika
     * \return odległość od jednostki przeciwnika
     */
    double licz_odleglosc(CJednostka* enemy);

    //! Metoda odpowiedzialna za określenie jednostki do ataku
    /*!
     * \param jednostki_wroga vector wskaźników do jednostek wroga
     */
    void znajdz_jednostke(std::vector<CJednostka*> jednostki_wroga);

    //! Metoda odpowiedzialna za przemieszczanie się jednostki
    /*!
     *
     */
    void przemiesc_sie();


    //! Metoda wirtualna odpowiedzialna za określenie wartości o jaką zostanie przesunięta jednostka
    /*!
     * \return wartość o jaką zostanie przemieszczona jednostka
     */
    virtual int ruch(){};

    //! Metoda wirtualna odpowiedzialna za określenie wartości o jaką zostanie przesunięta jednostka w sposób losowy
    /*!
     * \return wartość o jaką zostanie przemieszczona jednostka
     */
    virtual int losowy_ruch(){};

    //! Metoda weryfikująca, czy dana pozycja określona przez współrzędne x,y jest zajęta
    /*!
     * \param x współrzędna x pozycji, która jest weryfikowana
     * \param y współrzędna y pozycji, która jest weryfikowana
     * \return wartość typu boolean w zależności od tego, czy określona pozycja jest wolna czy nie
     */
    bool moge_zajac_miejsce(int x, int y);

    //! Metoda zwracająca liczbę losową w podanym zakresie
    /*!
     * \param Od wartość minimalna dla zakresu, z którego losowana jest wartość
     * \param Do wartość maksymlana dla zakres, z którego losowana jest wartość
     * \return wylosowaną wartość
     */
    double losuj(int Od, int Do);

    //! Metoda odpowiedzialna za wystrzal z broni jednostki
    /*!
     */
    void strzal();

    //! Metoda sprawdzająca, czy jednostka posiada wskazaną jednostkę do ataku
    /*!
     * \return prawdę lub fałsz w zależności od tego, czy obiekt posiada ustawioną jednostkę do ataku
     */
    bool mam_kogo_atakowac();

    //! Metoda odpowiedzialna za weryfikację, czy jednostka wskazana do ataku znajduje się w zasięgu jednostki
    /*!
     * \return prawdę lub fałsz w zależności od tego, czy jednostka znajduje się w zasięgu ataku
     */
    bool in_range(CJednostka* jednostka_do_ataku);

    //! Metoda wirtualna odpowiadająca za obliczenie liczby punktów ataku jednostki
    /*!
     * \return liczba punktów ataku
     */
    virtual int punkty_ataku();

    //! Metoda wirtualna odpowiadająca za obliczenie liczby punktów obrony jednostki
    /*!
     * \return liczba punktów obrony
     */
    virtual int punkty_obrony() ;


    QString nazwa; //!< parametr przechowujący nazwę jednostki
    QString message; //!< parametr przechowujący wiadomość jednostki
    QString frakcja; //!< parametr przechowujący informacje dotyczącą frakcji jednostki
    int pancerz; //!< parametr określający liczbę punktów pancerzu jednostki
    int sila_ataku;  //!< parametr określający liczbę punktów siły ataku jednostki
    int zasieg;  //!< parametr określający zasięg jednostki
    int doswiadczenie; //!< parametr określający doświadczenie jednostki
    int wytrzymalosc; //!< parametr określający wytrzymałość jednostki
    int zycie; //!< parametr określający liczbę punktów życia jednostki
    int szybkosc; //!< parametr określający szybkość jednostki
    int mobilnosc; //!< parametr określający mobilność jednostki
    int PozycjaX; //!< parametr określający współrzędną x pozycji jednostki
    int PozycjaY; //!< parametr określający współrzędną y pozycji jednostki
    bool death=false; //!< parametr określający czy jednostka pozostaje przy życiu
    CJednostka* jednostka_do_ataku=NULL; //!< parametr przechowujący wskaźnik na jednostkę, która jest celem ataku
    std::vector<CJednostka*> wrogowie; //!< vector przechowujący wskaźniki do jednostek, które znajdują się we frakcji przeciwnika
    std::vector<CJednostka*> swoi; //!< vector przechowujący wskaźniki do jednostek, które znajdują się we frakcji jednostki
    std::vector<CJednostka*> w_zasiegu; //!< vector przechowujący wskaźniki do jednostek, które znajdują się w zasięgu jednostki
    std::vector<CPrzeszkoda*> przeszkody; //!< vector przechowujący wskaźniki do przeszkód , które znajdują się w rozgrywce
    CBron* bron; //!< wskaźnik do obiektu typu CBron wykorzystywany przez jednostkę
};


#endif // CJEDNOSTKA_H
