#ifndef ROZWIAZANIE_PERMUTACJE_H
#define ROZWIAZANIE_PERMUTACJE_H

#include <vector>
#include "rozwiazanie.h"

class RozwiazaniePermutacje: public Rozwiazanie
{
    public:
        RozwiazaniePermutacje( ) {};
        RozwiazaniePermutacje(const int ile);

		virtual std::unique_ptr<Rozwiazanie> kopiuj() const;
        
        virtual void wyswietlRozwiazanie() const;
        bool czyNiepelneRozwiazanie() const;
        virtual bool czyRozwiazanie() const;
        virtual void wstaw(const int wiersz, const int kolumna, const int liczba);
        virtual void pustaPozycja(int &wiersz, int &kolumna) const;
        virtual bool czyPelna() const;
        virtual std::vector<int> mozliweWartosci(const int wiersz, const int kolumna) const;
        int getNr(const int ktora){ return rozwiazanie[ktora];};
    private:
        int najmniejszaWolna() const;
        bool czyRozlaczneLiczby() const;
        bool czyTrojkiPasuja() const;
		std::vector<int> rozwiazanie;
        int ileLiczb;
};

#endif