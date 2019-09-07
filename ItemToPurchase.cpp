// Chris Moroney
// CS212
// Iverson, online section
// Due 14 April 2019

#include<stdio.h>
#include<string.h>
// includes the header file to be called on
#include "ItemToPurchase.h"
#include <iostream>
 
// These are all of the ItemsToPurchase definitions from public in the header that are able to be defined
// more clearly, and more importantly called upon in the main function and have something done with 
// the class or method. 

// normally I would put the namespace here, but I found for some reason in my program it was more 
// without errors or warnings to leave out the namespace and put the namespace with each <iostream> part
// as necessary.


// if calling on a ItemToPurchase with no input, then ItemToPurchase is assumed to be blank and 0 item 0 quantity. 
ItemToPurchase::ItemToPurchase() {
	m_itemName = "blank";
	m_itemPrice = 0;
	m_itemQuantity = 0;
}
// if calling on an ItemToPurchase with input, then set the private fields in the header equal to 
// all data types in this ItemToPurchase. Note: since we define these terms here with the private
// fields, this allows us to later access each individual part with "mini" methods down below, 
// such as to find just the itemName of an ItemToPurchase
ItemToPurchase::ItemToPurchase(std::string itemName, int itemPrice, int itemQuantity) {
	m_itemName = itemName;
	m_itemPrice = itemPrice;
	m_itemQuantity = itemQuantity;
}

// this returns the String part of the output back into main. In other words what we see on the 
// screen is because of this line. It is specific to each ItemToPurchase, which is why we include 
// the class as a property of ItemToPurchase
std::string ItemToPurchase::toString() {
	return getItemName() + ", " + std::to_string(getItemQuantity()) + " @ $" + std::to_string(getItemPrice());
}
// returns ItemToPurchase name because it was defined in the method above
std::string ItemToPurchase::getItemName() {
	return m_itemName; 
}
// returns ItemToPurchase price because it was defined in the method above
int ItemToPurchase::getItemPrice() {
	return m_itemPrice; 
}
// returns ItemToPurchase quantity because it was defined in the method above
int ItemToPurchase::getItemQuantity() {
	return m_itemQuantity;
}
// returns ItemToPurchase total price, which is the quantity * individual price
int ItemToPurchase::itemTotal() {
	return (m_itemPrice * m_itemQuantity);
} 

// next two methods are not specific to a definition of ItemToPurchase, but moreover
// other things that an ItemToPurchase can do.

// this pointer method refers to an ItemToPurchase in the main that wants to return as 
// blank. In this case, we are simply returning an ItemToPurchase with no input, such as 
// that in a non-inputted ItemToPurchase. 
ItemToPurchase* MakeBlankItem() {
	ItemToPurchase* newItem = new ItemToPurchase();
	return newItem;
}
// although this function was never used in main and was provided in ItemToPurchase.h, 
// this method can be used to print out the cost of an indivudal item, such as that of JUST
// chocolate chip cookies etc. In main, this function is replaced with a for loop, but I thought
// just to write the code for this function anyways as it was mentioned in ItemToPurchase.h
void PrintItemCost(ItemToPurchase* item) {
	// itemTotal() is defined above
	std::cout << item->itemTotal();
}