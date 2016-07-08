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

	if(b.isBST()) cout << "Is a Binary Search Tree";
	else cout << "Not a Binary Search Tree";

	cin.ignore();
}