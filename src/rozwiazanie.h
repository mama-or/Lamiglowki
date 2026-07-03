#ifndef ROZWIAZANIE_H
#define ROZWIAZANIE_H

#include <iostream>
#include <vector>

using namespace std;

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

/////////////////////////////////////////////////////////

class RozwiazanieSudoku: public Rozwiazanie
{
    public:
        RozwiazanieSudoku( const int wierszy, const int kolumn );
        RozwiazanieSudoku( ) {};

		virtual std::unique_ptr<Rozwiazanie> kopiuj() const;
        
        virtual void wyswietlRozwiazanie() const;
        bool czyNiepelneRozwiazanie() const;
        virtual bool czyRozwiazanie() const;
        virtual void wstaw(const int wiersz, const int kolumna, const int liczba);
        virtual void pustaPozycja(int &wiersz, int &kolumna) const;
        virtual bool czyPelna() const;
        virtual std::vector<int> mozliweWartosci(const int wiersz, const int kolumna) const;
    private:
        bool czyRozlaczneKolumny() const;
        bool czyRozlaczneWiersze() const;
        bool czyRozlaczneKwadraty() const;
    
		std::vector<std::vector<int> > rozwiazanie;
        int ileKolumn, ileWierszy;
};

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

/////////////////////////////////////////////////////////

class RozwiazaniePermutacje: public Rozwiazanie
{
    public:
        RozwiazaniePermutacje( ) {};
        RozwiazaniePermutacje(const int ile);

		virtual std::unique_ptr<Rozwiazanie> kopiuj() const;
        
        virtual void wyswietlRozwiazanie() const;
        bool czyNiepelneRozwiazanie() const;
        virtual bool czyRozwiazanie() const;
        virtual void wstaw(const int wiersz, const int kolumna, const int liczba);
        virtual void pustaPozycja(int &wiersz, int &kolumna) const;
        virtual bool czyPelna() const;
        virtual std::vector<int> mozliweWartosci(const int wiersz, const int kolumna) const;
        int getNr(const int ktora){ return rozwiazanie[ktora];};
    private:
        int najmniejszaWolna() const;
        bool czyRozlaczneLiczby() const;
        bool czyTrojkiPasuja() const;
		std::vector<int> rozwiazanie;
        int ileLiczb;
};

/////////////////////////////////////////////////////////

RozwiazanieSudoku::RozwiazanieSudoku( const int wierszy, const int kolumn ): ileKolumn (kolumn), ileWierszy(wierszy)
{
    rozwiazanie.resize(ileWierszy);
    for(int i=0; i<ileWierszy; i++)
        rozwiazanie[i].resize(ileKolumn);
}

std::unique_ptr<Rozwiazanie> RozwiazanieSudoku::kopiuj() const
{
	return std::make_unique<RozwiazanieSudoku>(*this);
}

void RozwiazanieSudoku::wstaw(const int wiersz, const int kolumna, const int liczba)
{
    rozwiazanie[wiersz][kolumna] = liczba;
}

void RozwiazanieSudoku::wyswietlRozwiazanie() const
{
    for(int i = 0; i<ileWierszy; ++i)
    {
        for(int j = 0; j<ileKolumn; ++j)
            cout << rozwiazanie[i][j];
        cout << endl;
    }
}

bool RozwiazanieSudoku::czyPelna() const
{
    for(int i = 0; i<ileWierszy; ++i)
        for(int j = 0; j<ileKolumn; ++j)
            if(rozwiazanie[i][j] == 0) return false;
    return true;
}

void RozwiazanieSudoku::pustaPozycja(int &wiersz, int &kolumna) const
{
    for(int i = 0; i<ileWierszy; ++i)
        for(int j = 0; j<ileKolumn; ++j)
            if(rozwiazanie[i][j] == 0)
            {
                wiersz = i;
                kolumna = j;
                return;
            }
}
bool RozwiazanieSudoku::czyRozlaczneKolumny() const
{
    for(int i = 0; i<ileWierszy; ++i)
    {
        for(int liczba = 1; liczba<=9; ++liczba)
        {
            int ile=0;
            for(int j = 0; j<ileKolumn; ++j)
                if(rozwiazanie[i][j] == liczba)
                    ++ile;
            if(ile>1) return false;
        }
    }
    return true;
}

