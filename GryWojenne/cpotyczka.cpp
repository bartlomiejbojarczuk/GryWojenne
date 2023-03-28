#include "cpotyczka.h"

CPotyczka::CPotyczka()
{
    this->czynnik_losowy=new CCzynnik_losowy;
    this->licznik=0;

  this->okno_potyczki=new battlewindow;

    this->timer=new CTimer();

    connect( timer, SIGNAL(now()),SLOT(update()) );
    okno_potyczki->show();
    timer->start();
qDebug()<<"Potyczka konstruktor";

}

CPotyczka::~CPotyczka()
{
    timer->Stop();
}



std::vector<CJednostka *> CPotyczka::getJednostki_ISIS() const{

    return jednostki_ISIS;
}

std::vector<CJednostka *> CPotyczka::getJednostki_NATO() const{
    return jednostki_NATO;
}


void CPotyczka::tworz_oddzial(std::vector<QString> dodane_jednostki, QString frakcja){

    if(frakcja=="ISIS"){
    for (int k=0; k<dodane_jednostki.size();k++)
    {
       if(dodane_jednostki[k]=="Lotnictwo")
        {
       //jednostki_ISIS.push_back(new CLotnictwo(frakcja));
        }
       if(dodane_jednostki[k]=="Artyleria")
        {
        jednostki_ISIS.push_back(new CArtyleria(frakcja));
        }
       if(dodane_jednostki[k]=="Piechota")
        {
        jednostki_ISIS.push_back(new CPiechota(frakcja));
        }
       if(dodane_jednostki[k]=="Czolg")
        {
        jednostki_ISIS.push_back(new CCzolg(frakcja));
        }
    }}
    else
        for (int k=0; k<dodane_jednostki.size();k++)
        {
           if(dodane_jednostki[k]=="Lotnictwo")
            {
          //jednostki_NATO.push_back(new CLotnictwo(frakcja));
            }
           if(dodane_jednostki[k]=="Artyleria")
            {
            jednostki_NATO.push_back(new CArtyleria(frakcja));
            }
           if(dodane_jednostki[k]=="Piechota")
            {
            jednostki_NATO.push_back(new CPiechota(frakcja));
            }
           if(dodane_jednostki[k]=="Czolg")
            {
            jednostki_NATO.push_back(new CCzolg(frakcja));
            }
        }
    rozmiesc_jednostki(jednostki_ISIS,"ISIS");
    rozmiesc_jednostki(jednostki_NATO,"NATO");

}

void CPotyczka::update()
{   qDebug()<<"Update START \n";
    timer->Pause();
   if (jednostki_ISIS.size()>0 && jednostki_NATO.size()>0){
        pech();

        for(int i=0; i<jednostki_ISIS.size();i++){
                update_jednostki_ISIS(jednostki_ISIS[i]);
     }

        for(int i=0; i<jednostki_NATO.size();i++){
        update_jednostki_NATO(jednostki_NATO[i]);
       }

   sprawdz_kto_polegl(jednostki_ISIS);
   qDebug()<<"Apel poległych ISIS";
   sprawdz_kto_polegl(jednostki_NATO);
   qDebug()<<"Apel poległych NATO";
   przeszkody_w_potyczce=teren_walk->getPrzeszkody();
   }
   else{
       result ();
       timer->Stop();
   }
    timer->Resume();

if(licznik>=40)
       result();
   licznik++;

update_window();
}


void CPotyczka::result()
{
    tekst+="Koniec bitwy \n Zwycięża: ";
    if(jednostki_ISIS.size()==0)
            {
                tekst+="NATO \n";
                qDebug()<<"NATO wygrywa";
            }
    else
    {
                tekst+="ISIS \n";
            qDebug()<<"ISIS wygrywa";}
            finished=true;
            timer->Stop();
            okno_potyczki->tekst=tekst;
            update_window();
}

void CPotyczka::rozmiesc_jednostki(std::vector<CJednostka *> jednostki_do_rozmieszczenia,QString frakcja)
{
    int x1=0,y1=450,x2=0,y2=0;
    for(int i=0; i<jednostki_do_rozmieszczenia.size();i++){

    if(frakcja=="ISIS")
           {
            jednostki_do_rozmieszczenia[i]->setPozycjaX(x2);
            jednostki_do_rozmieszczenia[i]->setPozycjaY(y2);
               x2=x2+75;
               if(x2>=500)
               {   x2=0;
                   y2=y2+75;}
           }
           else
           {
            jednostki_do_rozmieszczenia[i]->setPozycjaX(x1);
            jednostki_do_rozmieszczenia[i]->setPozycjaY(y1);
               x1=x1+75;
               if(x1>=500)
               {   x1=0;
                   y1=y1-75;}

           }
    }

    qDebug()<<"Rozmieszczam jednostki";
}

void CPotyczka::sprawdz_kto_polegl(std::vector<CJednostka *> &jednostki_do_przegladu)
{
      std::vector < CJednostka* >::iterator iterator;
for ( iterator = jednostki_do_przegladu.begin(); iterator != jednostki_do_przegladu.end(); )
{
    if ((*iterator)->getDeath())
    {
        tekst+=(*iterator)->getNazwa()+" "+(*iterator)->getFrakcja()+" UMIERA \n";
        //delay(50);
        qDebug()<<"Usunieto "<<(*iterator)->getNazwa();
        delete *iterator;
        iterator = jednostki_do_przegladu.erase(iterator);

    }
    else
    {
        iterator++;
    }
}
}

void CPotyczka::pech()
{   qDebug()<<"Pech";
    if(!finished)
    {if(licznik%3==1)
        {
       if(licznik%2==0)
        czynnik_losowy->losuj_czynnik_losowy(jednostki_ISIS,teren_walk);

       else
        czynnik_losowy->losuj_czynnik_losowy(jednostki_NATO,teren_walk);
        }
    }
}

void CPotyczka::pobierz_wiadomosci(CJednostka *jednostka)
{   qDebug()<<"pobierz_wiadomosci";
    this->tekst+=jednostka->getMessage();
    qDebug()<<"I";
    jednostka->setMessage("");
    qDebug()<<"II";
    okno_potyczki->tekst=tekst;
    qDebug()<<"III";
    qDebug()<<"Pobierz wiadomości";
}

void CPotyczka::update_window()
{
    this->okno_potyczki->setJednostki_rys_ISIS(jednostki_ISIS);
    this->okno_potyczki->setJednostki_rys_NATO(jednostki_NATO);
    this->okno_potyczki->setPrzeszkody_rys(przeszkody_w_potyczce);
    this->okno_potyczki->on_now();
}

void CPotyczka::update_jednostki_ISIS(CJednostka *jednostka)
{
    jednostka->setWrogowie(jednostki_NATO);
    jednostka->setSwoi(jednostki_ISIS);
    jednostka->setPrzeszkody(przeszkody_w_potyczce);
    jednostka->awansuj();
    jednostka->atakuj();
    pobierz_wiadomosci(jednostka);
}

void CPotyczka::update_jednostki_NATO (CJednostka *jednostka)
{
    jednostka->setWrogowie(jednostki_ISIS);
    jednostka->setSwoi(jednostki_NATO);
    jednostka->setPrzeszkody(przeszkody_w_potyczce);
    jednostka->awansuj();
    jednostka->atakuj();
    pobierz_wiadomosci(jednostka);
}



