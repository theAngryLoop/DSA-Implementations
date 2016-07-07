#include "BSTNode.h"

using namespace std;

class BST{

	BSTNode *rootPtr;

	// helpers
	BSTNode* getNewNode( int );
	void insert( BSTNode**, int );
	bool search( BSTNode*, int );
	int kthGreater( BSTNode*, int );
	void empty( BSTNode* );

public:

	BST();
	void insert( int );
	bool search( int );
	int kthGreater( int );
	~BST();
};