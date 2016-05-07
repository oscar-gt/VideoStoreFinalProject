/*
 * Inventory.cpp
 *
 *  Created on: Mar 16, 2016
 *      Author: Oscar
 */

#include "Inventory.h"

// Implementation of Inventory.h

// Constructor and destructor
Inventory::Inventory()
{
	category = 'I';
}

// Destructor
Inventory::~Inventory()
{

}

// Doesn't work...
void Inventory::execute(Business B)
{
	B.displayStock();
}

