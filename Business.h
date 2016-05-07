/*
 * Business.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Oscar
 */

#ifndef BUSINESS_H_
#define BUSINESS_H_

#include "CustomerHashMap.h"
#include "MovieList.h"

// Business object holds all movie and
// customer information. All commands are
// implemented on the Business object in
// the driver.
//
// Customers are stored in a hash table that
// is a member of Business. Movies are stored
// in a linked list of trees. This linked
// list is also a member of Business.

class Business
{

public:
	// Constructor
	Business();
	// This constructor not used.
	Business(MovieList ML, CustomerHashMap C);
	~Business();
	// Displays entire stock
	void displayStock();
	// Displays a customer's history
	void getCustomerHistory(int custID);
	// Changes the quantity of a movie
	void changeStock(Movie* m, int changeVal);
	// inserts movie to tree
	void addMovieToStock(Movie* m);
	// inserts a customer to the hash table
	void addCustomerToTable(Customer c);
	// Returns pointer to found customer
	Customer* getCustomer(int cid);
	// return pointer to found movie
	Movie* findMovieBusiness(Movie* toFind);


private:

	// Entire movie info
	MovieList allMovies;
	// Entire customer info
	CustomerHashMap allCustomers;
};



#endif /* BUSINESS_H_ */
