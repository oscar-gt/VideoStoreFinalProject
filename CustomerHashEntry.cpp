/*
 * CustomerHashEntry.cpp
 *
 *  Created on: Mar 14, 2016
 *      Author: Oscar
 */

#include "CustomerHashEntry.h"
#include "CustomerHashMap.h"
#include<iostream>

// Implementation of CustomerHashEntry.h

// Constructor
CustomerHashEntry::CustomerHashEntry()
{
	key = -1;
	cust = NULL; // cust is a pointer to a customer!!!!
}

// Constructor
CustomerHashEntry::CustomerHashEntry(Customer* custVal): key(-1), cust(NULL)
{
	// Hashes our customer
	int tablesize = CustomerHashMap::getTableSize();

	// Getting key value
	key = ( custVal -> getID() ) %  tablesize;

	// setting key
	cust->setID(custVal->getID());

	// setting name
	cust->setFirstName(custVal->getFirstName());
	cust->setLastName(custVal->getLastName());

}

// Destructor
CustomerHashEntry::~CustomerHashEntry()
{
	if(cust == NULL)
	{
		delete cust;
	}

}

// Assignment operator
CustomerHashEntry &CustomerHashEntry::operator=( const CustomerHashEntry &rhs )
{

	CustomerHashEntry result;
	if(rhs.cust == NULL)
	{


		return result;
	}

	this->setKey(rhs.key);
	this->setCustomer(rhs.cust);

	return *this;


}

// --------------- Setters and Getters ----------------
void CustomerHashEntry::setKey(int k)
{

	key = k;


}

void CustomerHashEntry::setCustomer(Customer* c)
{

	if(cust != NULL && c == NULL)
	{
		delete cust;
		cust = NULL;
		return;
	}

	else if(cust == NULL && c == NULL)
	{
		cust = new Customer;
		cust->setID(-1);
		cust->setFirstName("");
		cust->setLastName("");

	}

	else if( cust== NULL && c != NULL)
	{
		cust = new Customer;
		cust->setID(c->getID());
		cust->setFirstName(c->getFirstName());
		cust->setLastName(c->getLastName());
	}
	else
	{

		cust->setID(c->getID());
		cust->setFirstName(c->getFirstName());
		cust->setLastName(c->getLastName());
	}

}

Customer* CustomerHashEntry::getCustomerFromHashEntry()
{
	return cust;
}

int CustomerHashEntry::getKey()
{
	return key;
}

void CustomerHashEntry::displayHashEntry()
{
	if(cust == NULL)
	{
		//cout << "No customer in hash entry." << endl;
		return;
	}
	else
	{
		cout << "Key=  "<< key << ",  ";
		cust->displayCustomer();
	}

}

// Checks of a hash entry is empty
bool CustomerHashEntry::isVacant()
{
	return (cust == NULL);
}

// Helper to calculate initial hash value
int CustomerHashEntry::calculateHashKey(Customer* c)
{
	int result = 0;
	result = ( c -> getID() ) %  CustomerHashMap::getTableSize();
	return result;
}


