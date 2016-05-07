/*
 * CustomerHashEntry.h
 *
 *  Created on: Mar 14, 2016
 *      Author: Oscar
 */

#ifndef CUSTOMERHASHENTRY_H_
#define CUSTOMERHASHENTRY_H_

#include "Customer.h"

// CustomerHashEntry represents an
// entry in our customer hash table.
// A hash entry has a key and a pointer
// to a customer.

class CustomerHashEntry
{
	friend class CustomerHashMap;
public:

	CustomerHashEntry &operator=( const CustomerHashEntry &rhs );	// Assignment

	CustomerHashEntry();
	CustomerHashEntry(Customer* cust);
	~CustomerHashEntry();

	void setKey(int k);
	void setCustomer(Customer* c);
	Customer* getCustomerFromHashEntry();
	int getKey();
	void displayHashEntry();
	bool isVacant();
	int calculateHashKey(Customer* c);

private:
	int key;
	Customer* cust;


};


#endif /* CUSTOMERHASHENTRY_H_ */
