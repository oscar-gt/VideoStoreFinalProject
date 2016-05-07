/*
 * Borrow.h
 *
 *  Created on: Mar 16, 2016
 *      Author: Oscar
 */

#ifndef BORROW_H_
#define BORROW_H_

#include "CustomerCommand.h"
#include "Business.h"

// Borrow is a CustomerCommand object
// that represents a Borrow transaction.
// A Borrow command translates to taking
// 1 copy of a movie (if it is found).

class Borrow:public CustomerCommand
{

public:
	// Constructor
	Borrow();
	// Destructor
	virtual ~Borrow();

	// execute doesn't work... Borrow
	// command processed in CommandFactory
	virtual void execute(Business b);


};



#endif /* BORROW_H_ */
