#include "LinkedListNode.h"

using namespace std;

class LinkedList{

	LinkedListNode* head;

	// helpers
	LinkedListNode* getNewLinkedListNode( int );

public:

	LinkedList();
	void insert( int );
	void insertBeginning( int );
	void insertAt( int, int );
	void remove( int );
	void removeAt( int );
	void print();
	~LinkedList();
};