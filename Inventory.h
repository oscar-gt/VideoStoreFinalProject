/*
 * Inventory.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Oscar
 */

/*
 * Inventory class is a subclass of the Command class.
 * The inventory command displays all of our inventory.
 *
 */

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "Business.h"
#include "Command.h"

class Inventory:public Command
{
public:

	// Constructor and destructor

	Inventory();	// Orignially had Inventory(Business b);
	~Inventory();

	virtual void execute(Business b);

};
#endif /* INVENTORY_H_ */
