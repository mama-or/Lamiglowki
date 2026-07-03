#ifndef PLANSZA_H
#define PLANSZA_H

#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Plansza
{
    public:
        virtual bool pobierzLamiglowke(string nazwaPliku) = 0;
        virtual void wyswietlPlansze() = 0;
		virtual ~Plansza() = default;
};
///////////////////////////////////////////////////////////////////////////////////

class PlanszaProstokatna: public Plansza
{
    public:
        PlanszaProstokatna () {};
        virtual bool pobierzLamiglowke(string nazwaPliku);
        virtual void wyswietlPlansze();
        int getIleKolumn() const {return ileKolumn;};
        int getIleWierszy() const {return ileWierszy;};
        int getPlansza(const int wiersz, const int kolumna) const {return plansza[wiersz][kolumna];};

     private:
		std::vector<std::vector<int> > plansza;
        int ileKolumn;
        int ileWierszy;

};

bool PlanszaProstokatna::pobierzLamiglowke(string nazwaPliku)
{
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku!" << endl;
        return false;
    }
    plik >> ileKolumn >> ileWierszy;
    
	plansza.resize(ileWierszy);
    for(int i = 0; i<ileWierszy; ++i) {
		plansza[i].resize(ileKolumn);
        for(int j = 0; j<ileKolumn; ++j)
            plik >> plansza[i][j];
	}

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
        virtual bool pobierzLamiglowke(string nazwaPliku);
        virtual void wyswietlPlansze();
        int getIleFigur() const {return ileFigur;};
        int getKsztalt( const int figura) const {return ksztalty[figura];};
        int getKolorWnetrza( const int figura) const {return koloryWnetrza[figura];};
        int getKolorRamki( const int figura) const {return koloryRamki[figura];};
        int getWzorWnetrza( const int figura) const {return wzoryWnetrza[figura];};

     private:
		std::vector<char> ksztalty;
        std::vector<char> koloryWnetrza;
        std::vector<char> koloryRamki;
        std::vector<char> wzoryWnetrza;
        int ileFigur;
};

bool PlanszaFigury::pobierzLamiglowke(string nazwaPliku)
{
    ifstream plik(nazwaPliku);

    if (!plik.is_open()) {
        cout << "Nie udało się otworzyć pliku!" << endl;
        return false;
    }
    plik >> ileFigur;
    
	ksztalty.resize(ileFigur);
	koloryWnetrza.resize(ileFigur);
	koloryRamki.resize(ileFigur);
	wzoryWnetrza.resize(ileFigur);

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
