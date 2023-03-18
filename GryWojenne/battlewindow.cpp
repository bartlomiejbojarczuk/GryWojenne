#include "battlewindow.h"
#include "ui_battlewindow.h"
#include <QtWidgets>
#include <QDebug>
#include <QLabel>
#include <typeinfo>




BattleWindow::BattleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BattleWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,500,500);
    rysuj_plansze();
    rysuj_flagi();
qDebug()<<"BattleWindow konstruktor";
}

BattleWindow::~BattleWindow()
{

    delete ui;

}



//Zamknięcie okna walki
void BattleWindow::on_pushButton_clicked()
{
    this->deleteLater();

}
