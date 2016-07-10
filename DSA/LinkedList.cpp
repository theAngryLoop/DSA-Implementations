#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList(){

	this->head = NULL;
}

LinkedListNode* LinkedList::getNewLinkedListNode( int val ){

	LinkedListNode* newNode = new LinkedListNode;

	newNode->value = val;
	newNode->next = NULL;

	return newNode;
}

void LinkedList::insert( int val ){

	LinkedListNode* newNode = this->getNewLinkedListNode( val );
	LinkedListNode* tempPtr = this->head;

	if( tempPtr == NULL ){ // empty list

		this->head = newNode;
	}
	else{ 
		
		while( tempPtr->next != NULL ){

			tempPtr = tempPtr->next;
		}

		tempPtr->next = newNode;
	}
}

void LinkedList::insertBeginning( int val ){

	LinkedListNode* newNode = this->getNewLinkedListNode( val );

	if( this->head == NULL ){ // empty list

		this->head = newNode;
	}
	else{ // not empty

		newNode->next = this->head;
		this->head = newNode;
	}
}

void LinkedList::insertAt( int val, int k ){

	if( k <= 1 || this->head == NULL ){ // invalid index, 1st index or empty list

		this->insertBeginning(val);
	}
	else{

		LinkedListNode* tempPtr = this->head;
		int count = 1;

		while( tempPtr->next != NULL && count < k-1 ){

			count++;
			tempPtr = tempPtr->next;
		}

		LinkedListNode* newNode = this->getNewLinkedListNode(val);

		newNode->next = tempPtr->next;
		tempPtr->next = newNode;
	}
}

void LinkedList::remove( int val ){

	if( this->head == NULL ){ // empty list

		return;
	}
	else if( this->head->value == val ){ // remove from head or only one element in list and is matched

		LinkedListNode* toRemove = this->head;
		this->head = this->head->next;

		delete toRemove;
		toRemove = NULL;
	}
	else{

		LinkedListNode* tempPtr = this->head;

		while( tempPtr->next != NULL && tempPtr->next->value != val ){

			tempPtr = tempPtr->next;
		}

		if( tempPtr->next != NULL ){ // have found the node

			LinkedListNode* toRemove = tempPtr->next;
			tempPtr->next = toRemove->next;

			delete toRemove;
			toRemove = NULL;
		}
	}
}

void LinkedList::print(){

	LinkedListNode* tempPtr = this->head;

	while( tempPtr != NULL ){

		cout << tempPtr->value << " ";

		tempPtr = tempPtr->next;
	}
}

LinkedList::~LinkedList(){

	LinkedListNode* tempPtr = NULL;

	while( this->head != NULL ){
		
		tempPtr = this->head;
		this->head = this->head->next;

		delete tempPtr;
		tempPtr = NULL;
	}
}