#ifndef ROZWIAZANIE_H
#define ROZWIAZANIE_H

#include <vector>
#include <memory>

class Rozwiazanie
{
    public: 
        virtual void wyswietlRozwiazanie() const = 0;
		virtual std::unique_ptr<Rozwiazanie> kopiuj() const = 0;
        virtual bool czyNiepelneRozwiazanie() const = 0;
        virtual bool czyRozwiazanie() const = 0;
        virtual void wstaw(const int wiersz, const int kolumna, const int liczba) = 0;
        virtual void pustaPozycja(int &wiersz, int &kolumna) const = 0;
        virtual bool czyPelna() const = 0;
        virtual std::vector<int> mozliweWartosci(const int wiersz, const int kolumna) const = 0;
		virtual ~Rozwiazanie() = default;
};

#endif
