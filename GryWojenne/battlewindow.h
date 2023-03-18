#ifndef BATTLEWINDOW_H
#define BATTLEWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "cprzeszkoda.h"

class CJednostka;
namespace Ui {
class BattleWindow;
}

class BattleWindow : public QMainWindow
{
    Q_OBJECT

public:

    void tworz_oddzial();
    explicit BattleWindow(QWidget *parent = 0);
    ~BattleWindow();
    std::vector <QGraphicsPixmapItem*> items_vector;
    void dodaj_jednostki(std::vector<QString> jednostki, QString frakcja);
    QString tekst;
    void setJednostki_rys_NATO(std::vector<CJednostka*> jednostki);
    void setJednostki_rys_ISIS(std::vector<CJednostka*> jednostki);
    void setPrzeszkody_rys (std::vector<CPrzeszkoda*> przeszkody_w_potyczce);
    void on_now();

private slots:


  void on_pushButton_clicked();

    void on_Fatum_button_clicked();

private:
    bool GO=false;
    QGraphicsScene *scene;
    Ui::BattleWindow *ui;



    void rysuj_jednostki(std::vector<CJednostka *> jednostki_do_narysowania, QString frakcja);
    void rysuj_plansze ();
    void rysuj_flagi ();
    void rysuj_przeszkody(std::vector<CPrzeszkoda*> przeszkody_do_narysowania);
    void usun_jednostke (QGraphicsPixmapItem *item);
    std::vector<CJednostka*> jednostki_rys_ISIS;
    std::vector<CJednostka*> jednostki_rys_NATO;
    std::vector<CPrzeszkoda*> przeszkody_rys;
};


#endif // BATTLEWINDOW_H
