/*
 * Business.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: Oscar
 */

#include "Business.h"
#include<iostream>
using namespace std;

using namespace std;

// Implementation of Business.h


Business::Business(): allMovies(), allCustomers()
{
	// Nothing here :P
}

// This constructor not used after all
Business::Business(MovieList ML, CustomerHashMap C)
{

}

// Destructor
Business::~Business()
{

}

// Displays entire stock
void Business::displayStock()
{
	allMovies.displayMovieList();
}

// Displayis a customer's transaction
// history if the customer exists.
void Business::getCustomerHistory(int custID)
{
	Customer* toFind = allCustomers.getCustomer(custID);
	if(toFind != NULL)
	{
		toFind -> displayCustomerHistory(); // ************************** IMPLEMENT THIS
	}
	else
	{
		cout << "Customer ID not found, please double check ID number.";
	}
}

// Changing the quantity of a movie
void Business::changeStock(Movie* m, int changeVal)
{
	allMovies.updateStock(m, changeVal);
}

// getCustomer attempts to retrieve
// a pointer to a customer in our
// hash table.
Customer* Business::getCustomer(int cid)
{
	Customer* toReturn;
	// Trying to retrieve from hash table
	toReturn = allCustomers.getCustomer(cid);
	return toReturn;
}

// Looks for a movie in our system.
Movie* Business::findMovieBusiness(Movie* toFind)
{
	Movie* toReturn;
	toReturn = allMovies.findMovie(toFind);  // ********************************  IMPLEMENT THIS
	return toReturn;
}

// Adds a movie to our system .
void Business::addMovieToStock(Movie* m)
{
	allMovies.insertMovie(m);
}

// Attempts to insert customer to hash table.
void Business::addCustomerToTable(Customer c)
{
	bool addedToTable = false;
	addedToTable = allCustomers.put(c);
}

