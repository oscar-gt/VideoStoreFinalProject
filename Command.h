/*
 * Command.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Oscar
 */

#ifndef COMMAND_H_
#define COMMAND_H_

#include "Business.h"

// A command object represents one
// of 4 current valid commands:
// Borrow (a movie)
// Return (a movie)
// History (customer transactions)
// Inventory (display all inventory)
//
// This is a base class for all 4.

class Command
{
public:
    Command();
    virtual ~Command();

    char getCategory();
    void setCategory(char c);

    virtual void execute(Business b);

    virtual void displayCommand();
protected:
    char category;
};




#endif /* COMMAND_H_ */
