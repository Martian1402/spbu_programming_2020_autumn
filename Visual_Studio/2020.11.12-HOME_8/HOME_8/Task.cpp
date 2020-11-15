#include<iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList list;
	list.addToHead(5);
	cout << list << endl;
	list.addToHead(6);
	cout << list << endl;
	list.addToTail(8);
	cout << list << endl;
	list.add(2, 9);
	cout << list << endl;

	
	return EXIT_SUCCESS;
}