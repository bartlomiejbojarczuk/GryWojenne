#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QString>

#include "cpotyczka.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool sprawdz();
    QMessageBox msgBox;
    std::vector <QString> dodane_jednostki_ISIS;
    std::vector <QString> dodane_jednostki_NATO;
    QString jednostki_ISIS_String="";
    QString jednostki_NATO_String="";
    int ile_jednostek_ISIS=0;
    int ile_jednostek_NATO=0;

private slots:
    void on_wyjscie_clicked();

    void on_Rozpocznij_potyczke_clicked();

    void on_dodaj_jednostke_Button_clicked();

    void on_LosujButton_clicked();

    void on_kasuj_oddzialy_clicked();

private:
    Ui::MainWindow *ui;
    int randomize(int low, int high);

};
#endif // MAINWINDOW_H
