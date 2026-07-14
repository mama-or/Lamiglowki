#ifndef ZNAJDZ_TRZY_H
#define ZNAJDZ_TRZY_H

#include <memory>
#include "../plansze/planszaFigury.h"
#include "../rozwiazania/rozwiazanie.h"
#include "lamiglowka.h"

class ZnajdzTrzy: public Lamiglowka
{
    public:
		ZnajdzTrzy();
		bool pobierzLamiglowke(std::string nazwaPliku);
        std::unique_ptr<Rozwiazanie> pierwszeRozwiazanie() const;
        bool czyPelneRozwiazanie(Rozwiazanie * rozw) const;
        bool czyNiepelneRozwiazanie(Rozwiazanie * rozw) const;
    private:
        bool czyFiguryPasuja(const int figura1, const int figura2, const int figura3) const;
};

#endif
