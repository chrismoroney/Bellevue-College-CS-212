// Chris Moroney
// Iverson
// CS212 online section
// Due 21 May 2019

#ifndef CONTACTS_H
#define CONTACTS_H
#include<iostream>
#include <string>
// use a namespace to be able to enable us using functions like string, cout etc.
using namespace std;
// create a class ContactNode. Multiple of these are made to create a linked list
class ContactNode {
	// these friend functions are used this way so that we can access the private
	// properties of the class ContactNode for these methods. In other words, we 
	// are saying that it is OK for these functions to access the private fields. 
	friend void InsertContactAfter(ContactNode* first, ContactNode* next);
	friend void DeleteWholeList(ContactNode* node);
// private fields that essentially define what a ContactNode is
private:
	// ContactNode name
	string m_contactName;
	// ContactNode phone number
	string m_contactPhoneNum;
	// having a ContactNode be a part of a ContactNode means that we 
	// are creating a list of ContactNodes. If this field is null, then it means
	// that there is no other ContactNode that follows this in the list. 
	ContactNode* m_nextNodePtr;
// public fields that are used to carry out tasks that are needed in the main. 
public:
	// blank constructor of a ContactNode
	ContactNode();
	// defined constructor of a ContactNode
	ContactNode(string contactNamestring, string contactPhoneNum, ContactNode* nextNodePtr);
	// prints info of a ContactNode
	void PrintContactNode();
	// gets the next ContactNode in the linked list
	ContactNode* GetNextContact();
	
};

#endif