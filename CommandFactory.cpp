/*
 * CommandFactory.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: Oscar
 */

// Implementation of CommandFactory.h
//
// This file takes an input file stream and
// a Business object. A command is extracted
// and then applied to the Business object.
// The commands that are currently able to
// be processed are
// Borrow (a movie)
// Return (a movie)
// History (display customer's transaction history)
// Inventory (display total current inventory)

#include "CommandFactory.h"
#include "Borrow.h"
#include "Return.h"
#include "Inventory.h"
#include "History.h"

#include "ClassicMovie.h"
#include "DramaMovie.h"
#include "ComedyMovie.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;


// ------------------------------ makeCommand() --------------------------

// returns a pointer to a command. We will ignore
// invalid commands, 'Z' means nothing right now,
// for example. We will also make sure that the
// movie is valid and or it exists for Borrow
// or Return commands, 'B', or 'R', respectively
//
// Currently, we only handle
// 'B'	Borrow a movie
// 'R'	Return a movie
// 'I'	Inventory..will display entire inventory
// 'H'	History to display a customers history

Command* CommandFactory::makeCommand(ifstream &file, Business &B)
{
	// Input items
	string inputStr = "";
	int number = 0;
	char cmd = NULL;

	// Retrieving first char which represents
	// the command to execute
	cmd = file.get();

	// -------------------- Borrow Command ---------------------


	if(cmd == 'B')
	{
		cmd = file.get(); // consuming space

		file >> number;		// Customer ID number

		Borrow* result = new Borrow;
		result->setCategory('B');
		result->setCustomerCommandID(number);

		// Retrieving media type, only D for dvd for now
		cmd = file.get();
		cmd = file.get();
		char mediaType = cmd;
		if(mediaType != 'D')
		{
			getline(file, inputStr);// getting rid of current line
			return NULL;
		}

		// Retrieving movie type, C=classic, F=Comedy, D=drama
		cmd = file.get();
		cmd = file.get();

		// Movie to return
		Movie* currentMovie = new Movie;
		currentMovie->setFormat(mediaType);

		// Filling movie w data. This helper function is in
		// this current file, scroll below.
		fillCommandMovie(cmd, currentMovie, file);

		if(currentMovie == NULL)
		{
			// exiting if movie not found
			return NULL;
		}

		result->setCommandMovie(currentMovie);

		// Processing the command which now has
		// a valid customer id and valid movie
		processB(result, B);

		return result;


	}

	// ----------------- Return Command ------------------------

	// WIll need to use fillCommandMovie(movietype, movie, file)
	// to create movie to return
	else if(cmd == 'R')
	{
		cmd = file.get(); // consuming space

		file >> number;		// Customer ID number

		Return* result = new Return;
		result->setCategory('R');

		// Setting Customer ID
		result->setCustomerCommandID(number);

		// Retrieving media type, only D for dvd for now
		cmd = file.get(); // cosume space
		cmd = file.get(); // retrieve char
		char mediaType = cmd;

		if(mediaType != 'D')
		{
			getline(file, inputStr); // Getting rid of current line
			return NULL;
		}

		// Retrieving movie type, C=classic, F=Comedy, D=drama
		cmd = file.get(); // consume space
		cmd = file.get(); // retrieve type: 'C', 'F', or 'D'

		// Movie to return
		Movie* currentMovie = new Movie;
		currentMovie->setFormat(mediaType);

		// Filling movie w data
		fillCommandMovie(cmd, currentMovie, file);
		if(currentMovie == NULL)
		{
			return NULL;
		}

		result->setCommandMovie(currentMovie);

		// Processing return with valid customer id
		// and valid movie
		processR(result, B);
		return result;

	}

	// --------------------- Inventory Command ------------------
	else if(cmd == 'I')
	{
		string currentString = "";

		Inventory* result = new Inventory;
		result->setCategory(cmd);

		getline(file, currentString);  // Consumes EOL

		processI(result, B);
		return result;

	}

	// ----------------------- History Command ---------------------
	else if(cmd == 'H')
	{
		string currentString = "";
		char currentChar;
		currentChar = file.get(); // cosume space

		int currentInt = 0;
		file >> currentInt;

		History* result = new History;
		result->setCustomerHistoryID(currentInt);
		result->setCategory(cmd);

		getline(file, currentString);  // Consumes EOL

		processH(result, B);
		return result;

	}
	// --------------------- invalid command ----------------
	else
	{
		cout << "Command '" << cmd << "' does not exist" << endl;
		cout << endl;
		string currentString = "";
		getline(file, currentString);  // Consumes EOL
		return NULL;
	}
}