bool RozwiazanieSudoku::czyRozlaczneWiersze() const
{
    for(int j = 0; j<ileWierszy; ++j)
    {
        for(int liczba = 1; liczba<=9; ++liczba)
        {
            int ile=0;
            for(int i = 0; i<ileKolumn; ++i)
                if(rozwiazanie[i][j] == liczba)
                    ++ile;
            if(ile>1) return false;
        }
    }
    return true;

}

bool RozwiazanieSudoku::czyRozlaczneKwadraty() const
{
    for(int a = 0; a<3; ++a)
        for(int b = 0; b<3; ++b)
        {
            for(int liczba = 1; liczba<=9; ++liczba)
            {
                int ile=0;
                for(int c = 0; c<3; ++c)
                    for(int d = 0; d<3; ++d)
                        if(rozwiazanie[3*a+b][3*c+d] == liczba)
                            ++ile;
                if(ile>1) return false;
            }
        }
    return true;
}

bool RozwiazanieSudoku::czyRozwiazanie() const
{
    return czyRozlaczneKolumny() && czyRozlaczneWiersze() && czyRozlaczneKwadraty();
}

bool RozwiazanieSudoku::czyNiepelneRozwiazanie() const
{
    return czyRozwiazanie();
}

std::vector<int> RozwiazanieSudoku::mozliweWartosci(const int wiersz, const int kolumna) const
{
	(void)wiersz;
	(void)kolumna;
	std::vector<int> vec;

	vec.reserve(9);
    for (int i=1;i<=9;i++)
        vec.push_back(i);
    return vec;
}

///////////////////////////////////////////////////////////

RozwiazaniePermutacje::RozwiazaniePermutacje(const int ile): ileLiczb(ile)
{
	rozwiazanie.resize(ileLiczb);
}

std::unique_ptr<Rozwiazanie> RozwiazaniePermutacje::kopiuj() const
{
	return std::make_unique<RozwiazaniePermutacje>(*this);
}

void RozwiazaniePermutacje::wstaw(const int wiersz, const int kolumna, const int liczba) // kolumna jest pomijana
{
	(void)kolumna;
    rozwiazanie[wiersz] = liczba;
}

void RozwiazaniePermutacje::wyswietlRozwiazanie() const
{
    for(int i = 0; i<ileLiczb; ++i)
    {
        cout << rozwiazanie[i] << " ";
        if(i%3==2)
            cout << endl;
    }
}

bool RozwiazaniePermutacje::czyPelna() const
{
    for(int i = 0; i<ileLiczb; ++i)
        if(rozwiazanie[i] == -1) return false;
    return true;
}

void RozwiazaniePermutacje::pustaPozycja(int &wiersz, int &kolumna) const // kolumna jest pomijana
{
    for(int i = 0; i<ileLiczb; ++i)
        if(rozwiazanie[i] == -1)
        {
            wiersz = i;
            kolumna = -1;
            return;
        }
}

bool RozwiazaniePermutacje::czyRozlaczneLiczby() const
{
    int ile;
    for(int liczba=0; liczba<ileLiczb; liczba++)
    {
        ile=0;
        for(int i=0; i<ileLiczb; i++)
            if(rozwiazanie[i]==liczba) ile++;
        if(ile>1) return false;
    }
    return true;
}
bool RozwiazaniePermutacje::czyRozwiazanie() const
{
    return czyRozlaczneLiczby(); 
}

bool RozwiazaniePermutacje::czyNiepelneRozwiazanie() const
{
    return czyRozwiazanie();
}

int RozwiazaniePermutacje::najmniejszaWolna() const
{
    int ile;
    for(int liczba=0; liczba<ileLiczb; liczba++)
    {
        ile=0;
        for(int i=0; i<ileLiczb; i++)
            if(rozwiazanie[i]==liczba) ile++;
        if(ile==0) return liczba;
    }
    return -1;
}
/*
list<int> RozwiazaniePermutacje::mozliweWartosci(const int wiersz, const int kolumna) const
{
    list<int> lista;
    if(wiersz%3==0)
        lista.push_back(najmniejszaWolna());
    else 
        for(int i=rozwiazanie[wiersz-1]+1; i<=17; i++)
            lista.push_back(i);
    return lista;
}
*/
std::vector<int> RozwiazaniePermutacje::mozliweWartosci(const int wiersz, const int kolumna) const
{
	(void)wiersz;
	(void)kolumna;
	std::vector<int> vec;

	vec.reserve(ileLiczb);
    for(int i=0; i<ileLiczb; i++)
        vec.push_back(i);
    return vec;
}

