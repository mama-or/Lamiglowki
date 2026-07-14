#ifndef PLANSZA_PROSTOKATNA_H
#define PLANSZA_PROSTOKATNA_H

#include <iostream>
#include <vector>

#include "plansza.h"

class PlanszaProstokatna: public Plansza
{
    public:
        PlanszaProstokatna () {};
        virtual bool pobierzLamiglowke(std::string nazwaPliku);
        virtual void wyswietlPlansze();
        int getIleKolumn() const {return ileKolumn;};
        int getIleWierszy() const {return ileWierszy;};
        int getPlansza(const int wiersz, const int kolumna) const {return plansza[wiersz][kolumna];};

     private:
		std::vector<std::vector<int> > plansza;
        int ileKolumn;
        int ileWierszy;
};

#endif