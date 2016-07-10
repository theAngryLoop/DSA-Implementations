#include <iostream>
#include "LinkedList.h"

using namespace std;

int main(){

	LinkedList l;

	l.insert(1);
	l.insert(13);
	l.insert(8);
	l.insert(11);
	l.insert(12);
	l.insert(4);
	l.insert(2);
	l.insert(9);

	l.print();

	cout << endl;

	l.removeAt(6);

	l.print();

	cin.ignore();
}