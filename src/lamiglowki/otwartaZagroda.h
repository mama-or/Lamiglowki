#ifndef OTWARTA_ZAGRODA_H
#define OTWARTA_ZAGRODA_H

#include <memory>
#include "../plansze/planszaProstokatna.h"
#include "../rozwiazania/rozwiazanie.h"
#include "lamiglowka.h"

class OtwartaZagroda: public Lamiglowka
{
    public:
		virtual bool pobierzLamiglowke(std::string nazwaPliku);
        OtwartaZagroda(){ plansza = std::make_unique<PlanszaProstokatna>(); };
        virtual std::unique_ptr<Rozwiazanie> pierwszeRozwiazanie() const;
        virtual bool czyPelneRozwiazanie(Rozwiazanie * rozw) const;
        virtual bool czyNiepelneRozwiazanie(Rozwiazanie * rozw) const;
};

#endif
