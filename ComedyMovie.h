/*
 * ComedyMovie.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Oscar
 */

/*
 * 	ComedyMovie object is a subclass of a Movie and
 * 	represents a comedy movie with the additional.
 *
 */
#ifndef COMEDYMOVIE_H_
#define COMEDYMOVIE_H_

#include "Movie.h"
class ComedyMovie:public Movie
{
public:

	// Constructor
	ComedyMovie();

	// Destructor
	~ComedyMovie();

	// Operators
	virtual bool operator< ( const Movie & rhs ) const;
	virtual bool operator> ( const Movie & rhs ) const;
	virtual bool operator== (const Movie & rhs ) const;
};
#endif /* COMEDYMOVIE_H_ */
