/*
	Badajoz, Severiano

	CS A250
	October 15, 2017

	Lab 06
*/

#include "DoublyList.h"

// createAList
void DoublyList::createAList()
{
	/*
		NOTE:
			
			* You will need to declare one pointer and 
			  you may re-use this pointer throughout the function, but
			  you are NOT allowed to create additional pointers.

			* DO NOT REMOVE EXISTING COMMENTS.

			* Pay CLOSE attention to instructions.
	*/

	/*----------------------------------------------------------------
	SECTION 1
	------------------------------------------------------------------*/

	// Create a node that stores the value 2 and make 
	// this node be the first node of the calling object.
	// List becomes: 2
	// Use the overloaded constructor.
	Node * curr = new Node(2, nullptr, nullptr);
	first = curr;
	last = curr;

	// Update count;
	count++;

	cout << "Section 1 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 2
	------------------------------------------------------------------*/

	// Create another node that stores the value 3 and 
	// insert this node to the left of the node that is 
	// storing value 2.
	// List becomes: 3 2
	curr = new Node(3, nullptr, first);
	first->setPrev(curr);
	first = curr;
	
	// Update count;
	count++;

	cout << "\n\nSection 2 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 3
	------------------------------------------------------------------*/

	// Create another node that stores the value 4 and
	// insert this node to the right of the node that is
	// storing value 3.
	// List becomes: 3 4 2
	// NO MORE than 3 statements.
	curr = new Node(4, first, last);
	first->setNext(curr);
	last->setPrev(curr);
	
	// Update count;
	count++;

	cout << "\n\nSection 3 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 4
	------------------------------------------------------------------*/

	// Delete the first node.
	// List becomes: 4 2
	free(first);
	first = last->getPrev();
	first->setPrev(nullptr);
	
	// Update count.
	count--;

	cout << "\n\nSection 4 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 5
	------------------------------------------------------------------*/

	// Insert three nodes at the end of the list storing 
	// 5 6 7 in this order.
	// List becomes: 4 2 5 6 7
	last->setNext(new Node(5, last, nullptr));
	last = last->getNext();

	last->setNext(new Node(6, last, nullptr));
	last = last->getNext();

	last->setNext(new Node(7, last, nullptr));
	last = last->getNext();
	// Update count.
	// One statement only.
	count += 3;

	cout << "\n\nSection 5 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 6
	------------------------------------------------------------------*/

	// Move last node to second position.
	// Here steps are very important. Carefully think 
	// how you can move nodes around without losing any
	// nodes and keeping all pointers pointing to the
	// correct nodes.
	// Note: 
	//		You may NOT create an additional node.
	//		NO loops are necessary.
	// List is 4 2 5 6 7 => will become 4 7 2 5 6
	
	first->getNext()->setPrev(last);
	last->setNext(first->getNext());
	first->setNext(last);
	last = last->getPrev();
	first->getNext()->setPrev(first);
	last->setNext(nullptr);
	cout << "\n\nSection 6 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 7
	------------------------------------------------------------------*/
	
	// Move the first node in between the node before last and
	// last node (the second node will become the first node
	// in the list, and the first node will become the before-last 
	// node in the list).
	//		You may NOT create an additional node.
	//		No loops are necessary.
	// List is 4 7 2 5 6 => will become 7 2 5 4 6
	curr = first->getNext();
	first->setNext(last);
	last->getPrev()->setNext(first);
	first->setPrev(last->getPrev());
	last->setPrev(first);
	first = curr;
	first->setPrev(nullptr);
	
	cout << "\n\nSection 7 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 8
	------------------------------------------------------------------*/

	// WITHOUT moving any nodes, swap around the values to 
	// create an ordered list. 
	// Note that there is no need to move the value 5.
	// You may declare an int, BUT do NOT use any literals.
	// List will become: 2 4 5 6 7
	int temp = first->getData();

	first->setData(last->getData());
	last->setData(temp);
	
	curr = last->getPrev();
	temp = first->getData();

	first->setData(curr->getData());
	curr->setData(temp);

	temp = first->getData();
	curr = first->getNext();

	first->setData(curr->getData());
	curr->setData(temp);


	
	cout << "\n\nSection 8 - TEST ALL" << endl;
	testAll();

	/*----------------------------------------------------------------
	SECTION 9
	------------------------------------------------------------------*/

	// Add two nodes storing 1 and 3 to complete the ordered list.
	// List becomes: 1 2 3 4 5 6 7
	first->setPrev(new Node(1, nullptr, first));
	first = first->getPrev();


	curr = new Node(3, nullptr, nullptr);
	first->getNext()->getNext()->setPrev(curr);
	curr->setNext(first->getNext()->getNext());
	first->getNext()->setNext(curr);
	curr->setPrev(first->getNext());
	
	// Add 2 to count.
	count += 2;

	cout << "\n\nSection 9 - TEST ALL" << endl;
	testAll();

}