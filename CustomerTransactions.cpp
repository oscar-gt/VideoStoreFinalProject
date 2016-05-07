/*
 * CustomerTransactions.cpp
 *
 *  Created on: Mar 14, 2016
 *      Author: Oscar
 */

#include<iostream>
#include "CustomerTransactions.h"
#include "Movie.h"

// Implementation of CustomerTransactions.h

// Constructor
CustomerTransactions::CustomerTransactions()
{
	head = NULL;
}

// Destructor
CustomerTransactions::~CustomerTransactions()
{
	(*this).clearCustomerTransactions();
}

// Helps destructor
void CustomerTransactions::clearCustomerTransactions()
{
	clearCustomerTransactionsHelp(head);
}

// Helps destructor
void CustomerTransactions::clearCustomerTransactionsHelp(TransactionNode* &headNode)
{
	if(headNode == NULL)
	{

	}
	else
	{
		clearCustomerTransactionsHelp(headNode->next);
		delete headNode->moviePointer;
		delete headNode;
	}
}

// Inserting a transaction to a customer's history
void CustomerTransactions::insertTransaction(char transactionType, Movie* m)
{
	if(head == NULL)
	{
		head = new TransactionNode;
		head->action = transactionType;
		head->moviePointer = new Movie;
		head->moviePointer = m;
		head->next = NULL;
	}
	else
	{
		TransactionNode* curr = head;
		while(curr -> next != NULL)
		{
			curr = curr->next;
		}
		curr -> next = new TransactionNode;
		curr -> next -> action = transactionType;
		curr-> next -> moviePointer = new Movie;
		curr-> next -> moviePointer = m;
		curr-> next -> next = NULL;
	}
}

// Displays all transactions
void CustomerTransactions::displayTransactions()
{
	if(head == NULL)
	{
		cout << "No transactions to display at this time." << endl;
		return;
	}
	TransactionNode* current = head;
	while(current != NULL)
	{
		if(current->action == 'B')
		{
			cout << "Borrowed:  ";
		}
		else if(current->action == 'R')
		{
			cout << "Returned:  ";
		}

		current->moviePointer->displayMovie();
		current = current -> next;
	}
}



