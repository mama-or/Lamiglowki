#ifndef OGRANICZENIE_POZIOME_H
#define OGRANICZENIE_POZIOME_H

#include "plansza.h"
 
 namespace ograniczenia {
	class Poziome: public Ograniczenie
	{
		public:
			template<typename TypPlanszy> 
				static consteval bool czyMoznaZaaplikowacDo(); 
			virtual bool czySpelnia(Plansza *plansza);
		protected:
			int wiersz;
	};
 }

template < typename TypPlanszy >
static consteval bool ograniczenia::Poziome::template czyMoznaZaaplikowacDo<TypPlanszy>()
{
	if constexpr (typeof(TypPlanszy) == typeof(PlanszaProstokatna)) 
	{
		return true;
	} 
	else 
	{
		return false;
	}
}


#endif