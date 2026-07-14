#ifndef UNIKALNA_KOLUMNA_H
#define UNIKALNA_KOLUMNA_H

#include "../rozwiazania/rozwiazanie.h"
#include "ograniczenie.h"
 
class UnikalnaKolumna: public Ograniczenie
{
	public:
		UnikalnaKolumna(int kolumna, int ileKolumn);
		virtual bool czySpelnia(Rozwiazanie *rozw);
	protected:
		int nrKolumny;
		int ile;
};

#endif