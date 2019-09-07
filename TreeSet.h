// Chris Moroney
// Iverson
// CS 212, online section
// Due by 17 June 2019
// Project 6
// aside from removing vector, the most significant changes appeared in the
// begin(), iterator class, and ++ operator when iteration happens through the tree


// Binary Search Tree (TreeSet)
// Code from Liang, C++ Data Structures
//
// changed significantly by W.P. Iverson
// Bellevue College, WA
// Spring 2019

#ifndef TreeSet_H
#define TreeSet_H
// got rid of the vector library
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;

// the basic nodes for tree
template<typename T>
class TreeNode
{
public:
	T element; // Element contained in the node
	TreeNode<T>* left; // Pointer to the left child
	TreeNode<T>* right; // Pointer to the right child
	// ** ADDED START
	TreeNode<T>* parent;
	bool already_visited;
	// ** ADDED END
	TreeNode(T element) // Constructor
	{
		this->element = element;
		left = NULL;
		right = NULL;
		// ** ADDED START
		parent = NULL;
		already_visited = false;
		// ** ADDED END
	}
	// ** ADDED START
	TreeNode(T element, TreeNode<T>* Parent) // Constructor w/ parent
	{                                        // and visited
		this->element = element;
		left = NULL;
		right = NULL;
		parent = Parent;
		already_visited = false;
	}
	// ** ADDED END
};

// one way to get a standard forward iterator:
template <typename T>
class Iterator : public std::iterator<std::forward_iterator_tag, T>
{
public:

	Iterator(TreeNode<T>* p)
	{
		// just to make it simpler, just start wherever the parent is
		current = p;
	}


	// This was the biggest change. There was clearly something wrong with the vector technique, so my thought was to
	// make an iterator that hadn't made progress and just remained at the root before actually working through
	// the tree. This is what allows alabama to actually be in the tree, instead of just storing data values into
	// a storage area, such as a vector
	// prefix forward increment
	Iterator operator++(int dummy)  // made this a postfix ++ operator
	{
		// set this boolean to true right now. If we aren't actually done, it will turn to false and then
		// fall to the "phase 2" part (labeled below)
		bool all_done = true;
		TreeNode<T>* p;  // temporary pointer to TreeNode
		// STAGE 1 -- we need to see if from where we are, if the Node we are on is the root after traversing through the whole thing, 
		// or any other node, then we set it to false
		current->already_visited = true;
		// if the parent of the current node IS NOT NULL..
		if (current->parent != NULL)
		{
			// move to stage 2
			all_done = false;
		}
		// if the current nodes' parent IS NULL AND either the left or child is not NULL (meaning current has a child)
		else if ((current->parent == NULL) && (current->left != NULL || current->right != NULL))
			// just check where the child is
		{	// if the left child is not null, we need to check if it has already been visited
			if (current->left != NULL)
			{// if the left child has NOT been visited, we need to check it
				if (current->left->already_visited == false)
				{// move to stage 2
					all_done = false;
				}
			}
			// same process as just above, but for the right child
			if (current->right != NULL)
			{
				if (current->right->already_visited == false)
				{// set to false if we have not visited that specific node
					all_done = false;
				}
			}
		}
		// STAGE 2 -- check to see if we need to move down children any farther down the branch
		// Given our result from stage one, we just need to check and see which node to set to current so that it can be shown in the test
		// This means if a node has not been visited, we need to put that in our list, we are essentially starting at the root, then 
		// moving down the right, and then the left branches with their children. Once it is all done, we are done iterating

		// if from above, we are not all done...
		if (!all_done)
		{// we make this bool just for the sakes of if the node had been found or visited before
			bool bFound = false;
			// if the right child exists on the current node
			if (current->right != NULL)
			{
				// set the current to the right and say we FOUND IT!
				current = current->right;
				bFound = true;
			}
			else
			{// if not, check the left branch, if we have a child...
				if (current->left != NULL)
				{// set the current equal to the left and say we FOUND IT!
					current = current->left;
					bFound = true;
				}
			}
			// if we have not found a child in either circumstance down the branch...
			if (!bFound)
			{// while the parent of the one we have right now is not null (check to make sure it isn't Kansas again before we finish) and that 
			// we hadn't found a node to set still...
				while (current->parent != NULL && !bFound)
				{
					// set current equal to the parent. This means we are moving BACK UP the node to check for the other branch once we are at the
					// leaf of a branch (last node of a branch)
					current = current->parent;
					// check to make sure the left child at this point exists
					if (current->left != NULL)
					{// if the chlid exists and we hadn't already visited it (from stage 1)...
						if (current->left->already_visited == false) {
							// set our current node to the left child, meaning we are now on the left child of the original parent
							current = current->left;
							bFound = true;
						}

					}
					// do the same thing, however just on the right side just in case we are missing right children
					else if (current->right != NULL)
					{
						if (current->right->already_visited == false) {
							current = current->right;
							bFound = true;
						}

					}
				}
			}

		}
		// if the parent of the one we are on is NULL, then we set current to NULL, and this means we are done iterating
		if (current->parent == NULL) {
			current = NULL;
		}
		// return the current node we have right now to be pasted in the test
		return *this;  // return this tree, with current pointer updated
	}

