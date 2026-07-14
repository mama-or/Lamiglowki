#ifndef PLANSZA_H
#define PLANSZA_H

#include <iostream>

class Plansza
{
    public:
        virtual bool pobierzLamiglowke(std::string nazwaPliku) = 0;
        virtual void wyswietlPlansze() = 0;
		virtual ~Plansza() = default;
};

#endif
