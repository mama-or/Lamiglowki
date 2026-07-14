#ifndef ROZWIAZANIE_PETLA_H
#define ROZWIAZANIE_PETLA_H

#include <vector>
#include "rozwiazanie.h"

class RozwiazaniePetla: public Rozwiazanie
{
    public:
        RozwiazaniePetla( ) {};
        RozwiazaniePetla( const int wierszy, const int kolumn );

		virtual std::unique_ptr<Rozwiazanie> kopiuj() const;
        
        virtual void wyswietlRozwiazanie() const;
        bool czyNiepelneRozwiazanie() const;
        virtual bool czyRozwiazanie() const;
        virtual void wstaw(const int wiersz, const int kolumna, const int liczba);
        virtual void pustaPozycja(int &wiersz, int &kolumna) const;
        virtual bool czyPelna() const;
        virtual std::vector<int> mozliweWartosci(const int wiersz, const int kolumna) const;
    private:
        int xStartowy, yStartowy;
		std::vector<char> rozwiazanie; // p - prawo, d - dol, l - lewo, g - gora
        int ileKolumn, ileWierszy;
        int dlugoscDrogi;
};

#endif