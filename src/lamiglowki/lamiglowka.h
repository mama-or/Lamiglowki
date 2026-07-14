#ifndef LAMIGLOWKA_H
#define LAMIGLOWKA_H

#include "../plansze/plansza.h"
#include "../rozwiazania/rozwiazanie.h"
#include "../ograniczenia/ograniczenie.h"

class Lamiglowka
{
    public:
		virtual ~Lamiglowka() = default;
        
        virtual bool pobierzLamiglowke(std::string nazwaPliku);
        void wyswietlPlansze();
        
        virtual std::unique_ptr<Rozwiazanie> pierwszeRozwiazanie() const = 0;
        virtual bool czyPelneRozwiazanie(Rozwiazanie * rozw) const = 0;
        virtual bool czyNiepelneRozwiazanie(Rozwiazanie * rozw) const = 0;
    
    protected:
		std::unique_ptr<Plansza> plansza;
		std::vector<std::unique_ptr<Ograniczenie> > ograniczenia;
        
};

#endif
