/*
 * MovieList.h
 *
 *  Created on: Mar 13, 2016
 *      Author: Oscar
 */

#ifndef MOVIELIST_H_
#define MOVIELIST_H_
#include "bintree.h"

/*
 * LinkedList.h
 *
 *  Created on: Feb 28, 2016
 *      Author: Oscar
 */

/*
 *  LinkedList class represents a linked list object
 *  that keeps our inventory stock information and
 *  our customer transaction history.
 *
 *  Each node in this linked list has a binary tree
 *  which represents a different category of movies.
 *  For now, there will only be 3 linked list nodes,
 *  one for Classic, Drama, and Comedy movies
 *
 */


class MovieList
{
public:
	MovieList( );							// the constructor
	//LinkedList( const LinkedList &rhs );	// the copy constructor
	virtual ~MovieList( );							// the destructor

	bool isEmpty( ) const;		// checks if a list is empty.
	void insertMovie( Movie* m);		// insert a new category

	void displayMovieList();

	void updateStock(Movie* m, int changeVal);
	void updateClassic(Movie* m, int changeVal);

	Movie* findMovie(Movie* toFind);

protected:
	struct LinkedListNode
	{
		char category;			// Movie category
		BinTree movieTree;		// Movie tree for each category
		LinkedListNode *next;	// Link to next category
	};

	LinkedListNode *head;	// Points to the head of the list

	// Private helpers
	virtual void clear( LinkedListNode* &n );				// clean up all list entries.
	void insertMovieHelp(LinkedListNode* &n, Movie* m);


};



#endif /* MOVIELIST_H_ */
