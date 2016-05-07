/*
 * bintree.cpp
 *
 *  Created on: Mar 13, 2016
 *      Author: Oscar
 */

// Class used to store movies of a particular category
#include "bintree.h"


BinTree::BinTree()
{
	root = NULL;
}

BinTree::~BinTree()
{
	(*this).makeEmpty();
}

// Inserting a movie into tree
bool BinTree::insert(Movie *m)
{
	return addNode(root, m);
}

// -------------------------- Find Movie Function --------------------

// Returns a pointer to a movie in the movie tree, or else
// returns null.
Movie* BinTree::findMovie(Movie* m)
{
	Movie* toReturn;
	toReturn = findMovieHelp(root, m);
	return toReturn;
}

// --------------------------- findMovieHelp Function ----------------

// Returns a movie pointer
Movie* BinTree::findMovieHelp(Node* treeRoot, Movie* m)
{
	// When at the end of a search
	if(treeRoot == NULL)
	{
		return NULL;
	}
	// When match is found
	else if( *m == *(treeRoot -> movieData) )
	{
		return treeRoot -> movieData;
	}
	// When less than, greater than
	else if( *m < *(treeRoot -> movieData) )
	{
		return findMovieHelp( treeRoot -> left, m );
	}
	else
	{
		return findMovieHelp( treeRoot -> right, m );
	}
}

// ---------------------- addNode() Helper --------------------

bool BinTree::addNode(Node * &treeRoot, Movie *m)
{
	if(treeRoot == NULL)
	{

		treeRoot = new Node;		// Allocating memory
		treeRoot -> movieData = m;	// Setting data value
		treeRoot -> left = NULL;	// Initializing left and right
		treeRoot -> right = NULL;
		// Insert was successful!
		return true;
	}

	// When incoming m is before current movie
	else if (*m < *(treeRoot -> movieData) )
	{
		return addNode(treeRoot -> left, m);
	}

	// When incoming m is after current movie in tree
	else if(*m > *(treeRoot -> movieData) )
	{
		return addNode( treeRoot -> right, m );
	}

	// For a movie with the same attributes
	else
	{
		return addNode(treeRoot -> left, m);
	}

}

// Helper for destructor
void BinTree::makeEmpty()
{
	clearTree(root);
}

// Helps destructor
void BinTree::clearTree(Node * &treeRoot)
{
	if(treeRoot != NULL)
	{	// Traversing children first...
		clearTree(treeRoot -> left);
		clearTree(treeRoot -> right);

		delete treeRoot -> movieData;  // ******************* <---Might need to delete this

		delete treeRoot; 	//..then deleting pointer
		treeRoot = NULL;
	}
}

bool BinTree::isEmpty() const
{
	return root == NULL;
}

void BinTree::displayTree()
{
	displayTreeHelp(root);
}

void BinTree::displayTreeHelp(Node *treeRoot)
{
	if(treeRoot == NULL)
	{
		// Nothing :P
	}
	else
	{
		displayTreeHelp(treeRoot -> left);
		treeRoot -> movieData -> displayMovie();
		displayTreeHelp(treeRoot -> right);
	}
}

