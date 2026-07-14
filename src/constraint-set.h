#ifndef CONSTRAINT_SET_H
#define CONSTRAINT_SET_H

#include "constraint.h"
#include "plansza.h"

template < typename P >
class constraint_set {
public:
	template < typename C >
		requires std::is_base_of<constraint, C>
	consteval constraint_set<P> &operator+=(C const& c);
	bool operator()(P const& plansza);
}

template< typename P, typename C >
	requires ( std::is_base_of<constraint, C> && C::template applicable<P>() )
constval constraint_set<P> &constraint_set<P>::operator+=(C const& c) {
	/* tutaj dodac c do jakiejs listy constraintow */
}


/* usage:
 * constraint_set<plansza_kwadratowa> cs;
 * constraint_set<plansza_liniowa> cs2;
 * cs += sudoku::line_constraint<0>();
 * cs2+= sudoku::line_constraint<0>(); // error w compile-timie
 *
 * plansza_kwadratowa p;
 * cs(p);
 * */

#endif

