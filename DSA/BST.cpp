#include <iostream>
#include "BST.h"

using namespace std;

BST::BST(){

	// initialize root pointer to NULL in beginning
	this->rootPtr = NULL;
}

BSTNode* BST::getNewNode( int val ){

	// create new BSTNode on heap memory
	BSTNode *newNode = new BSTNode();

	// initialize newly created BSTNode
	newNode->value = val;
	newNode->left = newNode->right = NULL;

	// return pointer to newly created BSTNode
	return newNode;
}

void BST::insert( BSTNode** root, int val ){

	if( *root == NULL ){ // current node is NULL, insert here

		*root = this->getNewNode(val);
	}
	else if( (*root)->value > val ){ // new value is less or equal to current node's value, go left

		this->insert(&(*root)->left, val);
	}
	else{ // new value is greater than current node's value, move right

		this->insert(&(*root)->right, val);
	}
}

void BST::insert( int val ){

	// call to private insert helper function with pointer to root to insert new BSTNode by recursively finding location
	this->insert(&this->rootPtr, val);
}

bool BST::search( BSTNode *root, int val ){

	if( root == NULL ){ // tree is empty

		return false;
	}
	else if( root->value == val ){ // found a match

		return true;
	}
	else if( root->value > val ){ // search value is less than current node's value, move left

		return this->search(root->left, val);
	}
	else{ // search value is less than current node's value, move right

		return this->search(root->right, val);
	}
}

bool BST::search( int val ){

	return this->search(this->rootPtr, val);
}

void BST::empty( BSTNode *root ){

	if( root == NULL ){ // already null, return back

		return;
	}
	else{ // move left and right

		this->empty( root->left );
		this->empty( root->right );

		// done with left and right, delete current node and set pointer to NULL
		delete root;
		root = NULL;

		return;
	}
}

BST::~BST(){

	this->empty(this->rootPtr);
}

