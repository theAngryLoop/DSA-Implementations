#include <iostream>
#include <queue> // for level-order traversal
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

void BST::remove( BSTNode** node, int val ){

	if( *node == NULL ){ // not a node

		return;
	}
	else if( (*node)->value > val ){ // find and remove in left subtree

		this->remove( &(*node)->left, val );
	}
	else if( (*node)->value < val ){ // find and remove in right subtree

		this->remove( &(*node)->right, val );
	}
	else{

		if( (*node)->value == val ){

			if( (*node)->left == NULL && (*node)->right == NULL ){ // is leaf node

				delete *node;
				*node = NULL;
			}
			else if( (*node)->left == NULL ){

				BSTNode* temp = *node;
				*node = (*node)->right;

				delete temp;
			}
			else if( (*node)->right == NULL ){

				BSTNode* temp = *node;
				*node = (*node)->left;

				delete temp;
			}
			else{ // none of left and right is null

				// find 1st greater in left subtree
				int leftGrtr = this->kthGreater((*node)->left, 1);

				// replace current node's value with greater in its left
				(*node)->value = leftGrtr;

				// remove the duplicate in current node's left
				this->remove(&(*node)->left, leftGrtr);
			}
		}
	}
}

void BST::remove( int val ){

	this->remove(&this->rootPtr, val);
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

int BST::kthGreater( BSTNode* currentNode, int k ){

	static int returnCount = 0;
	int greater = NULL;

	if( currentNode == NULL ){ // not a node, return

		returnCount++;
		return NULL;
	}
	else{

		greater = this->kthGreater(currentNode->right, k);

		if( greater == NULL ){ // its rightest node probably the answer, lets check

			if( returnCount == k ){ // got answer

				returnCount = 0;
				return currentNode->value;
			}
			else if(currentNode->left != NULL){ // go left, if left node available

				greater = this->kthGreater(currentNode->left, k );

				// no increment here, already counted
				return greater;
			}
			else{ // no left node, return back, count this return

				returnCount++;
				return NULL;
			}
		}
		else{ // already got answer

			return greater;
		}
	}
}

int BST::kthGreater( int k ){

	return this->kthGreater(this->rootPtr, k);
}

int BST::getHeight( BSTNode* node ){

	int rightHeight, leftHeight;
	rightHeight = leftHeight = 0;

	if(node == NULL){ // empty tree or no tree

		return -1;
	}
	else{ // not a leaf node yet

		rightHeight = this->getHeight(node->right) + 1;
		leftHeight = this->getHeight(node->left) + 1;

		return ((rightHeight > leftHeight)?rightHeight:leftHeight);
	}
}

int BST::getHeight(){

	return this->getHeight(this->rootPtr);
}

void BST::printPreOrder( BSTNode* node ){

	if( node == NULL ){ // no further nodes, return back

		return;
	}
	else{

		// print current
		cout << node->value << " ";

		// print preorder of left tree
		this->printPreOrder(node->left);
		// print preorder of right tree
		this->printPreOrder(node->right);
	}
}

void BST::printPreOrder(){

	this->printPreOrder(this->rootPtr);
}

void BST::printInOrder( BSTNode* node ){

	if( node == NULL ){ // no further nodes, return back

		return;
	}
	else{

		// print in order of left tree
		this->printInOrder(node->left);

		// print current
		cout << node->value << " ";

		// print in order of right tree
		this->printInOrder(node->right);
	}
}

void BST::printInOrder(){

	this->printInOrder(this->rootPtr);
}

void BST::printPostOrder( BSTNode* node ){

	if( node == NULL ){ // no further nodes, return back

		return;
	}
	else{

		// print post order of left tree
		this->printPostOrder(node->left);
		// print post order of right tree
		this->printPostOrder(node->right);

		// print current
		cout << node->value << " ";
	}
}

void BST::printPostOrder(){

	this->printPostOrder(this->rootPtr);
}

void BST::printLevelOrder( BSTNode* node ){

	if( node == NULL ){ // empty

		return;
	}
	else{ // lets play

		queue<BSTNode*> q;
		
		q.push(node);

		while(!q.empty()){ // while queue is not empty

			node = q.front();

			// print this node
			cout << node->value << " ";

			// if have left child or right child, push 'em
			if(node->left != NULL) q.push(node->left);
			if(node->right != NULL) q.push(node->right);

			// pop from front, the done node
			q.pop();
		}
	}
}

void BST::printLevelOrder(){

	this->printLevelOrder(this->rootPtr);
}

bool BST::isBST( BSTNode* node ){

	if(node == NULL){

		return true;
	}
	else{

		bool leftRightTreesOK = this->isBST(node->left) && this->isBST(node->right);
		bool currentTreeOK = true;

		if( (node->left != NULL && node->value < node->left->value) ||
			(node->right != NULL && node->value > node->right->value) ){

			currentTreeOK = false;
		}

		return leftRightTreesOK && currentTreeOK;
	}
}

bool BST::isBST(){

	return this->isBST(this->rootPtr);
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

