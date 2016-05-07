/*
 * ClassicMovie.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Oscar
 */

/*
 * 	ClassicMovie object is a subclass of a Movie and
 * 	represents a classic movie with the additional
 * 	actor and month data members.
 *
 */

#ifndef CLASSICMOVIE_H_
#define CLASSICMOVIE_H_

#include "Movie.h"
class ClassicMovie:public Movie
{
public:

	// Constructor
	ClassicMovie();

	// Destructor
	~ClassicMovie();

	// Operators
	virtual bool operator< ( const Movie & rhs ) const;
	virtual bool operator>( const Movie & rhs ) const;
	virtual bool operator==(const Movie & rhs ) const;

	virtual void displayMovie();
	void setActorFirst(string act);
	void setActorLast(string actLast);
	void setMonth(int m);
	string getActorFirst() const;	// Returns lead actor/actress
	string getActorLast() const;
	int getMonth() const;		// Returns release month

private:
	string actorFirst;	// Lead actor/actress in ClassicMovie
	string actorLast;
	int month;		// Release month of ClassicMovie
};

#endif /* CLASSICMOVIE_H_ */
