// Chris Moroney
// Iverson
// CS212, online section
// Due by 11 June 2019
// Project 5
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
 
template<typename T>
class Node
{
public:
	T element;  // Element contained in the node
	Node<T> *next; // Pointer to the next node
	
	// No-arg constructor
	Node() 
  {
		next = NULL;
	}

	// Constructor
	Node(T element) {
		this->element = element;
		next = NULL;
	}
};

template<typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T> 
{
public:
	Iterator(Node<T>* p) 
  {
		current = p;
	}

	Iterator operator++() 
  {
		current = current -> next;
		return *this;
	};

	T& operator*() 
  {
		return current -> element;
	}

	bool operator==(const Iterator<T> &iterator) 
  {
		return current == iterator.current;
	}

	bool operator!=(const Iterator<T> &iterator)
  {
		return current != iterator.current;
	}

private:
	Node<T>* current;
};
 
template<typename T>
class LinkedList 
{
public:
	LinkedList();
	LinkedList(LinkedList<T>& list);
	virtual ~LinkedList();
	void addFirst(T element);
	void addLast(T element);
	T getFirst() const;
	T getLast() const;
	T removeFirst() throw (runtime_error);
	T removeLast();
	void add(T element);
	void add(int index, T element);
	void clear();
	T get(int index) const;
	int indexOf(T element) const;
	bool isEmpty() const;
	int getSize() const;
	T removeAt(int index);
	T set(int index, T element);

	// added methods and operator overloads
	void addAll(LinkedList<T>& otherList);
	void removeAll(LinkedList<T>& otherList);
	void retainAll(LinkedList<T>& otherList);
	LinkedList<T> operator+ (LinkedList<T>& otherList);
	LinkedList<T> operator- (LinkedList<T>& otherList);
	LinkedList<T> operator^ (LinkedList<T>& otherList);
	T &operator[](int index) const;
	LinkedList<T> operator=(const LinkedList<T>& list);
	int lastIndexOf(T element) const;
	void remove(T element);
	bool contains(T element) const;

	Iterator < T > begin() const
    {
		return Iterator<T>(head);
	};

	Iterator < T > end() const
    {
		return Iterator < T > (tail->next);
	};

private:
	Node<T>* head;
	Node<T>* tail;
	int size;
};

template<typename T>
LinkedList<T>::LinkedList() 
{
	head = tail = NULL;
	size = 0;
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T>& list) 
{
	head = tail = NULL;
	size = 0;

	Node<T> *current = list.head;
	while (current != NULL) 
  {
		this->add(current->element);
		current = current->next;
	}
}

template<typename T>
LinkedList<T>::~LinkedList() 
{
	clear();
}

template<typename T>
void LinkedList<T>::addFirst(T element) 
{
	Node<T> *newNode = new Node<T>(element);
	newNode->next = head;
	head = newNode;
	size++;

	if (tail == NULL)
		tail = head;
}

template<typename T>
void LinkedList<T>::addLast(T element) 
{
	if (tail == NULL) 
  {
		head = tail = new Node<T>(element);
	}
	else 
  {
		tail->next = new Node<T>(element);
		tail = tail->next;
	}
	
	size++;
}

template<typename T>
T LinkedList<T>::getFirst() const 
{
	if (size == 0) throw runtime_error("Index out of range");
	else return head->element;
}

template<typename T>
T LinkedList<T>::getLast() const 
{
	if (size == 0) throw runtime_error("Index out of range");
	else return tail->element;
}

template<typename T>
T LinkedList<T>::removeFirst() throw (runtime_error)
{
	if (size == 0) throw runtime_error("No elements in the list");
	else 
  {
		Node<T> *temp = head;
		head = head->next;
		if (head == NULL) tail = NULL;
		size--;
		T element = temp->element;
		delete temp;
		return element;
	}
}

template<typename T>
T LinkedList<T>::removeLast() 
{
	if (size == 0) throw runtime_error("No elements in the list");
	else if (size == 1) 
  {
		Node<T> *temp = head;
		head = tail = NULL;
		size = 0;
		T element = temp->element;
		delete temp;
		return element;
	} 
  else
  {
		Node<T> *current = head;
		for (int i = 0; i < size - 2; i++)
			current = current->next;
			Node<T> *temp = tail;
			tail = current;
			tail->next = NULL;
			size--;
			T element = temp->element;
			delete temp;
			return element;
	}
}

template<typename T>
void LinkedList<T>::add(T element) 
{
	addLast(element);
}

