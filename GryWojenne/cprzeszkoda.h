#ifndef CPRZESZKODA_H
#define CPRZESZKODA_H

#include <QString>

//!
/*!
 * \class CPrzeszkoda
 * \brief Klasa definiuje metody i parametry wykorzystywane przez przeszkody, które pojawiają się w trakcie trwania potyczki
 * Klasa CPrzeszkoda reprezentuje przeszkody fizyczne, które mogą się pojawić na planszy w trakcie rozgrywki
*/
class CPrzeszkoda
{
public:
    //! Konstruktor klasy CPrzeszkoda
    /*!
     *
     */
    CPrzeszkoda();

    //! Konstruktor klasy CPrzeszkoda
    /*!
     *
     */
    CPrzeszkoda(QString co, int szer, int wys, int x, int y);

    //! Metoda zwracająca współrzędną x pozycji przeszkody
    /*!
     * \return współrzędną x pozycji przeszkody
     */
    int getPosx();

    //! Metoda zwracająca współrzędną y pozycji przeszkody
    /*!
     * \return współrzędną y pozycji przeszkody
     */
    int getPosy();

    //! Metoda zwracająca szerokość przeszkody
    /*!
     * \return szerokość przeszkody
     */
    int getSzerokosc();

    //! Metoda zwracająca wysokość przeszkody
    /*!
     * \return wysokość przeszkody
     */
    int getWysokosc();

    //! Metoda zwracająca nazwę przeszkody
    /*!
     * \return nazwę przeszkody
     */
    QString getNazwa();
private:
    QString nazwa; //!< parametr przechowujący nazwę przeszkody
    int Posx; //!< parametr przechowujący wartość współrzędnej x położenia przeszkody
    int Posy; //!< parametr przechowujący wartość współrzędnej y położenia przeszkody
    int szerokosc; //!< parametr przechowujący wartość szerokości przeszkody
    int wysokosc; //!< parametr przechowujący wysokość przeszkody
};

#endif // CPRZESZKODA_H
