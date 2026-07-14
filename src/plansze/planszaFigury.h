#ifndef PLANSZA_FIGURY_H
#define PLANSZA_FIGURY_H

#include <iostream>
#include <vector>
#include "plansza.h"

class PlanszaFigury: public Plansza
{
    public:
        PlanszaFigury () {};
        virtual bool pobierzLamiglowke(std::string nazwaPliku);
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

#endif