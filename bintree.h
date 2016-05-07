/*
 * bintree.h
 *
 *  Created on: Jan 14, 2016
 *      Author: Oscar Garcia-Telles
 *
 */


#ifndef BINTREE_H_
#define BINTREE_H_
// COMMENT LINES SHOULD NOT EXTEND BEYOND 80 CHARS. DON'T MAKE THEM THIS BIG!!!!

/*
 * A BinTree is a binary search tree. It has a left and right child.
 *
 *
 */

/*
 * BinTree objects will be used to represent trees
 * of Movie objects.
 *
 */

#include<ostream>
#include "Movie.h"
using namespace std;

class BinTree
{
	// MovieList will need access.
	friend class MovieList;
	friend class Business;

public:
	BinTree();						// constructor
	//BinTree(const BinTree &other);	// copy constructor
	~BinTree();				// destructor, calls makeEmpty
	bool isEmpty() const;	// true if tree is empty, otherwise false
	void makeEmpty();		// make the tree empty so isEmpty returns true
	Movie* findMovie(Movie* m);

	bool insert(Movie *n);
	// Looks for node and retrieves it
	void displayTree();


private:
	// Node that will be used to build tree
	struct Node {
		Movie* movieData;	// pointer to movie object

		Node* left;		// left subtree pointer
		Node* right;	// right subtree pointer
	};
	Node* root;			// root of the tree

	// utility functions

	void displayTreeHelp(Node *n);

	// Helps insert()
	bool addNode(Node * &tree, Movie *m);

	// Helps destructor
	void clearTree(Node * &treeRoot);
	Movie* findMovieHelp(Node* treeRoot, Movie* m);

};
#endif /* BINTREE_H_ */
