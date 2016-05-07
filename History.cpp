/*
 * History.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: Oscar
 */

#include "History.h"
#include<iostream>
using namespace std;

// Implementation of History.h

// Constructor and destructor
History::History()
{
	customerHistoryID = -1;
}

History::History(Customer cust, Business bus)
{
	customerHistoryID = cust.getID();
}

History::~History()
{

}

void History::setCustomerHistoryID(int id)
{
	customerHistoryID = id;
}

int History::getCustomerHistoryID()
{
	return customerHistoryID;
}

void History::execute(Business B)
{

	Customer* probablyExists = B.getCustomer(customerHistoryID);
	if(probablyExists == NULL)
	{
		cout << "History could not find customer" << endl;
		return;
	}

	probablyExists->displayCustomerHistory();

}

void History::displayCommand()
{
	cout << category << ", " << customerHistoryID << endl;
}





