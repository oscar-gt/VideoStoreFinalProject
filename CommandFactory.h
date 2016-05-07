/*
 * CommandFactory.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Oscar
 */

/*
 *  CommandFactory is a static class that extracts a
 *  Command from an input stream and converts it
 *  into a Command and return that Command.
 *
 *  This class was originally only meant to
 *  return a command to the be processed,
 *  but because of bugs, i had to proccess
 *  the commands within the implementation
 *  file instead.
 *
 *  All commands are procedded in this classes
 *  .cpp file.
 */
#ifndef COMMANDFACTORY_H_
#define COMMANDFACTORY_H_

#include "Command.h"

#include "Borrow.h"
#include "Return.h"
#include "Inventory.h"
#include "History.h"

#include <fstream>
using namespace std;

class CommandFactory
{
public:

	// Creates command and processes it.
	static Command* makeCommand(ifstream &file, Business &B);

private:
	// Generates movie with partial information from file stream
	static void fillCommandMovie(char mt, Movie* &m, ifstream &file);

	// Processing all commands
	static void processB(Borrow* b, Business &B);
	static void processR(Return* r, Business &B);
	static void processI(Inventory* i, Business &B);
	static void processH(History* h, Business &B);
};

#endif /* COMMANDFACTORY_H_ */