	// dereference

	T& operator*()
	{
		return current->element;
	}

	// comparison operators
	bool operator == (const Iterator<T>& iterator) const
	{
		return current == iterator.current;
	}

	bool operator != (const Iterator<T>& iterator) const
	{
		return current != iterator.current;
	}

private:
	TreeNode<T>* current;

	// use of vector, got rid of
  /*
  int current;  // where we start
  vector<T> v;  // used to make a copy of tree
  void treeToVector(TreeNode<T>* p)
  {
	if (p != NULL) // recursion
	{
	  // in order tree traversal
	  treeToVector(p -> left);
	  v.push_back(p -> element);
	  treeToVector(p -> right);
	} // base case is do nothing
  }
  */
};


// HERE starts the actual Binary Search Tree structure
template <typename T>
class TreeSet
{
public:
	TreeSet();
	TreeSet(T elements[], int arraySize);
	TreeSet(TreeSet<T>& tree);
	~TreeSet();
	bool search(T element) const;
	bool insert(T element);
	void inorder() const;
	bool remove(T element);

	int getSize() const;
	vector<TreeNode<T>* >* path(T element) const;


	// EDITED: I inserted inorder here as I figured it would be the best way to
	// be able to recognize alabama the easiest, being a child of alaska all the way on 
	// the left.
	Iterator<T> begin() const
	{
		inorder();
		return Iterator<T>(root);
	};

	Iterator<T> end() const
	{
		return Iterator<T>(NULL);
	};

protected:
	TreeNode<T>* root;
	int size;
	virtual TreeNode<T>* createNewNode(T element);
	virtual TreeNode<T>* createNewNode(T element, TreeNode<T>* parent); // added

private:
	void inorder(TreeNode<T>* root) const;
	//void postorder(TreeNode<T>* root) const;
   // void preorder(TreeNode<T>* root) const;
	void copy(TreeNode<T>* root);
};


template <typename T>
TreeSet<T>::TreeSet()
{
	root = NULL;
	size = 0;
}

template <typename T>
TreeSet<T>::TreeSet(T elements[], int arraySize)
{
	root = NULL;
	size = 0;

	for (int i = 0; i < arraySize; i++)
	{
		insert(elements[i]);
	}
}

/* Copy constructor */
template <typename T>
TreeSet<T>::TreeSet(TreeSet<T>& tree)
{
	root = NULL;
	size = 0;
	copy(tree.root); // Recursively copy nodes to this tree
}

/* Copies the element from the specified tree to this tree */
template <typename T>
void TreeSet<T>::copy(TreeNode<T>* root)
{
	if (root != NULL)
	{
		insert(root->element);
		copy(root->left);
		copy(root->right);
	}
}

/* Destructor */
template <typename T>
TreeSet<T>::~TreeSet()
{
	clear();
}

/* Return true if the element is in the tree */
template <typename T>
bool TreeSet<T>::search(T element) const
{
	TreeNode<T>* current = root; // Start from the root

	while (current != NULL)
		if (element < current->element)
		{
			current = current->left; // Go left
		}
		else if (element > current->element)
		{
			current = current->right; // Go right
		}
		else // Element matches current.element
			return true; // Element is found

	return false; // Element is not in the tree
}

