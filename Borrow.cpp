/*
 * Borrow.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: Oscar
 */

#include "Borrow.h"
#include<iostream>
using namespace std;

// Implementation of Borrow.h
// Represents a customer command, which
// attempts to decrease a movie's stock
// by 1. Error message is returned if
// stock is 0.

// Constructor
Borrow::Borrow()
{
	customerID = -1;
	category = NULL;
	commandMovie = NULL;
}

// Destructor
Borrow::~Borrow()
{
	cout << "From ~Borrow()" << endl;
	//delete commandMovie;
}

// I couldn't get execute to work..
void Borrow::execute(Business B)
{
	// First checking if customer exists
	Customer* probablyExists = B.getCustomer(customerID);
	if(probablyExists == NULL)
	{
		cout << "Borrow could not find customerID" << endl;
		return;
	}
	cout << "From borrow, found customer is ";
	probablyExists->displayCustomer();

	// Now checking if movie exists and if it can be borrowed.

	// Will find movie first.
	Movie* find = B.findMovieBusiness(commandMovie);
	if(find == NULL)
	{
		cout << "Borrow could not find movie" << endl;
		return;
	}

	cout << "From Borrow, found movie is:   ";
	find->displayMovie();

	// Will check to see if there's at least 1 movie to borrow.
	bool didBorrow;
	didBorrow = find->changeStock(-1);
	if(didBorrow == false)
	{
		cout << "Borrow could not borrow movie, not enough stock" << endl;
		return;
	}

	// At this point, there was a movie in stock that was
	// borrowed, so need to add this transaction to customers]
	// history.

	probablyExists->insertCustomerAction(category, find);


}



