/*
 * CustomerTransactions.h
 *
 *  Created on: Mar 14, 2016
 *      Author: Oscar
 */

#ifndef CUSTOMERTRANSACTIONS_H_
#define CUSTOMERTRANSACTIONS_H_

#include "Movie.h"

// CustomerTransaction objects represent
// all the transactions that a customer
// has made. They are stored in a linked
// list of transactions. Each node has
// an action, pointer to a movie, and
// a pointer to the next transaction

class CustomerTransactions
{
	friend class Customer;

private:

	struct TransactionNode
	{
		char action;			// Transaction type: borrow, return
		Movie* moviePointer;			// Movie borrowed, returned
		TransactionNode *next;	// Link to next transaction
	};

	TransactionNode *head;	// Points to the head of the list

	void clearCustomerTransactionsHelp(TransactionNode* &tn);

	// -------------------- Public --------------------
public:

	CustomerTransactions();

	~CustomerTransactions();

	void insertTransaction(char transactionType, Movie* m);

	void clearCustomerTransactions();

	void displayTransactions();

};



#endif /* CUSTOMERTRANSACTIONS_H_ */
