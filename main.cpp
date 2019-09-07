/* Code below started with zyBooks online text
   C programming by Vahid and Lysecky, Univ. of Arizona

   modified for CS212 students at Bellevue College
   for C++ linked list dynamic memory management
   by W.P. Iverson, instructor
   April 13, 2019
*/
#include <iostream>
#include <string>
using namespace std;

#include "ContactNode.h"

int main() {
	// Load three nodes with data, each independent right now, no list
	ContactNode* headContact = new ContactNode("David Frederick", "240-555-2104", NULL);
	ContactNode* nextContact = new ContactNode("Bernard Green", "802-555-4986", NULL);
	ContactNode* lastContact = new ContactNode("Hillary Jones", "212-555-9467", NULL);

	// Create a linked list, 3 nodes, headContact pointer points at head
	InsertContactAfter(headContact, nextContact);
	InsertContactAfter(nextContact, lastContact);

	// Print contact list similar to earlier C-programming assignment
	cout << "CONTACT LIST" << endl;
	ContactNode* currContact = headContact;
	while (currContact != NULL) { // linked list traversal
		currContact->PrintContactNode();
		currContact = currContact->GetNextContact();
		cout << endl;
	}

	// Function will confirm delete of each node
	DeleteWholeList(headContact);

	return 0;
}