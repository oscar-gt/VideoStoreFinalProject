/*
 * Customer.cpp
 *
 *  Created on: Mar 14, 2016
 *      Author: Oscar
 */

#include "Customer.h"
#include<iostream>

// Implementation of Customer.h

// Customer data members:

//int customerID;
//string firstName;
//string lastName;
//CustomerTransactions customerHistory;

// COnstructor
Customer::Customer()
{
	customerID = -1;
	firstName = "";
	lastName = "";
	customerHistory.head = NULL;

}

Customer::Customer(int id, string fullName)
{
	customerID = id;
	firstName = "";
	lastName = "";
	customerHistory.head = NULL;
}

// Creating a customer from input file
void Customer::createCustomer(ifstream &file)
{
	int idNumber = -1;
	string names = "";
	file >> idNumber;
	customerID = idNumber;

	file.ignore(2, ' '); // Ignoring comma and space

	// Extracting first and last names
	getline(file, names, ' ');
	lastName = names;
	// last name
	getline(file, names);
	firstName = names;
}

// Displaying customer info
void Customer::displayCustomer()
{
	if(firstName == "")
	{
		return;
	}

	cout << "Customer ID: " << customerID << ", first/last name: "
			<< firstName << " " << lastName << endl;
}

// Destructor
Customer::~Customer()
{
	customerHistory.clearCustomerTransactions();
}


// Inserting a customer transaction to customer's
// history.
void Customer::insertCustomerAction(char type, Movie*m)
{
	customerHistory.insertTransaction(type, m);
}

// Displaying a customer's history
void Customer::displayCustomerHistory()
{
	customerHistory.displayTransactions();

}

// --------------------- Getters ----------------

int Customer::getID()
{
	return customerID;
}

string Customer::getFirstName()
{
	return firstName;
}
string Customer::getLastName()
{
	return lastName;
}

// ----------------------- Setters --------------------

void Customer::setID(int id)
{
	//cout << "beginning of customer::setId(int id)" << endl; // ****************************** DEBUG
	customerID = id;
	//cout << "end of customer::setID(int id)" << endl;             // **************************** DEBYG
}

void Customer::setFirstName(string first)
{
	firstName = first;
}
void Customer::setLastName(string last)
{
	lastName = last;
}