template <typename T>
TreeNode<T>* TreeSet<T>::createNewNode(T element)
{
	return new TreeNode<T>(element);
}

template <typename T>  // Constructor with parent pointer
TreeNode<T>* TreeSet<T>::createNewNode(T element, TreeNode<T>* Parent)
{
	return new TreeNode<T>(element, Parent);
}

/* Insert element into the binary tree
 * Return true if the element is inserted successfully
 * Return false if the element is already in the list
 */
template <typename T>
bool TreeSet<T>::insert(T element)
{
	if (root == NULL)
		root = createNewNode(element); // Create a new root
	else
	{
		// Locate the parent node
		TreeNode<T>* parent = NULL;
		TreeNode<T>* current = root;
		current->parent = NULL;
		while (current != NULL)
			if (element < current->element)
			{
				parent = current;
				current = current->left;
			}
			else if (element > current->element)
			{
				parent = current;
				current = current->right;
			}
			else
				return false; // Duplicate node not inserted

			/***** replaced with NewNodes that include parent pointers *****/
		if (element < parent->element)
			parent->left = createNewNode(element, parent);
		else
			parent->right = createNewNode(element, parent);
	}

	size++;
	return true; // Element inserted
}

/* Inorder traversal */
template <typename T>
void TreeSet<T>::inorder() const
{
	inorder(root);
}

/* Inorder traversal from a subtree */
template <typename T>
void TreeSet<T>::inorder(TreeNode<T>* root) const
{
	if (root == NULL) return;
	inorder(root->left);
	//cout << root->element << " ";
	root->already_visited = false;
	inorder(root->right);
}


/* Get the number of nodes in the tree */
template <typename T>
int TreeSet<T>::getSize() const
{
	return size;
}



/* Return a path from the root leading to the specified element */
//template <typename T>

// get rid of this part so that we can use the proper iterator, instead of storing into
// a vector

/*
vector<TreeNode<T>*>* TreeSet<T>::path(T element) const
{
  vector<TreeNode<T>* >* v = new vector<TreeNode<T>* >();
  TreeNode<T>* current = root;

  while (current != NULL)
  {
	v->push_back(current);
	if (element < current->element)
	  current = current->left;
	else if (element > current->element)
	  current = current->right;
	else
	  break;
  }

  return v;

}
*/
/* Delete an element from the binary tree.
 * Return true if the element is deleted successfully
 * Return false if the element is not in the tree */
template <typename T>
bool TreeSet<T>::remove(T element)
{
	// Locate the node to be deleted and also locate its parent node
	TreeNode<T>* parent = NULL;
	TreeNode<T>* current = root;
	while (current != NULL)
	{
		if (element < current->element)
		{
			parent = current;
			current = current->left;
		}
		else if (element > current->element)
		{
			parent = current;
			current = current->right;
		}
		else
			break; // Element is in the tree pointed by current
	}

	if (current == NULL)
		return false; // Element is not in the tree

	  // Case 1: current has no left children
	if (current->left == NULL)
	{
		// Connect the parent with the right child of the current node
		if (parent == NULL)
		{
			root = current->right;
		}
		else
		{
			if (element < parent->element)
				parent->left = current->right;
			else
				parent->right = current->right;
		}

		delete current; // Delete current
	}
	else
	{
		// Case 2: The current node has a left child
		// Locate the rightmost node in the left subtree of
		// the current node and also its parent
		TreeNode<T>* parentOfRightMost = current;
		TreeNode<T>* rightMost = current->left;

		while (rightMost->right != NULL)
		{
			parentOfRightMost = rightMost;
			rightMost = rightMost->right; // Keep going to the right
		}

		// Replace the element in current by the element in rightMost
		current->element = rightMost->element;

		// Eliminate rightmost node
		if (parentOfRightMost->right == rightMost)
			parentOfRightMost->right = rightMost->left;
		else
			// Special case: parentOfRightMost->right == current
			parentOfRightMost->left = rightMost->left;

		delete rightMost; // Delete rightMost
	}

	size--;
	return true; // Element inserted
}

#endif
