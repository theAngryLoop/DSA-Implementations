#include "BSTNode.h"

using namespace std;

class BST{

	BSTNode *rootPtr;

	// helpers
	BSTNode* getNewBSTNode( int );
	void insert( BSTNode**, int );
	void remove( BSTNode**, int );
	bool search( BSTNode*, int );
	int kthGreater( BSTNode*, int );
	int getHeight( BSTNode* );
	void printPreOrder( BSTNode* );
	void printInOrder( BSTNode* );
	void printPostOrder( BSTNode* );
	void printLevelOrder( BSTNode* );
	bool isBST( BSTNode* );
	void empty( BSTNode* );

public:

	BST();
	void insert( int );
	void remove( int );
	bool search( int );
	int kthGreater( int );
	int getHeight();
	void printPreOrder();
	void printInOrder();
	void printPostOrder();
	void printLevelOrder();
	bool isBST();
	~BST();
};