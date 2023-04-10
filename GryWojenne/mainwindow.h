#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>
#include "cpustynia.h"
#include "cmiasto.h"

#include "cpotyczka.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

//!
/*!
 * \class MainWindow
 * \brief Klasa MainWindow - odpowiadająca za wyświetlanie ekranu ustawienia parametrów potyczki
 * Klasa odpowiada za wyświetlenie głownego okna aplikacji, w którym użytkownik ma możliwość zdefiniowania oddziałów po obu stronach potyczki, wybrania terenu, lub losowego wygenerowania oddziałów.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    //! Konstruktor klasy MainWindow
    /*!
     */
    MainWindow(QWidget *parent = nullptr);

    //! Destruktor klasy MainWindow
    /*!
     */
    ~MainWindow();

    //! Metoda odpowiedzialna za weryfikację liczebności odziałów po obu stronach rozgrywki i wyświetlenie użytkownikowi odpowiedniego komunikatu
    /*!
     */
    bool sprawdz();
    QMessageBox msgBox; //!< zmienna typu QMessageBox, okno dialogowe, w którym wyświetlane są informacje dla użytkownika
    std::vector <QString> dodane_jednostki_ISIS; //!< vector przechowujący nazwy dodanych jednostek po stronie ISIS
    std::vector <QString> dodane_jednostki_NATO; //!< vector przechowujący nazwy dodanych jednostek po stronie NATO
    QString jednostki_ISIS_String=""; //!< zmienna typu QString przechowująca w formie tekstowej nazwy dodanych jednostek po stronie ISIS
    QString jednostki_NATO_String=""; //!< zmienna typu QString przechowująca w formie tekstowej nazwy dodanych jednostek po stronie NATO
    int ile_jednostek_ISIS=0; //!< parametr określający liczbę dodanych jednostek po stronie ISIS
    int ile_jednostek_NATO=0; //!< parametr określający liczbę dodanych jednostek po stronie NATO

private slots:

    //! Slot realizujący działanie po wciśnięciu przycisku wyjścia z aplikacji
    /*!
     */
    void on_wyjscie_clicked();

    //! Slot realizujący działanie po wciśnięciu przycisku Rozpocznij Potyczkę
    /*!
     */
    void on_Rozpocznij_potyczke_clicked();

    //! Slot realizujący działanie po wciśnięciu przycisku Dodaj jednostkę
    /*!
     */
    void on_dodaj_jednostke_Button_clicked();

    //! Slot realizujący działanie po wciśnięciu przycisku Losuj
    /*!
     */
    void on_LosujButton_clicked();

    //! Slot realizujący działanie po wciśnięciu przycisku Kasuj oddziały
    /*!
     */
    void on_kasuj_oddzialy_clicked();

private:
    Ui::MainWindow *ui;

    //! Metoda zwracająca liczbę losową w podanym zakresie
    /*!
     * \param Od wartość minimalna dla zakresu, z którego losowana jest wartość
     * \param Do wartość maksymlana dla zakres, z którego losowana jest wartość
     * \return wylosowaną wartość
     */
    int randomize(int low, int high);

    //! Metoda zwracająca wskaźnik do obiektu typu Teren na którym realizowana będzie rozgrywka
    /*!
     */
    CTeren* daj_teren();

};
#endif // MAINWINDOW_H
