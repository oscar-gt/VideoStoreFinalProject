/*
 * CustomerCommand.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: Oscar
 */

#include "CustomerCommand.h"

#include<iostream>
using namespace std;

// Implementation of CustomerCOmmand.h

// Constructor
CustomerCommand::CustomerCommand()
{
	customerID = -1;
	category = NULL;
	commandMovie = NULL;
}

// Destructor
CustomerCommand::~CustomerCommand()
{
	cout << "From ~CustomerCommand()" << endl;
	delete commandMovie;
	cout << "From ~CustomerCommand()" << endl;
}

// --------------- Setters, Getters --------------------

void CustomerCommand::setCommandMovie(Movie* m)
{
	commandMovie = m; // ************************************************** NOT SURE ABOUT THIS
}


void CustomerCommand::setCustomerCommandID(int id)
{
	customerID = id;
}

void CustomerCommand::displayCommand()
{
	cout << customerID << ", " << category << ", ";
	commandMovie->displayMovie();
}

Movie* CustomerCommand::getCommandMovie()
{
	return commandMovie;
}

int CustomerCommand::getCustomerID()
{
	return customerID;
}


