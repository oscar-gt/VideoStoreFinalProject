/*
 * Return.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: Oscar
 */

#include "Return.h"
#include<iostream>
using namespace std;

//Implements Return.h

// Constructor
Return::Return()
{

}

// Destructor
Return::~Return()
{

}

// Does not work..
void Return::execute(Business B)
{

	Customer* probablyExists = B.getCustomer(customerID);
	if(probablyExists == NULL)
	{
		cout << "Return could not find customerID" << endl;
		return;
	}

	// At this point, need to see if movie exists.

	Movie* findMovie = B.findMovieBusiness(commandMovie);

	if(findMovie == NULL)
	{
		cout << "Return could not find movie" << endl;
		return;
	}

	// At this point, the customer exists and the movie
	// is in stock, so we can return movie and add transaction
	// to customer's history

	findMovie->changeStock(1);

	probablyExists->insertCustomerAction(category, findMovie);


}



