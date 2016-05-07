/*
 * Return.h
 *
 *  Created on: Mar 16, 2016
 *      Author: Oscar
 */

#ifndef RETURN_H_
#define RETURN_H_

#include "CustomerCommand.h"
#include "Business.h"

// Return object represents a customer
// command to return a movie. It has
// a customer id and a movie pointer

class Return:public CustomerCommand
{
public:
	Return();
	virtual ~Return();
	virtual void execute(Business b);

};



#endif /* RETURN_H_ */
