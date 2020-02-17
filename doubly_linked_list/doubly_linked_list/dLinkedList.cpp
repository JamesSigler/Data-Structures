#include "dLinkedList.h"
#include <iostream>
using namespace std;

//creating the node constructor
Node::Node(int datum) {
	//giving the node a value and creating a next value
	this->datum = datum;
	this->next = NULL;
	this->prev = NULL;
}
//creating the node get function
int Node::get() {
	//returning the node data
	return this->datum;
}
//creating the node set function
void Node::set(int datum) {
	//setting the data in the node
	this->datum = datum;
}

//creating the node get_next function
Node* Node::get_next() {
	//setting get_next to next
	return this->next;
}

//creating the node set_next fucntion
void Node::set_next(Node* next) {
	//sets the node to the next node
	this->next = next;
}

Node* Node::get_prev() {
	return this->prev;
}

void Node::set_prev(Node* prev) {
	this->prev = prev;
}
//creating the constructor for the linked list class
LinkedList::LinkedList() {
	//setting the default size to zero and the head to null
	this->size = 0;
	this->head = NULL;
}

//creating the deconstructor for the linked list class
LinkedList::~LinkedList() {
	//calling deconstructor helper function
	this->destr_helper(this->head);
}

//creating the deconstructor helper function
void LinkedList::destr_helper(Node* n) {
	//checking if the list is empty
	if (n == NULL) {
		return;
	}
	//cycling until the next value is null
	else {
		this->destr_helper(n->get_next());
	}
}

//creating the insert function for linked list
void LinkedList::insert(int index, int datum) {

	//if the list is empty return
	if (index > this->size || index < 0) {
		cout << "Invalid Index" << endl;
		return;
	}

	Node* newNode = new Node(datum);

	//inserting to the 0 position
	if (index == 0) {
		newNode->set_next(this->head);
		newNode->set_prev(NULL);
		this->head = newNode;
	}

	//inserting to the Nth position
	else {
		Node* temp = head;
		for (int i = 0; i < index - 1; i++, temp = temp->get_next());
		
		//setting the previous pointer to the previous node
		newNode->set_prev(temp->get_prev());
		temp->set_prev(newNode);

		//setting the next pointer to the next node
		newNode->set_next(temp->get_next());
		temp->set_next(newNode);
		
		
	}
	//increasing the size of the list
	this->size++;
}

//creating the remove function for linked list
void LinkedList::remove(int index) {
	//making sure the index is in range
	if (index < 0 || index >= size)
	{
		return;
	}
	//checking if the list is empty
	if (head == NULL)
	{
		return;
	}

	//removing the head and pushing the elements back
	if (index == 0)
	{
		Node *temp = head;
		head = head->next;
		head->set_prev(NULL);
		delete(temp);
		size--;
		return;
	}
	//removing the Nth element and pushing the other elements back
	else {
		Node *temp = head;
		int i = 0;
		while (i<index - 1)
		{
			temp = temp->next;
			i++;
		}

		if (temp->next != NULL)
		{
			Node *del = temp->next;
			//setting the pointer to the element after the one removed
			temp->next = temp->next->next;
			if (temp->next != NULL) {
				//setting the pointer of the next element to the element before the removed element
				temp->next->prev = temp->prev;
			}
			
			delete(del);
			size--;
			return;
		}
		else {
			temp->next = NULL;
			temp->prev = temp->get_prev();
			size--;
			return;
		}
	}
}

//creating the linked list print statement
void LinkedList::print() {
	//printing the list
	Node* temp = head;
	cout << "{";
	if (temp != NULL) {
		cout << " " << temp->get();
		for (temp = temp->get_next(); temp != NULL; temp = temp->get_next()) {
			cout << ", " << temp->get();
		}
	}
	cout << " }" << endl;
}

//creating the get function for linked list
int LinkedList::get(int index) {
	//making sure input is not out of range
	if (index > this->size || index < 0) {
		cout << "Invalid Index" << endl;
		return 0;
	}
	//checking if the list is empty
	if (head == NULL)
	{
		cout << "Invalid Index" << endl;
		return 0;
	}



	Node* temp = head;
	//getting the head if index is zero
	if (index == 0)
	{
		cout << "Number at position " << index << ": " << temp->get() << endl;
		return temp->get();
	}

	//getting the element at Nth term
	for (int i = 0; i <= index; i++)
	{

		temp = temp->get_next();
		if (i = index)
		{
			cout << "Number at position " << index << ": " << temp->get() << endl;
			return temp->get();
		}
	}
	return 0;
}

//creating the linked list empty function
bool LinkedList::empty()
{

	//checking if the function is empty and printing the result
	if (head == NULL)
	{
		cout << "List is empty" << endl;
		return true;

	}
	else {

		cout << "List is not empty" << endl;
		return false;
	}
}

//creating the search function for linked list
int LinkedList::search(int datum)
{
	int value, pos = 0;
	bool flag = false;

	//making sure the list is not empty
	if (head == NULL)
	{
		cout << "List is Empty" << endl;
		return 0;
	}

	Node *temp;
	temp = head;

	//finding the first occurance of the inputted number
	while (temp != NULL)
	{
		pos++;
		if (temp->get() == datum)
		{
			flag = true;
			cout << "Element " << datum << " is Found at position " << pos - 1;
			return 0;
		}
		temp = temp->next;
	}

	//flagging if the element is not found
	if (!flag)
	{
		cout << "Element " << datum << " not Found in the List";
		return 0;
	}
	return 0;
}

void LinkedList::set(int index, int datum)
{
	if (index > this->size || index < 0) {
		cout << "Invalid Index" << endl;
		return;
	}

	Node* newNode = new Node(datum);

	if (index == 0)
	{
		head->set(datum);
	}
	else
	{
		Node* temp = head;
		for (int i = 0; i < index; i++, temp = temp->get_next());
		{
			newNode->set(temp->get());
			temp->set(datum);
		}
	}
}