template<typename T>
void LinkedList<T>::add(int index, T element) 
{
	if (index == 0) addFirst(element);
	else if (index >= size)
		addLast(element);
	else {
		Node<T> *current = head;
		for (int i = 1; i < index; i++)
		current = current->next;
		Node<T> *temp = current->next;
		current->next = new Node<T>(element);
		(current->next)->next = temp;
		size++;
	}
}

template<typename T>
void LinkedList<T>::clear() 
{
	while (head != NULL)
  {
		Node<T> *temp = head;
		head = head->next;
		delete temp;
	}
	tail = NULL;
  size = 0;
}


template<typename T>
T LinkedList<T>::get(int index) const 
{
	if (index < 0 || index > size - 1) throw runtime_error("Index out of range");
	Node<T> *current = head;
	for (int i = 0; i < index; i++)
		current = current->next;
	return current->element;
}

template<typename T>
int LinkedList<T>::indexOf(T element) const 
{
	// Implement it in this exercise
	Node<T> *current = head;
	for (int i = 0; i < size; i++)
  {
		if (current->element == element) return i;
		current = current->next;
	}
	return -1;
}

template<typename T>
bool LinkedList<T>::isEmpty() const 
{
	return head == NULL;
}

template<typename T>
int LinkedList<T>::getSize() const 
{
	return size;
}

template<typename T>
T LinkedList<T>::removeAt(int index) 
{
	if (index < 0 || index >= size) throw runtime_error("Index out of range");
	else if (index == 0) return removeFirst();
	else if (index == size - 1) return removeLast();
	else 
  {
		Node<T> *previous = head;
		for (int i = 1; i < index; i++) 
    {
			previous = previous->next;
		}

		Node<T> *current = previous->next;
		previous->next = current->next;
		size--;
		T element = current->element;
		delete current;
		return element;
	}
}

template<typename T>
inline T LinkedList<T>::set(int index, T element)
{
	return T();
}

template<typename T>
void printList(LinkedList<T>& list) 
{
  Iterator<T> current = list.begin();

	while (current != list.end()) 
  {
		cout << *current << " ";
      ++current;
	}

	cout << endl;
}

// ADDED FUNCTIONS HERE \\



// addAll function
template<typename T>
void LinkedList<T>::addAll(LinkedList<T>& secondList) {
	// create an iterator that can move through the other list starting at the beginning
	Iterator<T> nextPlace = secondList.begin();
	// while we haven't reached the end of the list
	while (nextPlace != secondList.end()) {
		// add it to our original list
		add(*nextPlace);
		// then move to the next value
		++nextPlace;
	}
}
// removeAll function
template<typename T>
void LinkedList<T>::removeAll(LinkedList<T>& secondList) {
	// create an iterator that can move through the other list starting at the beginning 
	Iterator<T> nextPlace = secondList.begin();
	// while we haven't reached the end of the new list
	while (nextPlace != secondList.end()) {
		// if the index of the value exists (not beyond 0, or the start)
		if (indexOf(*nextPlace) > -1) {
			// remove that value from the index on the original list, which will
			// essentially make the "difference" between the two lists
			removeAt(indexOf(*nextPlace));
		}
		// move on and check the next value
		++nextPlace;
	}
}
//retainAll function
template<typename T>
void LinkedList<T>::retainAll(LinkedList<T>& secondList){
	// assign nodes to certain areas within the list

	// the pointer starts at the head, which will then move progressively
	Node<T>* pointer = head;
	// previous will indicate the node before the pointer
	Node<T>* previous = NULL;
	// we will use the pointerHolder to keep a place for the pointer to move forward
	Node<T>* pointerHolder = NULL;
	// while the node we are looking at now is not null...
	while (pointer != NULL) {
		// if the new lists actually contains the element in the original list
		if (secondList.contains(pointer->element)) {
			// just move on
			// shift our previous forward 
			previous = pointer;
			// focus on the new node
			pointer = pointer->next;
		}
		else {
			// if not, then we need to check if we are at the beginning or end of the list
			bool atHead = !previous;
			bool atTail = !pointer->next;
			// if we are at the head...
			if (atHead) {
				// we set the head's private value to the next, so that
				// the list doesn't have a NULL head
				head = pointer->next;
			// else if we are at the tail...
			}
			else if (atTail) {
				// we don't want a NULL tail, so we set it to the previous value
				tail = previous;
			}
			// otherwise we can just shift our values
			else {
				previous->next = pointer->next;
			}
			// we then have to reduce the size so that we don't have NULL
			// spaces in our list
			size--;
			// use the holder to keep a spot for the next value that we will look at
			pointerHolder = pointer->next;
			// delete the current pointer we are on
			delete pointer;
			// then just set the pointer to the holder, which allows us to move through the whole list
			pointer = pointerHolder;
		}
	}
	// keep going until finished through the whole list, to find our union
}

