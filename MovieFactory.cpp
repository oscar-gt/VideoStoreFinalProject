/*
 * MovieFactory.cpp
 *
 *  Created on: Mar 12, 2016
 *      Author: Oscar
 */

// Implements moviefactory.h file
//
// The main purpose of this class is to return
// a Movie pointer with the data members filled
// in.


#include "MovieFactory.h"

#include <fstream>
#include <iostream>
#include <string>
using namespace std;


Movie* MovieFactory::makeMovie(ifstream & file)
{
	string inputStr = "";
	int number = 0;
	char cat = NULL;

	cat = file.get();
	if(cat == NULL)
	{

	}

	// ---------- Checking to see what type of movie we have ----------

	// ----------------------- Classic Movie ----------------------
	if(cat == 'C')
	{
		// We have a Classic movie, so extract info
		//Movie* result;
		ClassicMovie* cm = new ClassicMovie;

		cm -> setCategory('C');

		// Consuming comma and space
		file.ignore(2, ' ');

		// Extracting quantity
		file >> number;
		cm -> changeStock(number);
		file.ignore(2, ' '); // Ignoring comma and space

		// Extracting director
		getline(file, inputStr, ' ');
		cm -> setDirectorFirst(inputStr);
		//file.ignore(1, ' ');
		getline(file, inputStr, ',');
		cm -> setDirectorLast(inputStr);
		file.ignore(2, ' '); // igonoring space

		//Extracting title
		getline(file, inputStr, ',');
		cm -> setTitle(inputStr);
		file.ignore(1, ' ');

		// Extracting major actor/actress
		getline(file, inputStr, ' ');
		cm -> setActorFirst(inputStr);
		getline(file, inputStr, ' ');
		cm -> setActorLast(inputStr);

		// Extracting month
		file >> number;
		cm -> setMonth(number);

		// Extracting year
		file >> number;
		cm -> setYear(number);

		getline(file, inputStr);  // Consumes EOL

		return cm;
	}

	// ------------------------   Comedy Movie   ---------------------

	else if(cat == 'F')
	{
		// We have a Comedy movie, so extract info
		ComedyMovie* result = new ComedyMovie;
		result -> setCategory('F');
		// Using helper
		fillMovie(result, file);

		return result;
	}

	// ----------------------------- Drama movie -------------------------

	else if(cat == 'D')
	{
		// We have a Comedy movie, so extract info
		DramaMovie* result = new DramaMovie;
		result -> setCategory('D');
		fillMovie(result, file);

		return result;
	}
	else
	{
		//cout << "Category char does not exist" << endl;
		//cout << endl;
		getline(file, inputStr);  // Consumes EOL
		return NULL;
	}
}


// ------------------------ FillMovie Helper Function ------------------

// This function will fill in the information for movies that only
// have a stock, director, title, and year member.
void MovieFactory::fillMovie(Movie* m, ifstream &file)
{
	string inputStr = "";
	int number = 0;
	char c = NULL;
	// Consuming comma and space
	file.ignore(2, ' ');

	// Extracting quantity
	file >> number;
	m -> changeStock(number);
	file.ignore(2, ' '); // Ignoring comma and space

	// Extracting director
	getline(file, inputStr, ' ');
	m -> setDirectorFirst(inputStr);
	//file.ignore(1, ' ');
	getline(file, inputStr, ',');
	m -> setDirectorLast(inputStr);
	file.ignore(2, ' '); // igonoring space

	//Extracting title
	getline(file, inputStr, ',');
	m -> setTitle(inputStr);
	file.ignore(1, ' ');

	file >> number;
	m -> setYear(number);

	getline(file, inputStr);  // Consumes EOL

}


