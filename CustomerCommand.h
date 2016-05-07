/*
 * CustomerCommand.h
 *
 *  Created on: Mar 16, 2016
 *      Author: Oscar
 */

#ifndef CUSTOMERCOMMAND_H_
#define CUSTOMERCOMMAND_H_

#include "Command.h"
#include "Movie.h"
#include "Business.h"

// A customer command can currently only
// be
// Borrow (a movie)
// Return (a movie)
// These commands store a customer ID,
// pointer to a movie, and a char for the
// type of command, 'B', or 'R'

class CustomerCommand: public Command
{


public:

	CustomerCommand();
	virtual ~CustomerCommand();

	//virtual void execute(Business B);

	//virtual void execute(Business B);    // Virtual function to perform action
	void setCommandMovie(Movie* m);

	void setCustomerCommandID(int id);

	virtual void displayCommand();

	int getCustomerID();

	Movie* getCommandMovie();

protected:
	int customerID;
	Movie* commandMovie;
};




#endif /* CUSTOMERCOMMAND_H_ */
