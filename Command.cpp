/*
 * Command.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: Oscar
 */


#include "Command.h"
#include<iostream>
using namespace std;


// Implementation of Command.h

// Constructor
Command::Command()
{
	category = NULL;
}

// Destructor
Command::~Command()
{

}

// Does not work...
void Command::execute(Business b)
{

}

// --------------- Getters and Setters -------------------

char Command::getCategory()
{
	return category;
}

void Command::setCategory(char c)
{
	category = c;
}

// Displaying command
void Command::displayCommand()
{
	cout << category << endl;
}



