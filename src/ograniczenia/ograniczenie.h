#ifndef OGRANICZENIE_H
#define OGRANICZENIE_H

#include "../rozwiazania/rozwiazanie.h"
 
class Ograniczenie
{
	public:
		virtual ~Ograniczenie() = default;
	/*	template<typename TypPlanszy> 
			static consteval bool czyMoznaZaaplikowacDo() = 0; */
		virtual bool czySpelnia(Rozwiazanie *rozw) = 0;
};

#endif