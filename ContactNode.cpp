// Chris Moroney
// Iverson
// CS212 online section
// Due 21 May 2019

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include <string>

#include "ContactNode.h"
// use a namespace to be able to enable us using functions like string, cout etc.
using namespace std;
// Constructs a basic ContactNode. If there is no input, then all fields are considered NULL or blank.
ContactNode::ContactNode() {
	m_contactName = "";
	m_contactPhoneNum = "";
	m_nextNodePtr = NULL;
}
// Constructs a ContactNode. If there is input, then we set the name, number, and the next node in
// the linked list equal to the properties in the ContactNode.
ContactNode::ContactNode(string contactName, string contactPhoneNum, ContactNode* nextNodePtr) {
	m_contactName = contactName;
	m_contactPhoneNum = contactPhoneNum;
	m_nextNodePtr = nextNodePtr;
}
// sets a ContactNode (next) as the next node in a linked list, which is the ContactNode
// that follows in order to the next nodes. The order is determined by the nextNodePtr property of a ContactNode
void InsertContactAfter(ContactNode* first, ContactNode* next) {
	first->m_nextNodePtr = next;
}
// Prints the information of a ContactNode, including name and number.
void ContactNode::PrintContactNode() {
	cout << "Name: " << m_contactName << endl;
	cout << "Phone Number: " << m_contactPhoneNum << endl;
}
// returns a ContactNode that is the next ContactNode in a linked list (from the current position of a node). 
ContactNode* ContactNode::GetNextContact() {
	return m_nextNodePtr;
}
// deletes a linked list by inputing the head ContactNode. 
void DeleteWholeList(ContactNode* node) {
	// set a ContactNode next equal to the next ContactNode in the list, mainly as a placeholder
	ContactNode* next = node->m_nextNodePtr;
	// if the nextContactNode IS NOT NULL...
	if (node->m_nextNodePtr != NULL) {
		// print this message
		cout << "calling delete " << node->m_contactName << endl;
		// delete the node
		delete node;
		// then recursively move to the next ContactNode. Once there is no more ContactNodes present
		// in the nextNodePtr, or in other words we have reached the last node, then we go to the else statement,
		// and come out of the recursion loop
		DeleteWholeList(next);
	}
	// we will get to this point if node->m_nextNodePtr is NULL, which is at the very very end of a linked list
	else {
		cout << "calling delete " << node->m_contactName << endl;
		delete node;
	}
	
}
