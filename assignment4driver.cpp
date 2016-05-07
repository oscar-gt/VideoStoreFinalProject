/*
 * ADriver.cpp
 *
 *  Created on: Mar 11, 2016
 *      Author: Oscar Garcia-Telles
 *
 *
 */




/*
 *	Hash table implemented in the CustomerHashMap.cpp
 *
 *	This driver creates a Business object that
 *	holds all the movie information in a linked
 *	list of binary trees. Each node in the list
 *	has a tree of a different movie category.
 *
 *	Business also has a hash table field that
 *	contains customer information. This
 *	driver populates the hash table.
 *
 *	The commands are then processed, displaying
 *	error messages when
 *	a customer id is not found,
 *	a movie is not found in our inventory, and when
 *	there are not enough copies for customers to borrow
 *
 *	All input files are assumed to be formatted correctly
 *
 */

#include "MovieFactory.h"
#include "bintree.h"
#include "MovieList.h"

#include "CustomerHashMap.h"

#include <iostream>
#include <fstream>

#include "CommandFactory.h"
#include "CustomerCommand.h"

using namespace std;

// Reads movie info and places it
// into B
void populateMovies(Business &B);

// Reads customer info and places it
// in B
void populateCustomers(Business &B);

// Processes all commands
void processCommands();

int main()
{

	processCommands();

	return 0;
}


void processCommands()
{

	// Business stores all movie and customer info
	Business oscarBusiness;

	// Populating movie inventory
	populateMovies(oscarBusiness);

	// Populating customers
	populateCustomers(oscarBusiness);

	cout << "Will process data4movies, data4customers, and data4commands text files" << endl;
	cout << endl;

	ifstream file1("data4commands.txt");
	if (!file1) {
		cout << "File could not be opened." << endl;
	}


	// Current command that will be processed
	Command* currentCommand;

	for(;;)
	{



		// Note: I was originally going to retrieve a command and
		// do currentCommand -> execute(Business B)
		// but it had too many bugs. So instead I decided
		// to process the commands from inside the
		// command factory (not according to plans...).

		currentCommand = CommandFactory::makeCommand(file1, oscarBusiness);

		if (file1.eof())
		{
			cout << endl;
			cout << "reached command file EOF" << endl;
			break;
		}

		// currentCommand -> execute(oscarBusiness); // <------- bugs doing it this way

		if(currentCommand != NULL)
		{

		}


	}

	cout << "End of command processing" << endl;


}

void populateCustomers(Business &B)
{
	ifstream file1("data4customers.txt");
	if (!file1) {
		cout << "File could not be opened." << endl;
	}

	// Initializing our customer
	Customer currentCustomer;
	for(;;)
	{
		if (file1.eof())
		{
			cout << "reached EOF" << endl;
			break;
		}


		// Creating customer
		currentCustomer.createCustomer(file1);

		// Placing customer into our hash table
		B.addCustomerToTable(currentCustomer);
	}
}


void populateMovies(Business &B)
{
	ifstream file1("data4movies.txt");
	if (!file1) {
		cout << "File could not be opened." << endl;
	}

	int numMovies = 31;

	for (int i = 0; i < numMovies; i++){


		if (file1.eof())
		{
			break;
		}

		Movie* currentMovie = new Movie;
		currentMovie = MovieFactory::makeMovie(file1);
		if(currentMovie == NULL)
		{
			delete currentMovie;

		}
		else
		{

			B.addMovieToStock(currentMovie);

		}

	}
}



