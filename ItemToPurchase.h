// Chris Moroney
// CS212
// Iverson, online section
// Due 14 April 2019

#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
#include <iostream>

// the header file contains the definition of the C++ classes, which is primarily defined
// here in its most basic components, but what to actually do or assign with a particular
// class is defined in the ItemToPurchase.cpp file. 
class ItemToPurchase {
// private field contains these three fields for class ItemToPurchase. These 
// are all private because we need to be able to call upon each ItemToPurchase independently and these
// fields need to hold in their own item. These are the "properties" of the ItemToPurchase
private:
	// item name defined
	std::string m_itemName;
	// item price defined
	int m_itemPrice;
	// item quantity defined
	int m_itemQuantity;
// these public fields are what a particular ItemToFunction can actually do, more such as the 
// "actions" of ItemToPurchase. These can be called upon in main and or other classes (if included),
// and can structure an ItemToPurchase however necessary in main. 
public:
	// basic ItemToPurchase to be called on
	ItemToPurchase();
	// defined / structured ItemToPurchase to be called on
	ItemToPurchase(std::string name, int price, int quantity);
	// attaining the ItemToPurchase name
	std::string getItemName();
	// attaining the ItemToPurchase price
	int getItemPrice();
	// attaining the ItemToPurchase quantity
	int getItemQuantity();
	// multiplies the price and quantity to reach the total for that item
	int itemTotal();
	// converts a particular data type to a string
	std::string toString();
};

// these two methods work independently of an ItemToPurchase, as in it is not necessarily a property
// of an ItemToPurchase, so these can be left outside of the class in the header

// sets a particular ItemToPurchase as "blank" (blank, 0, 0)
ItemToPurchase* MakeBlankItem();
// prints the information for that particular item.
void PrintItemCost(ItemToPurchase* item);

// finished with 0 errors and 0 warnings
#endif