/*
 * History.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Oscar
 */

/*
 * History class is a subclass of the Command class.
 * The History command outputs the action history
 * for a specified customer.
 *
 */
#ifndef HISTORY_H_
#define HISTORY_H_

#include "Business.h"
#include "Command.h"

class History:public Command
{
public:

	// Constructor and destructor
	History();
	History(Customer cust, Business bus);
	~History();
	void setCustomerHistoryID(int id);
	int getCustomerHistoryID();
	virtual void displayCommand();

	virtual void execute(Business b);

private:
	int customerHistoryID;

};
#endif /* HISTORY_H_ */
