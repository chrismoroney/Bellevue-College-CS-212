// Original code from Daniel Liang
// modified by W.P. Iverson
// Bellevue College, May 2019
// for CS212
#include <iostream>
#include <string>
#include "LinkedList.h"
using namespace std;

// function we'll all use to print data
template<typename T>
void printList(const LinkedList<T>& list)
{
	Iterator<T> current = list.begin();
	while (current != list.end())
	{
		cout << *current << " ";
		current++;
	}
	cout << endl;
}


int main()
{
	// Create a list for strings
	LinkedList<string> list;
	list.add("Bellevue");
	list.add("Tofino");

	// Create another list for strings
	LinkedList<string> list2;
	list2.add("Bellevue");
	list2.add("Ellensburg");

	cout << "list2: ";
	printList(list2);

	cout << "list is : ";
	printList(list);
	
	return 0;
}