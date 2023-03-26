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

class battlewindow : public QDialog
{
    Q_OBJECT

public:
    explicit battlewindow(QWidget *parent = nullptr);
    ~battlewindow();
    void tworz_oddzial();
    std::vector <QGraphicsPixmapItem*> items_vector;
    void dodaj_jednostki(std::vector<QString> jednostki, QString frakcja);
    QString tekst;
    void setJednostki_rys_NATO(std::vector<CJednostka*> jednostki);
    void setJednostki_rys_ISIS(std::vector<CJednostka*> jednostki);
    void setPrzeszkody_rys (std::vector<CPrzeszkoda*> przeszkody_w_potyczce);
    void on_now();
    char buffer[MAX_PATH];
private slots:
    void on_pushButton_clicked();

private:
    Ui::battlewindow *ui;
    QGraphicsScene *scene;

    void rysuj_jednostki(std::vector<CJednostka *> jednostki_do_narysowania, QString frakcja);
    void rysuj_plansze ();
    void rysuj_flagi ();
    void rysuj_przeszkody(std::vector<CPrzeszkoda*> przeszkody_do_narysowania){};
    void usun_jednostke (QGraphicsPixmapItem *item);
    std::vector<CJednostka*> jednostki_rys_ISIS;
    std::vector<CJednostka*> jednostki_rys_NATO;
    std::vector<CPrzeszkoda*> przeszkody_rys;

};

#endif // BATTLEWINDOW_H