// Helper that fills in partial movie info
void CommandFactory::fillCommandMovie(char mt, Movie* &m, ifstream &file)
{
	char curr;

	// Classic movie
	if(mt == 'C')
	{
		int currentInt = 0;
		string currentString = "";
		ClassicMovie* c = new ClassicMovie;

		c->setCategory('C'); // Classic

		curr = file.get(); // consumes space
		// retrieving month and year of release
		file >> currentInt;
		c->setMonth(currentInt);
		file >> currentInt;
		c->setYear(currentInt);

		// Retrieving first and last name of major actor/actress
		getline(file, currentString, ' ');
		c -> setActorFirst(currentString);

		getline(file, currentString);
		c -> setActorLast(currentString);

		// Pointing to classic
		m = c;
	}

	// Comedy movie
	else if(mt == 'F')
	{
		int currentInt = 0;
		string currentString = "";
		ComedyMovie* f = new ComedyMovie;

		f->setCategory('F'); // F for funny, comedy

		curr = file.get(); // consumes space

		// retrieving movie title
		getline(file, currentString, ',');

		f->setTitle(currentString);

		// retrieving release year

		file >> currentInt;

		f->setYear(currentInt);


		getline(file, currentString);  // Consumes EOL

		// pointing to created comedy movie
		m = f;
	}

	// Drama movie
	else if(mt == 'D')
	{

		string currentString = "";
		DramaMovie* d = new DramaMovie;

		d->setCategory('D'); // Drama

		curr = file.get(); // consumes space

		// retrieving Director's first and last name
		getline(file, currentString, ' ');
		d -> setDirectorFirst(currentString);

		getline(file, currentString, ',');
		d -> setDirectorLast(currentString);
		file.ignore(2, ' '); // igonoring space

		// retrieving title
		getline(file, currentString, ',');
		d->setTitle(currentString);


		getline(file, currentString);  // Consumes EOL

		// pointing to created comedy movie
		m = d;
	}

	// Invalid movie type.
	else
	{
		string currentString = "";
		getline(file, currentString);  // Consumes rest of the line

		m = NULL;

	}
}


// ------------------------------ Processing Commands Here ----------------------------

// Processing borrow command
void CommandFactory::processB(Borrow* b, Business &B)
{
	// First checking if customer exists
	int cid = b->getCustomerID();
	Movie* m = b->getCommandMovie();

	Customer* probablyExists = B.getCustomer(cid);
	if(probablyExists == NULL)
	{
		cout << "Customer ID: " << cid << " is not in our system"
				<< ", cannot borrow." << endl;
		cout << endl;
		return;
	}

	// Now checking if movie exists and if it can be borrowed.

	// Will find movie first.
	Movie* find = B.findMovieBusiness(m);
	if(find == NULL)
	{
		cout << "We don't carry this movie, ";
		probablyExists->displayCustomer();
		cout << "is not able to borrow." << endl;
		cout << endl;
		return;
	}

	// Will check to see if there's at least 1 movie to borrow.
	bool didBorrow;
	didBorrow = find->changeStock(-1);
	if(didBorrow == false)
	{
		cout << "There are currently no copies of: "<< endl;
		find->displayMovie();
		probablyExists->displayCustomer();
		cout << "is not able to borrow." << endl;
		cout << endl;
		return;
	}

	// At this point, there was a movie in stock that was
	// borrowed, so need to add this transaction to customers]
	// history.

	probablyExists->insertCustomerAction(b->getCategory(), find);
}

// Processing return command
void CommandFactory::processR(Return* r, Business &B)
{

	int cid = r->getCustomerID();

	Customer* probablyExists = B.getCustomer(cid);
	if(probablyExists == NULL)
	{
		cout << "Cannot return movie, could not find customerID " << cid << endl;
		cout << endl;
		return;
	}

	// At this point, need to see if movie exists.

	Movie* findMovie = B.findMovieBusiness(r->getCommandMovie());

	if(findMovie == NULL)
	{
		cout << "Movie not found; cannot be returned by ";
		probablyExists->displayCustomer();
		cout << endl;
		return;
	}

	// At this point, the customer exists and the movie
	// is in stock, so we can return movie and add transaction
	// to customer's history

	findMovie->changeStock(1);

	probablyExists->insertCustomerAction(r->getCategory(), findMovie);
}

// Processing inventory command
void CommandFactory::processI(Inventory* i, Business &B)
{
	cout << "-------------------------------------------------------" << endl;
	cout << "               Current Total Inventory" << endl;
	cout << "-------------------------------------------------------" << endl;
	B.displayStock();
	cout << endl;
}

// Processing history command
void CommandFactory::processH(History* h, Business &B)
{
	int cid = h->getCustomerHistoryID();
	Customer* probablyExists = B.getCustomer(cid);
	if(probablyExists == NULL)
	{
		cout << "Customer ID " << cid << " is not in our system."
				<< " No history to display." << endl;
		cout << endl;
		return;
	}

	cout << "Transaction History for ";
	probablyExists->displayCustomer();
	probablyExists->displayCustomerHistory();
	cout << endl;

}

