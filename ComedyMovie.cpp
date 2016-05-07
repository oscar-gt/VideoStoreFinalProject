/*
 * ComedyMovie.cpp
 *
 *  Created on: Mar 12, 2016
 *      Author: Oscar
 */

#include "ComedyMovie.h"
#include<fstream>
#include<iostream>
using namespace std;

// Constructor
ComedyMovie::ComedyMovie(): Movie()
{
	// Nothing to do
}

// Destructor
ComedyMovie::~ComedyMovie()
{

}

// -------------------- Operators ----------------------

bool ComedyMovie::operator<( const Movie & rhs ) const
{
	// Casting to a Comedy Movie
	const ComedyMovie & cm = dynamic_cast<const ComedyMovie&>(rhs);

	// Checking director first
	if(this -> getTitle() < cm.getTitle() )
	{
		return true;
	}
	else if(this -> getTitle() > cm.getTitle() )
	{
		return false;
	}
	// At this point, lhs and rhs have the same director
	// Now checking release year
	else if(this -> getYear() < cm.getYear() )
	{
		return true;
	}
	else // Year must be greater than or equal, but not <
	{
		return false;
	}
}

bool ComedyMovie::operator>( const Movie & rhs ) const
{
	// Casting to a Comedy Movie

	const ComedyMovie & cm = dynamic_cast<const ComedyMovie&>(rhs);

	// Checking director first
	if(this -> getTitle() > cm.getTitle() )
	{
		return true;
	}
	else if(this -> getTitle() < cm.getTitle() )
	{
		return false;
	}
	// At this point, lhs and rhs have the same director
	// Now checking release year
	else if(this -> getYear() > cm.getYear() )
	{
		return true;
	}
	else // Year must be greater than or equal, but not <
	{
		return false;
	}
}

bool ComedyMovie::operator==( const Movie & rhs ) const
{
	const ComedyMovie & cm = dynamic_cast<const ComedyMovie&>(rhs);
	return !(*this < cm || *this > cm);
}

