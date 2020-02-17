#pragma once

//Creating the node class
class Node {
	int datum;
public:
	//Initiating all of the Node Functions
	Node * next;
	Node * prev;
	Node(int);
	int get();
	void set(int);
	Node* get_next();
	void set_next(Node*);
	Node* get_prev();
	void set_prev(Node*);
};

//Creating the Linked List class
class LinkedList{
	int size;
	Node* head;
	Node* tail;
public:
	//Initiating all of the Linked List Functions
	LinkedList();
	~LinkedList();
	void destr_helper(Node*);
	void insert(int, int);
	void remove(int);
	int get(int);
	void set(int, int);
	int search(int);
	bool empty();
	void print();
	int get_prev(int);
};