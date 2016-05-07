/*
 * DramaMovie.cpp
 *
 *  Created on: Mar 12, 2016
 *      Author: Oscar
 */
#include "DramaMovie.h"
#include<fstream>
#include<iostream>
using namespace std;

// Implementation of DramaMovie.h

// Constructor
DramaMovie::DramaMovie(): Movie()
{
	// Nothing to do
}

// Destructor
DramaMovie::~DramaMovie()
{

}
// -------------------- Operators ----------------------

bool DramaMovie::operator<( const Movie & rhs ) const
{
	// Casting to a Drama Movie
	const DramaMovie & cm = dynamic_cast<const DramaMovie&>(rhs);

	// Checking director first
	if(this -> getDirectorLast() < cm.getDirectorLast() )
	{
		return true;
	}
	else if(this -> getDirectorLast() > cm.getDirectorLast() )
	{
		return false;
	}
	// At this point, lhs and rhs have the same director
	// Now checking Title
	else if(this -> getTitle() < cm.getTitle() )
	{
		return true;
	}
	else // Year must be greater than or equal, but not <
	{
		return false;
	}
}

bool DramaMovie::operator>( const Movie & rhs ) const
{
	// Casting to a Comedy Movie

	const DramaMovie & cm = dynamic_cast<const DramaMovie&>(rhs);

	// Checking director first
	if(this -> getDirectorLast() > cm.getDirectorLast() )
	{
		return true;
	}
	else if(this -> getDirectorLast() < cm.getDirectorLast() )
	{
		return false;
	}
	// At this point, lhs and rhs have the same director
	// Now checking release year
	else if(this -> getTitle() > cm.getTitle() )
	{
		return true;
	}
	else // Year must be greater than or equal, but not <
	{
		return false;
	}
}

bool DramaMovie::operator==( const Movie & rhs ) const
{
	const DramaMovie & cm = dynamic_cast<const DramaMovie&>(rhs);
	return !(*this < cm || *this > cm);
}

