/*
 * CustomerHashMap.h
 *
 *  Created on: Mar 14, 2016
 *      Author: Oscar
 */

#ifndef CUSTOMERHASHMAP_H_
#define CUSTOMERHASHMAP_H_

#include "CustomerHashEntry.h"

// CustomerHashMap object keeps our customer information
// in a hash table. The table is an array of HashEntry objects,
// which each have a key and a pointer to a customer.
//
// ******************************************************
// We assume that we will have less than 6091 customers
// *******************************************************
//
// We use double hashing to deal with collisions.
// h1 = customerID mod 6091
// h2 = i*(941 - (customerID - 941) )
// so our hash function = (hi + h2) mod 6091
//
// See line 164 of CustomerHashMap.cpp to see
// the function being used.

class CustomerHashMap
{
	friend class CustomerHashEntry;
public:

	// We will assume that a table will conton only
	// a few thousand entries.
	static const int TABLE_SIZE = 6091;
	// For double hashing
	static const int DOUBLE_HASH_R = 941;

	static int getTableSize();

	CustomerHashMap();
	~CustomerHashMap();
	Customer* getCustomer(int custID); // Retrieves customer


	bool put(Customer); // hashes and stores customer based on ID

	// ONLY FOR TESTING PUROPOSES
	void displayHashMap() const;

private:

	CustomerHashEntry hashEntry[TABLE_SIZE];


};





#endif /* CUSTOMERHASHMAP_H_ */
