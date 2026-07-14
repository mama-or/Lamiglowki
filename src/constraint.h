#ifndef CONSTRAINT_H
#define CONSTRAINT_H

#include "plansza.h"

class constraint {
public:
	virtual ~constraint();
	template< typename P >
	static consteval virtual bool applicable();
	virtual bool board_satisfies(plansza *p);
};

sudoku::line_constraint<2>::template applicable<plansza_prostokatna>()

sudoku::rect_constraint<0, 2, 0, 2>::template applicable<plansza_prostokatna>() -> true
sudoku::rect_constraint<0, 2, 0, 2>::template applicable<plansza_kwadratowa>()  -> true

sudoku::rect_constraint<plansza_prostokatna, 0, 2, 0, 2>::applicable() -> true
sudoku::rect_constraint<plansza_kwadratowa, 0, 2, 0, 2>::applicable()  -> true

#endif

