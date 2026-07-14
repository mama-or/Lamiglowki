#ifndef UNIKALNY_WIERSZ_H
#define UNIKALNY_WIERSZ_H

#include "../rozwiazania/rozwiazanie.h"
#include "ograniczenie.h"
 
class UnikalnyWiersz: public Ograniczenie
{
	public:
		UnikalnyWiersz(int wiersz, int ileKolumn);
		virtual bool czySpelnia(Rozwiazanie *rozw);
	protected:
		int nrWiersza;
		int ile;
};

#endif