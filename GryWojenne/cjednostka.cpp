#include "cjednostka.h"

CJednostka::CJednostka()
{
   this->bron=new CBron;
}
CJednostka::~CJednostka(){
qDebug()<<"Destruktor jednostka!";
}

double CJednostka::licz_odleglosc(CJednostka* enemy)
{
   qDebug()<<"CJednostka::licz_odleglosc";

if(enemy && this ){
   qDebug()<<"Adres this: "<<this;
   qDebug()<<this->PozycjaX;
   qDebug()<<this->PozycjaY;
   qDebug()<<"Adres enemy: "<<enemy;
   qDebug()<<enemy->PozycjaX;
   qDebug()<<enemy->PozycjaY;

   int rX=this->PozycjaX-(enemy->PozycjaX);
   qDebug()<<"1";
   int rY=this->PozycjaY-(enemy->PozycjaY);
   qDebug()<<"2";
   double odl=sqrt(rX*rX+rY*rY);
   qDebug()<<"3-> "<<odl;
   return odl;
}
   else
   {   qDebug()<<"Enemy is null";

       return 0;}
qDebug()<<"To nie tutaj";
}

void CJednostka::znajdz_jednostke(std::vector<CJednostka*> jednostki_wroga)
{   int min=500;
   qDebug()<<"Szukam celu dla: "<<this->nazwa;

   for(int i=0; i<jednostki_wroga.size();i++)
       if(licz_odleglosc(jednostki_wroga[i])<min)
       {   min=licz_odleglosc(jednostki_wroga[i]);
           jednostka_do_ataku=jednostki_wroga[i];
       }
   qDebug()<<"Znalazłem cel dla:  "<<this->nazwa<<" jest to: "<< jednostka_do_ataku->getNazwa();


}

bool CJednostka::moge_zajac_miejsce(int x, int y){


   for(int i=0;i<swoi.size();i++)
   {
       if(swoi[i])
       if(x==swoi[i]->PozycjaX && y==swoi[i]->PozycjaY)
           return false;}

   for(int i=0;i<wrogowie.size();i++)
      {
           if(wrogowie[i])
           if(x==wrogowie[i]->PozycjaX && y==wrogowie[i]->PozycjaY)
           return false;
   }

   if(x>500 || x<0 || y>500 || y<0)
       return false;
   for(int i=0; i<this->przeszkody.size();i++)

   {
       if(przeszkody[i])
       if((x>(przeszkody[i]->getPosx()-(przeszkody[i]->getSzerokosc()/2)) &&
           x<(przeszkody[i]->getPosx()+(przeszkody[i]->getSzerokosc())/2)) ||
          ((y>(przeszkody[i]->getPosy()-(przeszkody[i]->getWysokosc())/2) &&
           y<(przeszkody[i]->getPosy()+(przeszkody[i]->getWysokosc())/2))))
           return false;
   }
   return true;
}

void CJednostka::przemiesc_sie()
{   qDebug()<<"Przemieszczam się";
   int nPozycjaY, nPozycjaX;
       if(this && jednostka_do_ataku){
           if(this->PozycjaX>jednostka_do_ataku->PozycjaX)
        {     nPozycjaX=this->PozycjaX-ruch();
            if(moge_zajac_miejsce(nPozycjaX,this->PozycjaY))
                this->PozycjaX=nPozycjaX;
            else {
                while(!moge_zajac_miejsce(nPozycjaX,this->PozycjaY))
                {
                    nPozycjaX=this->PozycjaX-losowy_ruch();
                }
            this->PozycjaX=nPozycjaX;
            }
        }

       if(this->PozycjaX<jednostka_do_ataku->PozycjaX)
       {
           nPozycjaX=this->PozycjaX+ruch();
           if(moge_zajac_miejsce(nPozycjaX,this->PozycjaY))
               this->PozycjaX=nPozycjaX;
           else {
               while(!moge_zajac_miejsce(nPozycjaX,this->PozycjaY))
               {
                   nPozycjaX=this->PozycjaX+losowy_ruch();
               }
           this->PozycjaX=nPozycjaX;
           }
       }

qDebug()<<"USTALONO X";

if(this->PozycjaY>jednostka_do_ataku->PozycjaY)
{     nPozycjaY=this->PozycjaY-ruch();
    if(moge_zajac_miejsce(this->PozycjaX,nPozycjaY))
        this->PozycjaY=nPozycjaY;
    else {
        while(!moge_zajac_miejsce(this->PozycjaX,nPozycjaY))
        {
            nPozycjaY=this->PozycjaY-losowy_ruch();
        }
    this->PozycjaY=nPozycjaY;
    }
}
if(this->PozycjaY<jednostka_do_ataku->PozycjaY)
{     nPozycjaY=this->PozycjaY+ruch();
    if(moge_zajac_miejsce(this->PozycjaX,nPozycjaY))
        this->PozycjaY=nPozycjaY;
    else {
        while(!moge_zajac_miejsce(this->PozycjaX,nPozycjaY))
        {
            nPozycjaY=this->PozycjaY+losowy_ruch();
        }
    this->PozycjaY=nPozycjaY;
    }
}
qDebug()<<"USTALONO Y";
       }
       else
           qDebug()<<"przemiesc_sie - pusty this or pusta jednostka_do_ataku";
}

