/*
 * MovieFactory.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Team CompileDriver:
 *      		Drew Anderson
 *      		Oscar Garcia-Telles
 *      		Logan McArthur
 */

/*
 *      		MovieFactory: Static class to extract data from an
 *      		input stream and convert it into a movie object
 *      		and return that object.
 */

#ifndef MOVIEFACTORY_H_
#define MOVIEFACTORY_H_

#include "Movie.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include <fstream>
class MovieFactory
{
public:

	// Creates a Movie object
	static Movie* makeMovie(ifstream &file);

private:
	// Helper to fill in movie data
	static void fillMovie(Movie* m, ifstream &file);
};

#endif /* MOVIEFACTORY_H_ */
