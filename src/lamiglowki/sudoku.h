#ifndef SUDOKU_H
#define SUDOKU_H

#include "../rozwiazania/rozwiazanie.h"
#include "lamiglowka.h"

class Sudoku: public Lamiglowka
{
    public:
        Sudoku();
		virtual bool pobierzLamiglowke(std::string nazwaPliku);
        virtual std::unique_ptr<Rozwiazanie> pierwszeRozwiazanie() const;
        virtual bool czyPelneRozwiazanie(Rozwiazanie * rozw) const;
        virtual bool czyNiepelneRozwiazanie(Rozwiazanie * rozw) const;

};


#endif