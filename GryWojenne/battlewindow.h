#ifndef BATTLEWINDOW_H
#define BATTLEWINDOW_H

#include <QDialog>
#include <QGraphicsScene>
#include <QDebug>
# include <windows.h>
#include <QWidget>
#include <QGraphicsPixmapItem>

#include "cjednostka.h"
#include "cprzeszkoda.h"
#include "cczolg.h"
#include "cpiechota.h"
#include "cartyleria.h"

namespace Ui {
class battlewindow;
}

//! Klasa battlewindow - odpowiadająca za wyświetlanie przebiegu potyczki
/*!
  \class Klasa odpowiada za rysowanie elementów graficznych odzwierciedlających przebieg potyczki (jednostek, przeszkód) oraz elementów stałych okna potyczki (flagi, siatka).
 */
class battlewindow : public QDialog
{
    Q_OBJECT

public:
    //! Konstruktor okna potyczki
    /*!
     \param *parent wskaźnik na QWidget
     */
     battlewindow(QWidget *parent = nullptr);

     //! Destruktor okna potyczki
     /*!
      */
    ~battlewindow();

     //! Metoda tworząca oddział jednostek
     /*!
      */
    void tworz_oddzial();
    std::vector <QGraphicsPixmapItem*> items_vector; //!< vector przechowujący wskaźniki do elementów typu QGraphicsPixmapItem - elementów, które są generowane w oknie potyczki

    //! Metoda wykorzystywana do dodania jednostek do odziału
    /*!
     \param jednostki lista jednostek do dodania do odziału
     \param frakcja do odziału której zostaną dodane jednostki
     */
    void dodaj_jednostki(std::vector<QString> jednostki, QString frakcja );

    QString tekst; //!< zmienna typu QString przechowująca treść komunikatów wyświetlanych w oknie potyczki

    //! Setter służacy do ustawienia parametru Jednostki_rys_NATO
    /*!
     \param jednostki vector wskaźników CJednostka przechowujący jednostki NATO biorące udział w potyczce
     */
    void setJednostki_rys_NATO(std::vector<CJednostka*> jednostki);


    //! Setter służacy do ustawienia parametru Jednostki_rys_ISIS
    /*!
     \param jednostki vector wskaźników CJednostka przechowujący jednostki ISIS biorące udział w potyczce
     */
    void setJednostki_rys_ISIS(std::vector<CJednostka*> jednostki);

    //! Setter służacy do ustawienia parametru przeszkody_rys
    /*!
     \param przeszkody_w_potyczce vector wskaźników CPrzeszkoda przechowujący przeszkody, które pojawią się w potyczce
     */
    void setPrzeszkody_rys (std::vector<CPrzeszkoda*> przeszkody_w_potyczce);

    //! Metoda służaca do odświeżenia widoku na planszy
    /*!
        Metoda w pierwszej kolejności czyści planszę z elementóW, następnie rysuje kolejno jednostki obu frakcji oraz przeszkody
     */
    void on_now();

private slots:
    void on_pushButton_clicked();

private:
    Ui::battlewindow *ui;
    QGraphicsScene *scene;

    //! Metoda służaca do rysowania jednostek na planszy potyczki
    /*!
        Metoda w pierwszej kolejności czyści planszę z elementóW, następnie rysuje kolejno jednostki obu frakcji oraz przeszkody
        \param jednostki_do_narysowania vector przechowujący wskaźniki do obiektów typu CJednostka, które mają zostać narysowane
        \param frakcja frakcja, po której stronie zostaną  narysowane jednostki

    */
    void rysuj_jednostki(std::vector<CJednostka *> jednostki_do_narysowania, QString frakcja);

    //!Metoda pozwala na narysowanie planszy, na której rozgrywa się potyczka
    /*!
     */
    void rysuj_plansze ();

    //! Metoda służaca do narysowania flag obu frakcji na ekranie potyczki
    /*!
     */
    void rysuj_flagi ();

    //! Metoda służaca do narysowania przeszkód na ekranie potyczki
    /*!
     \param przeszkody_narysowania vector przechowujący wskaźniki do obiektów typu CPrzeszkoda, które mają zostać narysowane
     */
    void rysuj_przeszkody(std::vector<CPrzeszkoda*> przeszkody_do_narysowania);

    //! Metoda służaca do odświeżenia widoku na planszy
    /*!
        Metoda w pierwszej kolejności czyści planszę z elementóW, następnie rysuje kolejno jednostki obu frakcji oraz przeszkody
     */
    //void usun_jednostke (QGraphicsPixmapItem *item);
    std::vector<CJednostka*> jednostki_rys_ISIS; //!< vector przechowujący wskaźniki do obiektów typu CJednostka - jednostek frakcji ISIS, które zostaną narysowane na planszy
    std::vector<CJednostka*> jednostki_rys_NATO; //!< vector przechowujący wskaźniki do obiektów typu CJednostka - jednostek frakcji NATO, które zostaną narysowane na planszy
    std::vector<CPrzeszkoda*> przeszkody_rys; //!< vector przechowujący wskaźniki do obiektów typu CPrzeszkoda - przeszkód, które zostaną narysowane na planszy

};

#endif // BATTLEWINDOW_H
