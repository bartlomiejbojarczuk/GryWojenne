#ifndef CPOCISK_H
#define CPOCISK_H

//!
/*!
 * \class CPocisk
 * \brief Klasa CPocisk reprezentuje uogólniony pocisk, wystrzeliwany przez jednostki
 * Klasa opisuje parametry i metody pocisku.
 */
class CPocisk
{
public:

    //! Konstruktor klasy CPocisk
    /*!
     */
    CPocisk();

    //! Destruktor klasy CPocisk
    /*!
     */
    virtual ~CPocisk();

    //! Metoda wirtualna zwracająca liczbę obrażeń zadawanych przez pocisk
    /*!
     * \return liczbę zadawanych obrażeń
     */
    virtual int obrazenia(){};
protected:
    int sila_razenia; //!< parametr określający siłę rażenia pocisku

    bool niewypal;//!< parametr określający czy pocisk jest niewypałem



};

#endif // CPOCISK_H