// operator to demonstrate union
template<typename T>
LinkedList<T> LinkedList<T>::operator+ (LinkedList<T>& otherList){
	// use the addAll to return a list with union properties (all between both lists)
	addAll(otherList);
	return *this;
}

// operator to demonstrate difference
template<typename T>
LinkedList<T> LinkedList<T>::operator-(LinkedList<T>& otherList){
	// use the removeAll to return a list with difference properties (between both lists)
	removeAll(otherList);
	return *this;
}

// operator to demonstrate intersection
template<typename T>
LinkedList<T> LinkedList<T>::operator^(LinkedList<T>& otherList){
	// use the retainAll to return a list with alike properties (between both lists)
	retainAll(otherList);
	return *this;
}
// sets a list equal to another
template<typename T>
LinkedList<T> LinkedList<T>::operator=(const LinkedList<T>& newList){
	// making a new list, so we need to set our properties accordingly without any info
	head = NULL;
	tail = NULL;
	size = 0;
	// use this node to point to a current node within the list we are taking in
	Node<T>* pointing = newList.head;
	// while our pointing node is not NULL...
	while (pointing != NULL){
		// add it to our work in progress returning linked list
		this->add(pointing->element);
		// move on to the next element
		pointing = pointing->next;
	}
	// return our new linked list
	return *this;
}
// able to access an element in the list with this operator
template<typename T>
T& LinkedList<T>::operator[](int index) const {
	// I first tried to just use the get function and overload the operator that way,
	// but it continually didn't work because of an error, but I found for some reason using 
	// pretty much the same code down here worked, don't know why.

	// throw exception if we are not in the range of the list 
	// (needed to research and get help for this part)
	if (index < 0 || index > size - 1) throw runtime_error("Index out of range");
	// set our pointer equal to the head, so we start at the beginning
	Node<T>* pointer = head; 
	// I used a for loop because I was able to access the index value, though I'm not
	// entirely sure why size didn't work when I tried
	for (int i = 0; i < index; i++) {
		pointer = pointer->next;
	}
	// return the value that we are looking for
	return pointer->element;
}

// removes a specific value in the linked list
template<typename T>
void LinkedList<T>::remove(T removeVal) {
	// this is VERY similar to the retainAll function because we are removing
	// certain values as we iterate through, but this time we are only removing
	// one value at particular instances, instead of finding the similarities. 
	// Logic will be very similar to that of the retainAll, so not as many comments
	// will be used here

	Node<T>* pointer = head;
	Node<T>* previous = NULL;
	Node<T>* pointerHolder = NULL;

	while (pointer != NULL) {
		// MAJOR DIFFERENECE HERE: we want to see if the value we are looking at
		// matches taht of the value we are trying to remove.

		// if the value is NOT our seeking value...
		if (pointer->element != removeVal) {
			// just move on
			previous = pointer;
			pointer = pointer->next;
		}
		else {
			bool isStart = !previous;
			bool isEnd = !pointer->next;

			if (isStart) {
				head = pointer->next;
			}
			else if (isEnd) {
				tail = previous;
			}
			else {
				previous->next = pointer->next;
			}
			size--;
			pointerHolder = pointer->next;
			delete pointer;
			pointer = pointerHolder;
		}
	}
}
// method to find last index of a particular value in the linked list
template<typename T>
int LinkedList<T>::lastIndexOf(T instance) const{
	// start at the beginning of the list by assigning our head
	Node<T>* pointer = head;
	// returnVal starts at -1 in case we can't find any of our value
	int returnVal = -1;
	// initialize finder as the location where our value is found if found
	int finder = 0;
	// while we are still in the list...
	while (pointer != NULL) {
		// if the value we are looking at IS our value we are looking for (found an instance
		// of our value)
		if (pointer->element == instance) {
			// set returnVal equal to the point where we found our value
			returnVal = finder;
			// increase value of finder, so if we find our value again, it is truly
			// the LAST instance
			finder++;
			// move our pointer forward
			pointer = pointer->next;
		}
		// return whatever returnVal is equal to by the end of the list. If unfound,
		// returns -1
		return returnVal;
	}
}
// boolean that determines whether or not a particular value is in the linked list
template<typename T>
bool LinkedList<T>::contains(T location) const {
	// if the value of our value is not unfound...
	if (indexOf(location) != -1) {
		// then we do have our value
		return true;
	}
	else {
		// otherwise we don't
		return false;
	}
}

#endif