double CJednostka::losuj(int Od, int Do){
   srand(time(NULL));
   int zakres=Do-Od;
   double losowanie=((rand()%zakres)+Od);
   return losowanie;
}

void CJednostka::umrzyj()
{
   if(this->zycie<=0)
       this->death=true;
}

int CJednostka::punkty_ataku()
{
   return bron->suma_obrazen+2*sila_ataku;
}

int CJednostka::punkty_obrony()
{
   return pancerz+0.5*doswiadczenie*wytrzymalosc;
}



void CJednostka::odejmij_zycie(int ile){

   this->zycie-=ile;
}

void CJednostka::strzal()
{   if(this){
   bron->strzel(this->nazwa,jednostka_do_ataku->nazwa);
       jednostka_do_ataku->odejmij_zycie(punkty_ataku());

   jednostka_do_ataku->umrzyj();
   if(jednostka_do_ataku->death)
       jednostka_do_ataku=NULL;
   }
   else
       qDebug()<<"Strzal pusty this";
}

bool CJednostka::mam_kogo_atakowac()
{
   if(jednostka_do_ataku!=NULL)
       return true;
   else
       return false;
}


bool CJednostka::in_range(CJednostka *jednostka_do_ataku)
{   qDebug()<<"in range()";
   if(jednostka_do_ataku){
       qDebug()<<"Jednostka do ataku istnieje";
   if(licz_odleglosc(jednostka_do_ataku)<zasieg)
   {   qDebug()<<"in_range1";
       return true;
   }

   else return false;
   }
   else {
       return false;
       qDebug()<<"in_range() jednostka_do_ataku_pusta";
   }
}




QString CJednostka::getNazwa()
{
   return this->nazwa;
}

QString CJednostka::getMessage()
{
   return this->message;
}

void CJednostka::setMessage(QString tekst)
{
this->message=tekst;
}

QString CJednostka::getFrakcja()
{
   return this->frakcja;
}

void CJednostka::setFrakcja(QString strona_konfliktu)
{
   this->frakcja=strona_konfliktu;
}

void CJednostka::setPozycjaX(int x)
{
   this->PozycjaX=x;
}

int CJednostka::getPozycjaX()
{
   return this->PozycjaX;
}

void CJednostka::setPozycjaY(int y)
{
   this->PozycjaY=y;
}

int CJednostka::getPozycjaY()
{
   return this->PozycjaY;
}

void CJednostka::setWrogowie(std::vector<CJednostka *> jednostki)
{
   this->wrogowie=jednostki;
}

void CJednostka::setSwoi(std::vector<CJednostka *> jednostki)
{
   this->swoi=jednostki;
}

void CJednostka::setPrzeszkody(std::vector<CPrzeszkoda *> przeszkody)
{
   this->przeszkody=przeszkody;
}

bool CJednostka::getDeath()
{
   return this->death;
}


void CJednostka::kto_w_zasiegu(int zas)
{
   for(int i=0;i<swoi.size();i++)
       if(licz_odleglosc(swoi[i])<zas)
           this->w_zasiegu.push_back(swoi[i]);
   for(int i=0;i<wrogowie.size();i++)
       if(licz_odleglosc(wrogowie[i])<zas)
           this->w_zasiegu.push_back(wrogowie[i]);

}

void CJednostka::awansuj()
{
  (this->doswiadczenie)++;
}

