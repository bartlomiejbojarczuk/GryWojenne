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
    on_now();
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
    rysuj_przeszkody(przeszkody_rys);
    rysuj_jednostki(jednostki_rys_ISIS,"ISIS");
    rysuj_jednostki(jednostki_rys_NATO,"NATO");


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
    QPixmap ISIS_flag("C:\\Users\\bbojarczuk\\ZCUZ\\GryWojenne\\GryWojenne\\graphics\\NATO_flag.png");
    QPixmap NATO_flag("C:\\Users\\bbojarczuk\\ZCUZ\\GryWojenne\\GryWojenne\\graphics\\ISIS_flag.png");
    ui->label->setPixmap(NATO_flag);
    ui->label_2->setPixmap(ISIS_flag);
    qDebug() << "App path : " << qApp->applicationDirPath();
}

void battlewindow::setJednostki_rys_NATO(std::vector<CJednostka*> jednostki)
{
    this->jednostki_rys_NATO=jednostki;
}

void battlewindow::setJednostki_rys_ISIS(std::vector<CJednostka*> jednostki){
    this->jednostki_rys_ISIS=jednostki;
}

void battlewindow::setPrzeszkody_rys(std::vector<CPrzeszkoda *> przeszkody_w_potyczce)
{
    this->przeszkody_rys=przeszkody_w_potyczce;
}

void battlewindow::rysuj_jednostki (std::vector<CJednostka*> jednostki_do_narysowania, QString frakcja){

      for(int i=0;i<jednostki_do_narysowania.size();i++){


if(jednostki_do_narysowania.size()){

    QString subpath="";

                    //if(dynamic_cast<CLotnictwo*>(jednostki_do_narysowania[i]))
                     {
                     subpath="plane_";
                     }
                    if(dynamic_cast<CArtyleria*>(jednostki_do_narysowania[i]))
                     {
                     subpath="artyleria_";
                     }
                    if(dynamic_cast<CPiechota*>(jednostki_do_narysowania[i]))
                     {
                     subpath="soldier_";
                     }
                    if(dynamic_cast<CCzolg*>(jednostki_do_narysowania[i]))
                     {
                    subpath="tank_";
                     }
            subpath=subpath+frakcja;
            QString path="C:\\Users\\bbojarczuk\\ZCUZ\\GryWojenne\\GryWojenne\\graphics\\"+subpath;
            qDebug() << "Rysuję: " <<subpath;
            QImage Image(path);
            QGraphicsPixmapItem *item=new QGraphicsPixmapItem(QPixmap::fromImage(Image));
            item->setScale(0.1);
            item->setPos(jednostki_do_narysowania[i]->getPozycjaX(),jednostki_do_narysowania[i]->getPozycjaY());
            scene->addItem(item);
    }

    }}
