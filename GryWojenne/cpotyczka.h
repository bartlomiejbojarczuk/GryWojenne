#ifndef CPOTYCZKA_H
#define CPOTYCZKA_H

#include <stdlib.h>
#include <vector>
#include <QString>
#include <QDebug>

#include "cjednostka.h"
#include "cteren.h"
#include "cprzeszkoda.h"
#include "battlewindow.h"
#include "cpiechota.h"
#include "cczolg.h"
#include "cartyleria.h"

class CPotyczka
{
public:
    CPotyczka();
    ~CPotyczka();
    std::vector<CJednostka*> getJednostki_NATO () const;
    std::vector<CJednostka*> getJednostki_ISIS () const;
    void tworz_oddzial(std::vector<QString> dodane_jednostki, QString frakcja);
    QString tekst;
    bool finished=false;
    CTeren* teren_walk;
    std::vector<CPrzeszkoda*> przeszkody_w_potyczce;

protected:
    battlewindow* okno_potyczki;


private:
    void result();
    std::vector<CJednostka*> jednostki_NATO;
    std::vector<CJednostka*> jednostki_ISIS;
    void rozmiesc_jednostki(std::vector<CJednostka*> jednostki_do_rozmieszczenia, QString frakcja);
    bool w_planszy (int x, int y);
    void sprawdz_kto_polegl(std::vector<CJednostka*> &jednostki_do_przegladu);
    void pech();
    void pobierz_wiadomosci(CJednostka *jednostka);
    void update_window();
    void update_jednostki_ISIS(CJednostka *jednostka);
    void update_jednostki_NATO (CJednostka *jednostka);
};

#endif // CPOTYCZKA_H
