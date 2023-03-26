#include "battlewindow.h"
#include "ui_battlewindow.h"

battlewindow::battlewindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::battlewindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(0,0,500,500);
    rysuj_plansze();
    rysuj_flagi();
qDebug()<<"BattleWindow konstruktor";
}

battlewindow::~battlewindow()
{
    delete ui;
}

void battlewindow::on_pushButton_clicked()
{
    exit (1);
}

//odświeżenie widoku
void battlewindow::on_now(){

    ui->textBrowser->setText(tekst);

    scene->clear();
    rysuj_plansze();
    //rysuj_przeszkody(przeszkody_rys);
    //rysuj_jednostki(jednostki_rys_ISIS,"ISIS");
    //rysuj_jednostki(jednostki_rys_NATO,"NATO");


}

//Metoda pozwala na narysowanie planszy, na której rozgrywa się potyczka
void battlewindow::rysuj_plansze()
{
    QPen redPen (Qt::red);
    QPen greenPen (Qt::darkGreen);

    for (int x=0; x<=500; x+=50)
    scene->addLine(x,0,x,500, redPen);
    for (int y=0; y<=500; y+=50)
        scene->addLine(0,y,500,y, greenPen);
}


//Metoda rysująca flagi
void battlewindow::rysuj_flagi()
{
    ui->label->setScaledContents(true);
    ui->label_2->setScaledContents(true);
    QPixmap ISIS_flag("..\\graphics\\NATO_flag.png");
    QPixmap NATO_flag("..\\..\\GryWojenne\\graphics\\ISIS_flag.png");
    ui->label->setPixmap(NATO_flag);
    ui->label_2->setPixmap(ISIS_flag);
    qDebug() << "App path : " << qApp->applicationDirPath();
}
