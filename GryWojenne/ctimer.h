#ifndef CTIMER_H
#define CTIMER_H

#include <ctime>
#include <QThread>
#include <QString>


//!
/*!
 * \class CTimer
 * \brief Klasa definiuje parametry i metody timera, który steruje rozgrywką
 * Klasa odpowiada za sterownie rozgrywką poprzez odmierzanie kolejnych cykli rozgrywki
 */
class CTimer:public QThread
{ Q_OBJECT

signals:
    void now();

public:
    //! Konstruktor klasy CTimer
    /*!
     */
    CTimer();
    virtual ~CTimer();

    //! Metoda zwracająca wartość logiczną związaną ze stanem timera - czy został wystartowany
    /*!
     */
    bool IsStarted();

    //! Metoda zwracająca wartość logiczną związaną ze stanem timera - czy został zatrzymany
    /*!
     */
    bool IsStopped();

    //! Metoda zwracająca wartość logiczną związaną ze stanem timera - czy została włączona pauza
    /*!
     */
    bool IsPaused();

    //! Metoda zwracająca wartość logiczną związaną ze stanem timera - czy jest aktywny
    /*!
     */
    bool IsActive();

    //! Metoda odpowiedzialna za sterowanie timerem - włączenie pauzy
    /*!
     */
    void Pause();

    //! Metoda odpowiedzialna za sterowanie timerem - wyłączenie pauzy
    /*!
     */
    void Resume();

    //! Metoda odpowiedzialna za sterowanie timerem - uruchomienie timera
    /*
     */
    void Start ();

    //! Metoda odpowiedzialna za sterowanie timerem - zatrzymanie timera
    /*!
     */
    void Stop ();

    //! Metoda odpowiedzialna za sterowanie timerem - zresetowanie timera
    /*!
     */
    void Reset();



    //! Metoda zwracająca czas trwania od uruchomienia lub wznowienia timera
    /*!
     * \return czas trwania od uruchomienia lub wznowienia timera
     */
    clock_t GetTime();

    //! Metoda odpowiedzialna za uruchomienie timera i wysłanie sygnału
    /*!
     */
    void run();


private:
    clock_t startedAt; //!< parametr określający czas w jakim wystartowano timer
    clock_t pausedAt; //!< parametr określający czas w jakim uruchomiona pauzę timera
    bool started; //!< parametr określający czy timer został wystartowany
    bool paused; //!< parametr określający czy została uruchomiona pauza timera
};

#endif // CTIMER_H
