/*
 * Customer.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Oscar
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "CustomerTransactions.h"
#include <fstream>

// Customer objects represent our store's
// customers. They each have a 4 digit
// customer id number, a firs and last name,
// and a transaction history which is a
// linked list of transactions.


class Customer
{
	//friend class CustomerHashMap;

public:

	Customer();

	Customer(int id, string fullName);

	~Customer();

	void createCustomer(ifstream &file);

	void displayCustomer();

	void displayCustomerHistory();

	int getID();

	string getFirstName();
	string getLastName();

	void setID(int id);

	void setFirstName(string first);

	void setLastName(string last);

	void insertCustomerAction(char type, Movie* m);

private:

	int customerID;
	string firstName;
	string lastName;
	CustomerTransactions customerHistory;

	// Helpers

};



#endif /* CUSTOMER_H_ */
