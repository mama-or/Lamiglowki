#ifndef PLANSZA_H
#define PLANSZA_H

#include <fstream>
#include <iostream>
using namespace std;

class Plansza
{
    public:
        virtual bool pobierzLamiglowke(string nazwaPliku) = 0;
        virtual void wyswietlPlansze() = 0;
};
///////////////////////////////////////////////////////////////////////////////////

class PlanszaProstokatna: public Plansza
{
    public:
        PlanszaProstokatna () {};
        ~ PlanszaProstokatna ();
        virtual bool pobierzLamiglowke(string nazwaPliku);
        virtual void wyswietlPlansze();
        int getIleKolumn() const {return ileKolumn;};
        int getIleWierszy() const {return ileWierszy;};
        int getPlansza(const int wiersz, const int kolumna) const {return plansza[wiersz][kolumna];};

     private:
        int **plansza;
        int ileKolumn;
        int ileWierszy;

};

PlanszaProstokatna::~PlanszaProstokatna ()
{
    for(int i=0; i<ileWierszy; i++)
    {
        if(plansza[i]!=0)
            delete [] plansza[i];
        plansza[i]=0;
    }
    if(plansza!=0)
        delete [] plansza;    
    plansza = 0;
}

bool PlanszaProstokatna::pobierzLamiglowke(string nazwaPliku)
{
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku!" << endl;
        return false;
    }
    plik >> ileKolumn >> ileWierszy;
    
    plansza = new int*[ileWierszy];
    for(int i=0; i<ileWierszy; i++)
        plansza[i] = new int[ileKolumn];

    for(int i = 0; i<ileWierszy; ++i)
        for(int j = 0; j<ileKolumn; ++j)
            plik >> plansza[i][j];
    plik.close();
    return true;
}

void PlanszaProstokatna::wyswietlPlansze()
{
    for(int i = 0; i<ileWierszy; ++i)
    {
        for(int j = 0; j<ileKolumn; ++j)
            cout << plansza[i][j];
        cout << endl;
    }
}
////////////////////////////////////////////////////////////////////////

class PlanszaFigury: public Plansza
{
    public:
        PlanszaFigury () {};
        ~ PlanszaFigury ();
        virtual bool pobierzLamiglowke(string nazwaPliku);
        virtual void wyswietlPlansze();
        int getIleFigur() const {return ileFigur;};
        int getKsztalt( const int figura) const {return ksztalty[figura];};
        int getKolorWnetrza( const int figura) const {return koloryWnetrza[figura];};
        int getKolorRamki( const int figura) const {return koloryRamki[figura];};
        int getWzorWnetrza( const int figura) const {return wzoryWnetrza[figura];};

     private:
        char *ksztalty;
        char *koloryWnetrza;
        char *koloryRamki;
        char *wzoryWnetrza;
        int ileFigur;
};

PlanszaFigury::~PlanszaFigury ()
{
    if(ksztalty!=0)
        delete [] ksztalty;
    ksztalty = 0;

    if(koloryWnetrza!=0)
        delete [] koloryWnetrza;
    koloryWnetrza = 0;

    if(koloryRamki!=0)
        delete [] koloryRamki;
    koloryRamki = 0;


    if(wzoryWnetrza!=0)
        delete [] wzoryWnetrza;
    wzoryWnetrza = 0;
}

bool PlanszaFigury::pobierzLamiglowke(string nazwaPliku)
{
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku!" << endl;
        return false;
    }
    plik >> ileFigur;
    
    ksztalty = new char[ileFigur];
    koloryWnetrza = new char[ileFigur];
    koloryRamki = new char[ileFigur];
    wzoryWnetrza = new char[ileFigur];

    for(int i = 0; i<ileFigur; ++i)
        plik >> ksztalty[i] >> koloryWnetrza[i] >> koloryRamki[i] >> wzoryWnetrza[i];
    plik.close();
    return true;
}

void PlanszaFigury::wyswietlPlansze()
{
    for(int i = 0; i<ileFigur; ++i)
        cout << ksztalty[i] << koloryWnetrza[i] << koloryRamki[i] << wzoryWnetrza[i] << endl;
}

#endif