/*
 * MovieList.cpp
 *
 *  Created on: Mar 13, 2016
 *      Author: Oscar
 */


#include "MovieList.h"
#include<iostream>
using namespace std;

// Implementation of MovieList.h

// COnstructor
MovieList::MovieList()
{
	head = NULL;

}

// Destructor
MovieList::~MovieList()
{
	clear(head);
}

// Finds a movie and changes its stock
void MovieList::updateStock(Movie* m, int changeVal)
{
	Movie* toChange;
	char cat = m->getCategory();
	// Will travese linked list of movie trees
	LinkedListNode* curr = head;

	// First finding correct movie tree in linked list
	while( (curr != NULL) && (curr -> category != cat) )
	{
		curr = curr->next;
	}
	// Now locating movie
	toChange = curr -> movieTree.findMovie(m);
	if(toChange != NULL)
	{
		toChange->changeStock( changeVal );
	}
}


void MovieList::updateClassic(Movie* m, int changeVal)
{

}

// Inserts movie into inventory
void MovieList::insertMovie(Movie* m)
{

	insertMovieHelp(head, m);

}

// Insert helper
void MovieList::insertMovieHelp(LinkedListNode* &n, Movie* m)
{

	// If first creating inventory or if
	// there's a new category being added
	// to the end of a list.
	if(n == NULL)
	{
		n = new LinkedListNode;
		n -> category = m -> getCategory();
		n -> next = NULL;
		n -> movieTree.insert(m); /// ************************************** INSERTS

		return;

	}

	// If we've found the category a movie is in
	else if( n -> category == m -> getCategory() )
	{
		n->movieTree.insert(m);

	}

	// If the incoming category comes first
	else if( m -> getCategory() > n -> category)
	{
		// Creating new node to insert in front
		LinkedListNode* front = new LinkedListNode;
		// Setting data
		front->category = m->getCategory();
		front -> movieTree.insert(m);

		// Linking
		front->next = n;
		n = front;
	}

	// When we need to keep looking for the
	// right category
	else
	{
		insertMovieHelp( n->next, m);
	}
}

// Destructor helper
void MovieList::clear(LinkedListNode* &n)
{
	if(head == NULL)
	{
		// Nothing :P
	}
	else
	{
		clear(n -> next);
		n -> movieTree.makeEmpty();
		delete n;
		n = NULL;
	}
}

// Displays all movies
void MovieList::displayMovieList()
{
	LinkedListNode* current = head;

	cout << "Displaying all movies by category..." << endl;
	cout << endl;

	int count = 1;

	while(current != NULL)
	{
		cout << "         Movies of category  '"
				<< (current -> category) << "'  " << endl;
		current -> movieTree.displayTree();
		current = current -> next;


		count++;
		cout << endl;

	}
}

// Returns a pointer to a movie if found
Movie* MovieList::findMovie(Movie* toFind)
{
	Movie* toReturn;

	// First need to find the right tree!!!
	// In other words, traverse linked list
	// intil you find 'C' tree, 'F' tree,
	// or 'D' tree, depending on what's needed.

	char cat = toFind->getCategory();

	LinkedListNode* curr = head;

	while(curr != NULL)
	{
		if(cat == (curr -> category) )
		{
			toReturn = curr -> movieTree.findMovie(toFind);
			return toReturn;
		}
		curr = curr -> next;
	}

	return NULL;
}



