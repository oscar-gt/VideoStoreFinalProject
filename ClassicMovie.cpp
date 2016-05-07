/*
 * ClassicMovie.cpp
 *
 *  Created on: Mar 11, 2016
 *      Author: Oscar
 */



#include "ClassicMovie.h"
#include<fstream>
#include<iostream>
using namespace std;

// Implementation of derived class ClassicMovie.h

// Constructor
ClassicMovie::ClassicMovie(): Movie(), actorFirst(""), actorLast(""), month(0)
{
	// Nothing to do here.
}

// Destructor
ClassicMovie::~ClassicMovie()
{

}

// ------------------------ Operators -----------------------

// For a classic movie, we need to compare release
// dates then major actor. So first compare year,
// then month, and if year and month are the same,
// compare major actor.

bool ClassicMovie::operator<( const Movie & rhs ) const
{
	const ClassicMovie & cm = dynamic_cast<const ClassicMovie&>(rhs);
	// Checking year first
	if(this->getYear() < rhs.getYear() )
	{
		return true;
	}
	else if(this->getYear() > rhs.getYear() )
	{
		return false;
	}

	// At this point, they have the same release year

	// Checking month
	else if(this->getMonth() < cm.getMonth() )
	{
		return true;
	}
	else if(this->getMonth() > cm.getMonth() )
	{
		return false;
	}

	// At this point, they have the same release year and month

	// Checking actors
	else if(this->getActorLast() < cm.getActorLast() )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ClassicMovie::operator>( const Movie & rhs ) const
{
	const ClassicMovie & cm = dynamic_cast<const ClassicMovie&>(rhs);
	// Checking year first
	if((this->getYear() ) > rhs.getYear() )
	{
		return true;
	}
	else if(this->getYear() < rhs.getYear() )
	{
		return false;
	}

	// At this point, they have the same release year

	// Checking month
	else if(this->getMonth() > cm.getMonth() )
	{
		return true;
	}
	else if(this->getMonth() < cm.getMonth() )
	{
		return false;
	}

	// At this point, they have the same release year and month

	// Checking actors
	else if(this->getActorLast() > cm.getActorLast() )
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool ClassicMovie::operator==( const Movie & rhs ) const
				{
	const ClassicMovie & cm = dynamic_cast<const ClassicMovie&>(rhs);


	return(this->getMonth() == cm.getMonth()
			&& this->getYear() == cm.getYear());
				}

// ------------------ Setter and Getter Functions -------------

void ClassicMovie::setActorFirst(string act)
{
	actorFirst = act;
}

void ClassicMovie::setActorLast(string actLast)
{
	actorLast = actLast;
}
void ClassicMovie::setMonth(int m)
{
	month = m;
}

string ClassicMovie::getActorFirst() const
{
	return actorFirst;
}

string ClassicMovie::getActorLast() const
{
	return actorLast;
}

int ClassicMovie::getMonth() const
{
	return month;
}

void ClassicMovie::displayMovie()
{

	// Director
	cout.setf(ios::left);
	cout.width(8);
	cout << this -> getDirectorFirst() << " ";
	cout.setf(ios::left);
	cout.width(15);
	cout << (this -> getDirectorLast() + "," ) ;

	// Title
	cout.setf(ios::left);
	cout.width(28);
	cout << (this -> getTitle() + "," ) ;

	// Major actress/actor
	cout.setf(ios::left);
	cout.width(12);
	cout <<this -> getActorFirst() << " ";
	cout.setf(ios::left);
	cout.width(15);
	cout << this -> getActorLast() << " ";

	// Release date
	cout.setf(ios::left);
	cout.width(2);
	cout << this -> getMonth() << " ";
	cout << this -> getYear();
	//Stock
	cout << ", Current Stock:  " << this -> getStock() << ", Classic"<< endl;
}

