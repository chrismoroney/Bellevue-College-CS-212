#include "TreeSet.h"
#include <set>
#include <string>
#include <iterator>
#include <iostream>
using namespace std;
// CS212, Spring 2019, Program #6
// W.P. Iverson, instructor
void main()
{
	// Create a binary search tree for strings
	TreeSet<string> tree;
	//set<string> tree;  // C++ STL example

	// Add elements to the tree
	tree.insert("Kansas");
	tree.insert("Colorado");
	tree.insert("Maine");
	tree.insert("Alaska");
	tree.insert("Kansas");

	// Create an iterator from this set
	Iterator<string> itr = tree.begin();  
	//set<string>::iterator itr = tree.begin(); // C++ STL example
	tree.insert("Alabama"); // modify the tree
	// Traverse a binary tree using iterators
	while (itr != tree.end())
	{
		cout << *itr << " ";
		++itr;
	} // Alabama is missing, FIX IT!!!!
	cout << endl;

	// Create another fresh iterator from set
	Iterator<string> another = tree.begin();  
	//set<string>::iterator another = tree.begin(); // C++ STL example
	while (another != tree.end())
	{
		cout << *another << " ";
		++another;
	} // Alabama exists, YES.
	cout << endl;

	//system("pause");
}