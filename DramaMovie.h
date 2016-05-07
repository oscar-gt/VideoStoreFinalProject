/*
 * DramaMovie.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Oscar
 */

/*
 * 	DramaMovie object is a subclass of a Movie and
 * 	represents a drama movie with the additional.
 *
 */

#ifndef DRAMAMOVIE_H_
#define DRAMAMOVIE_H_

#include "Movie.h"
class DramaMovie:public Movie
{
public:

	// Constructor
	DramaMovie();

	// Destructor
	~DramaMovie();

	// Operators
	virtual bool operator< ( const Movie & rhs ) const;
	virtual bool operator> ( const Movie & rhs ) const;
	virtual bool operator== (const Movie & rhs ) const;
};
#endif /* DRAMAMOVIE_H_ */
