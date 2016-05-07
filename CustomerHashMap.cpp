/*
 * CustomerHashMap.cpp
 *
 *  Created on: Mar 14, 2016
 *      Author: Oscar
 */

#include "CustomerHashMap.h"
#include<iostream>

// Implementation of CustomerHashMap.h

// Constructor
CustomerHashMap::CustomerHashMap()
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{

		hashEntry[i].setKey(-1);
		hashEntry[i].cust = NULL;

	}

}

// -------------------- Destructor deletes customer pointers ----------------------
CustomerHashMap::~CustomerHashMap()
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{
		// Retrieving customer.
		Customer* current = hashEntry[i].getCustomerFromHashEntry();
		if(current != NULL)
		{
			delete current;
		}
	}
}

// Retrieves a pointer to a customer if customerID exists
Customer* CustomerHashMap::getCustomer(int custID)
{

	// Generating key
	int keyVal = custID % TABLE_SIZE;
	int index = keyVal;

	// Starting key, used to terminate search
	// if we end up at the same key
	int startingPoint = keyVal;

	int hashCount = 1;
	int doubleHashVal = 0;
	// Customer ID
	int cid = custID;
	Customer* probablyFind;

	int probable = 0;
	int toMatch = 0;

	// Checking for collisions and getting
	// the right index
	while( true )
	{

		// Pointing to current customer.
		probablyFind = hashEntry[index].getCustomerFromHashEntry();

		// First checking that we're not searching in circles
		if(hashCount == TABLE_SIZE)
		{

			return NULL;
		}

		// A customer is found, now checking if it
		// is the right customer
		if(probablyFind != NULL)
		{

			probable = probablyFind->getID();
			toMatch = custID;

			// If a matchis found
			if(probable == custID)
			{
				return probablyFind;
			}
		}

		// At this point, the customer found is not
		// the right one, so we'll use double hashing
		// to get the next search index.

		// Double hashing function
		doubleHashVal = hashCount * (DOUBLE_HASH_R - (cid % DOUBLE_HASH_R));
		// New index to try
		index = (keyVal + doubleHashVal) % TABLE_SIZE;
		hashCount = hashCount + 1;

		// Checking if we're checking the very first place
		// we looked in the firt check.
		if(index == startingPoint)
		{
			return NULL;
		}
	}

}

// Placing a customer into our hash table
bool CustomerHashMap::put(Customer inputCust)
{

	if(inputCust.getFirstName() == "")
	{
		cout << "Cannot put a null customer" << endl;
		return false;
	}

	// First creating hash entry with new customer
	Customer* C = new Customer;
	// Setting ID
	C -> setID(inputCust.getID());
	// Setting first name
	C -> setFirstName(inputCust.getFirstName());
	// Setting Last name
	C -> setLastName(inputCust.getLastName());

	CustomerHashEntry entry;
	entry.setCustomer(C);

	int temp = entry.calculateHashKey(C);

	entry.setKey(temp);

	// Now placing in hash table
	int keyVal = entry.getKey();
	int index = keyVal;

	int hashCount = 1;
	int doubleHashVal = 0;
	// Customer ID
	int cid = inputCust.getID();

	// Checking for collisions and getting
	// the right index
	bool isVacant = hashEntry[index].isVacant();

	// Will look until we find an empty spot
	while(  !( hashEntry[index].isVacant() ) )
	{
		// Checking if we've searched the same number
		// of times as our table size
		if(hashCount == TABLE_SIZE)
		{
			cout << "Unable to put customer: ";
			entry.displayHashEntry();
			cout << "in hash table" << endl;
			return false;
		}

		// Double hashing function
		doubleHashVal = hashCount * (DOUBLE_HASH_R - (cid % DOUBLE_HASH_R));
		// New index to try
		index = (keyVal + doubleHashVal) % TABLE_SIZE;
		hashCount = hashCount + 1;
	}
	hashEntry[index] = entry;

	return true;

}

// Returning table size
int CustomerHashMap::getTableSize()
{
	return TABLE_SIZE;
}

// Only used for debugging!!!!!!!!!!!!!!!!!!!!!
void CustomerHashMap::displayHashMap() const
{
	for(int i = 0; i < TABLE_SIZE; i++)
	{

		CustomerHashEntry current = hashEntry[i];
		if(current.getKey() != -1)
		{

			current.displayHashEntry();
		}


	}
}

