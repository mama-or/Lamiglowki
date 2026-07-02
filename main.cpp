#include <iostream>
#include "algorytm.h"
#include "lamiglowka.h"

using namespace std;

Sudoku lamiglowka;
string nazwaPliku = "sudoku.txt";

//ZnajdzTrzy lamiglowka;
//string nazwaPliku = "znajdz trzy.txt";


//string nazwaPliku = "otwarta zagroda.txt";

int main()
{
    if(!lamiglowka.pobierzLamiglowke(nazwaPliku)) return false;
    cout << "Plansza:"<<endl;
    lamiglowka.wyswietlPlansze();

    algorytm(lamiglowka);

    return 0;
}