#ifndef ROZWIAZANIE_PROSTOKATNE_H
#define ROZWIAZANIE_PROSTOKATNE_H

#include <vector>
#include "rozwiazanie.h"

class RozwiazanieProstokatne: public Rozwiazanie
{
    public:
        RozwiazanieProstokatne( const int wierszy, const int kolumn );
        RozwiazanieProstokatne( ) {};

		virtual std::unique_ptr<Rozwiazanie> kopiuj() const;
        
        virtual void wyswietlRozwiazanie() const;
        bool czyNiepelneRozwiazanie() const;
        virtual bool czyRozwiazanie() const;
        virtual void wstaw(const int wiersz, const int kolumna, const int liczba);
        virtual void pustaPozycja(int &wiersz, int &kolumna) const;
        virtual bool czyPelna() const;
        virtual std::vector<int> mozliweWartosci(const int wiersz, const int kolumna) const;
		virtual int wartosc(int wiersz, int kolumna);
    private:
        bool czyRozlaczneKolumny() const;
        bool czyRozlaczneWiersze() const;
        bool czyRozlaczneKwadraty() const;
    
		std::vector<std::vector<int> > rozwiazanie;
        int ileKolumn, ileWierszy;
};

#endif