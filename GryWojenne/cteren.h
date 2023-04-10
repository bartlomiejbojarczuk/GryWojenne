#ifndef CTEREN_H
#define CTEREN_H

#include <QString>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "cprzeszkoda.h"

//!
/*!
 * \class CTeren
 * \brief Klasa  reprezentuje teren na którym rozgrywana jest potyczka
 * Klasa CTeren definiuje parametry i metody, które są następnie wykorzystywane w trakcie potyczki, klasa reprezentuje teren na którym rozgrywana jest potyczka.
 */
class CTeren
{
public:
    //! Konstruktor klasy CTeren
    /*!
     */
    CTeren();

    //! Metoda zwracająca wartość parametru trudność charakterystycznego dla danego Terenu
    /*!
     * \return wartość parametru trudność
     */
    int getTrudnosc();

    //! Metoda zwracająca vector przechowujący wskaźniki do przeszkód
    /*!
     * \return vector przechowujący wskaźniki do obiektów typu CPrzeszkoda
     */
    std::vector<CPrzeszkoda *> getPrzeszkody();

    //! Metoda wirtualna wprowadzająca do rozgrywki czynnik losowy wynikający z terenu
    /*!
     *
     */
    virtual void przeszkodz(double wylosowane){};
protected:
    std::vector<CPrzeszkoda*> przeszkody; //!< parametr typu vector przechowujący wskaźniki do obiektów typu CPrzeszkoda
    int trudnosc; //!< parametr określający trudność Terenu

    //! Metoda zwracająca liczbę losową w podanym zakresie
    /*!
     * \param Od wartość minimalna dla zakresu, z którego losowana jest wartość
     * \param Do wartość maksymlana dla zakres, z którego losowana jest wartość
     * \return wylosowaną wartość
     */
    double losuj (int Od, int Do);

private:

};

#endif // CTEREN_H