///////////////////////////////////////////////////////////

RozwiazaniePetla::RozwiazaniePetla( const int wierszy, const int kolumn )
{
	rozwiazanie.resize((ileWierszy+1) * (ileKolumn+1));
    
    ileKolumn = kolumn;
    ileWierszy = wierszy;
    dlugoscDrogi = 0;
    xStartowy = -1;
    yStartowy = -1;
}
void RozwiazaniePetla::wyswietlRozwiazanie() const
{
    int tablica[ileWierszy][ileKolumn];
    
    for(int i=0; i<ileWierszy; i++) 
        for(int j=0; j<ileKolumn; j++) 
            tablica[i][j] = 0;
    
    int x = xStartowy;
    int y = yStartowy;
    
    if(dlugoscDrogi>0) tablica[x][y] = 1;
    
    for(int i=0; i<dlugoscDrogi; i++)
    {
        if(rozwiazanie[i]=='d') y++;
        if(rozwiazanie[i]=='g') y--;
        if(rozwiazanie[i]=='p') x++;
        if(rozwiazanie[i]=='l') x--;
        tablica[x][y] = 1;
    }
    for(int i=0; i<ileWierszy; i++) 
    {
        for(int j=0; j<ileKolumn; j++) 
            cout << tablica[i][j] << " ";
        cout <<endl;
    }
}

bool RozwiazaniePetla::czyNiepelneRozwiazanie() const
{
    return true;
}
bool RozwiazaniePetla::czyRozwiazanie() const
{
    return true;
}
std::unique_ptr<Rozwiazanie> RozwiazaniePetla::kopiuj() const
{
	return std::make_unique<RozwiazaniePetla>(*this);
}
void RozwiazaniePetla::wstaw(const int wiersz, const int kolumna, const int liczba) //1 - prawo, 2-dol, 3-lewo, 4-gora, wiersz i kolumna sa pomijane
{
	(void)wiersz;
	(void)kolumna;
    dlugoscDrogi++;
    if(liczba==1)
        rozwiazanie[dlugoscDrogi] = 'p';
    else if(liczba==2)
        rozwiazanie[dlugoscDrogi] = 'd';
    else if(liczba==3)
        rozwiazanie[dlugoscDrogi] = 'l';
    else if(liczba==4)
        rozwiazanie[dlugoscDrogi] = 'g';

}
void RozwiazaniePetla::pustaPozycja(int &wiersz, int &kolumna) const // zarowno wiersz jak i kolumna sa pomijane
{
    wiersz = 0;
    kolumna = 0;
}

bool RozwiazaniePetla::czyPelna() const // czy pelna petla, na razie nie sprawdzam czy sie przecina
{
    int pion = 0;
    int poziom = 0;
    for(int i=0; i<dlugoscDrogi; i++)
    {
        if(rozwiazanie[i]=='d') pion++;
        if(rozwiazanie[i]=='g') pion--;
        if(rozwiazanie[i]=='p') poziom++;
        if(rozwiazanie[i]=='l') poziom--;
    }
    if(pion==0 && poziom==0) return true;
    return false;
}

//1 - prawo, 2-dol, 3-lewo, 4-gora, wiersz i kolumna sa pomijane
std::vector<int> RozwiazaniePetla::mozliweWartosci(const int wiersz, const int kolumna) const
{
	(void)wiersz;
	(void)kolumna;
	std::vector<int> vec;

	vec.reserve(4);
    if(dlugoscDrogi==0)
    {
        vec.push_back(1); // prawo
        vec.push_back(2); // dol
        vec.push_back(3); // lewo
        vec.push_back(4); // gora
    }
    else if(rozwiazanie[dlugoscDrogi-1]=='g') 
    {
        vec.push_back(1); // prawo
        vec.push_back(3); // lewo
        vec.push_back(4); // gora
    }
    else if(rozwiazanie[dlugoscDrogi-1]=='d') 
    {
        vec.push_back(1); // prawo
        vec.push_back(2); // dol
        vec.push_back(3); // lewo
    }
    else if(rozwiazanie[dlugoscDrogi-1]=='p') 
    {
        vec.push_back(1); // prawo
        vec.push_back(2); // dol
        vec.push_back(4); // gora
    }
    else if(rozwiazanie[dlugoscDrogi-1]=='l') 
    {
        vec.push_back(2); // dol
        vec.push_back(3); // lewo
        vec.push_back(4); // gora
    }
    
    return vec;
}

#endif
