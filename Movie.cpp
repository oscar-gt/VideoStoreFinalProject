/*
 * Movie.cpp
 *
 *  Created on: Mar 11, 2016
 *      Author: Oscar
 */

// Implementation of the base class Movie.h


#include "Movie.h"
#include<fstream>
#include<iostream>
using namespace std;

// ----------------------  Constructor ------------------

Movie::Movie()
{
	category = NULL;
	quantity = 0;
	format = NULL;
	directorFirst = "";
	directorLast = "";
	title = "";
	year = 0;
}

//  --------------------  Destructor ------------------
Movie::~Movie()
{

}

// --------------------  Operators  -------------------
// Note about operators:
// The <, >, and == operators will necessarily
// be implemented by each subclass, so the
// return values in this superclass don't
// mean anything.

// ----------------- Less Than Operator -------------------

bool Movie::operator<( const Movie & rhs ) const
{
	cout << "test < from Movie.cpp" << endl;
	return true;
}

// ------------------ Greater Than Operator ----------------

bool Movie::operator>( const Movie & rhs ) const
{
	return false;
}

// ------------------ Equal to Operator ---------------
bool Movie::operator==(const Movie & rhs ) const
		{
	return false;
	//	return !(*this < rhs || *this > rhs);
		}


// -------------------- Getter Functions --------------------

char Movie::getCategory() const
{
	return category;
}

char Movie::getFormat() const
{
	return format;
}

int Movie::getStock() const
{
	return quantity;
}

string Movie::getDirectorFirst() const
{
	return directorFirst;
}

string Movie::getDirectorLast() const
{
	return directorLast;
}

string Movie::getTitle() const
{
	return title;
}

int Movie::getYear() const
{
	return year;
}

// ------------------------ Getters and Setters ----------------------

void Movie::setCategory(char cat)
{
	category = cat;
}


void Movie::setDirectorFirst(string dir)
{
	directorFirst = dir;
}

void Movie::setDirectorLast(string dirLast)
{
	directorLast = dirLast;
}

void Movie::setTitle(string t)
{
	title = t;
}

void Movie::setYear(int yr)
{
	year = yr;
}

void Movie::setFormat(char f)
{
	format = f;
}

// ----------------- Change Stock Function ----------------

// Member function will attempt to add or subtract from
// a Movie's stock. If it subtracts more than there is
// in a Movie's stock, it will return false and not
// change anything.
bool Movie::changeStock(int addOrSubtractVal)
{
	if(quantity + addOrSubtractVal < 0)
	{
		return false;
	}
	else
	{
		quantity = quantity + addOrSubtractVal;
		return true;
	}

}

void Movie::displayMovie()
{
	// Going to format all non classics to display with the
	// same spacing.
	string movieType = (category == 'F') ? "Comedy":"Drama";

	// Director
	cout.setf(ios::left);
	cout.width(8);
	cout << this -> getDirectorFirst() << " ";
	cout.setf(ios::left);
	cout.width(15);
	cout << (this -> getDirectorLast() + "," ) ;

	// Title
	cout.setf(ios::left);
	cout.width(33);
	cout << (this -> getTitle() + "," ) ;

	// Release date
	cout.setf(ios::left);
	cout.width(4);
	cout << (this -> getYear()) <<",";
	//Stock
	cout << "  Current Stock:  " << this -> getStock() << ", " << movieType << endl;

}



