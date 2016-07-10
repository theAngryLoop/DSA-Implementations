#include <iostream>
#include "BST.h"

using namespace std;

int main(){

	BST b;

	b.insert(22);
	b.insert(33);
	b.insert(11);
	b.insert(21);
	b.insert(31);
	b.insert(9);
	b.insert(40);
	b.insert(30);
	b.insert(15);

	b.printInOrder();

	b.remove(22);

	b.printInOrder();

	cin.ignore();
}