#ifndef UNIKALNY_PROSTOKAT_H
#define UNIKALNY_PROSTOKAT_H

#include "../rozwiazania/rozwiazanie.h"
#include "ograniczenie.h"
 
class UnikalnyProstokat: public Ograniczenie
{
	public:
		UnikalnyProstokat(int odX, int odY, int doX, int doY, int ile);
		virtual bool czySpelnia(Rozwiazanie *rozw);
	protected:
		int odX, doX, odY, doY;
		int ile;
};

#endif