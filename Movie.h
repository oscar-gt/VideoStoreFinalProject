/*
 * Movie.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Oscar Garcia-Telles
 *
 */

/*
 *  Movie class is a superclass to represent
 *  information about a movie.
 */

#ifndef MOVIE_H_
#define MOVIE_H_

#include <string>
#include <fstream>
using namespace std;

class Movie
{
public:

	// Constructor
	Movie();

	// Destructor
	virtual ~Movie();

	// Operators
	virtual bool operator<( const Movie & rhs ) const;
	virtual bool operator>( const Movie & rhs ) const;
	virtual bool operator==(const Movie & rhs ) const;

	char getCategory() const;		// Returns Movie's category
	char getFormat() const; 		// Returns Movie's format
	int getStock() const;			// Returns current number of this movie
	string getDirectorFirst() const;		// Returns Movie's director
	string getDirectorLast() const;
	string getTitle() const;		// Returns Movie's title
	int getYear() const; 			// Returns Movie's theatrical
									// release year
	virtual void displayMovie();
	// Setter functions
	void setCategory(char cat);
	bool changeStock(int changeVal);
	void setDirectorFirst(string dir);
	void setDirectorLast(string dirLast);
	void setTitle(string t);
	void setYear(int yr);

	void setFormat(char f);

private:

	char category;		// Movie's category
	int quantity;		// Number of copies
	char format;		// DVD, vhs, etc
	string directorFirst;	// Movie's director
	string directorLast;
	string title;		// Movie's title
	int year;			// Movie's theatrical release year
};
#endif /* MOVIE_H_ */
