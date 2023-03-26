#include "cpotyczka.h"

CPotyczka::CPotyczka()
{
    this->okno_potyczki=new battlewindow;
    okno_potyczki->show();
    qDebug()<<"Potyczka created";
}

CPotyczka::~CPotyczka()
{
}
std::vector<CJednostka *> CPotyczka::getJednostki_ISIS() const{

    return jednostki_ISIS;
}

std::vector<CJednostka *> CPotyczka::getJednostki_NATO() const{
    return jednostki_NATO;
}


//metoda odpowiedzialna za rozmieszczenie jednostek - przypisanie im współrzędnych ich pozycji
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

//metoda odpowiedzialna za utworzenie oddziałów na podstawie przekazanej listy jednostek
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
        //jednostki_ISIS.push_back(new CPiechota(frakcja));
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
            //jednostki_NATO.push_back(new CPiechota(frakcja));
            }
           if(dodane_jednostki[k]=="Czolg")
            {
            jednostki_NATO.push_back(new CCzolg(frakcja));
            }
        }
    rozmiesc_jednostki(jednostki_ISIS,"ISIS");
    rozmiesc_jednostki(jednostki_NATO,"NATO");

}

////metoda odświeżająca okno potyczki
//void CPotyczka::update_window()
//{
//    this->okno_potyczki->setJednostki_rys_ISIS(jednostki_ISIS);
//    this->okno_potyczki->setJednostki_rys_NATO(jednostki_NATO);
//    this->okno_potyczki->setPrzeszkody_rys(przeszkody_w_potyczce);
//    this->okno_potyczki->on_now();
//}
