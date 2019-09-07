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
	list.add("Newcastle");
	list.add("Cle Elum");
	list.add("Pullman");

	// Create another list for strings
	LinkedList<string> list2;
	list2.add("Bellevue");
	list2.add("Ellensburg");
	list2.add("Pullman");
	list2.add("Boston");
	list2.add("Tacoma");

	LinkedList<string> list1(list); // copy constructor
	cout << "list1: ";
	printList(list1);
	cout << "list2: ";
	printList(list2);
	list1.addAll(list2);
	cout << "list is : ";
	printList(list);
	cout << "After list1.addAll(list2), list1 is ";
	printList(list1);
	list1 = list;
	cout << "list1: ";
	printList(list1);
	cout << "list2: ";
	printList(list2);
	list1.removeAll(list2);
	cout << "After list1.removeAll(list2), list1 is ";
	printList(list1);
	list1 = list;
	cout << "list1: ";
	printList(list1);
	cout << "list2: ";
	printList(list2);
	list1.retainAll(list2);
	cout << "After list1.retainAll(list2), list1 is ";
	printList(list1);
	list1 = list;
	cout << "list1: ";
	printList(list1);
	cout << "list2: ";
	printList(list2);
	list1 = list1 + list2;
	cout << "After list1 = list1 + list2, list1 is ";
	printList(list1);
	list1 = list; // make this a deep copy (copy data not just reference)
	cout << "list1: ";
	printList(list1);
	cout << "list2: ";
	printList(list2);
	list1 = list1 - list2;
	cout << "After list1 = list1 - list2, list1 is ";
	printList(list1);
	list1 = list;
	cout << "list1: ";
	printList(list1);
	cout << "list2: ";
	list1 = list1 ^ list2;
	cout << "After list1 = list1 ^ list2, list1 is ";
	printList(list1);
	list1 = list;
	cout << list1[0] << endl; // like random access, but we know it's not
	list1[0] = "Paris";
	cout << list1[0] << endl;

	// So contains and last index will be easy once all of above are working
	cout << "Contains Seattle? " << list1.contains("Seattle") << endl;
	cout << "Last index of Seattle: " << list1.lastIndexOf("Seattle") << endl;
	cout << "Last index of Paris: " << list1.lastIndexOf("Paris") << endl;
	list1.remove("Paris");
	cout << "Last index of Paris: " << list1.lastIndexOf("Paris") << endl;
	cin.get();
	return 0;
}