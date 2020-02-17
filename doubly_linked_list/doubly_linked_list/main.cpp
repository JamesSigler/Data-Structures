#include "dLinkedList.h"
#include <iostream>
using namespace std;


int main() {

	//creating a default LinkedList called "list"
	LinkedList *list = new LinkedList;

	//creating the menu and menu variables
	int ch, pos, in, val;
	while (1)
	{

		//printing information for user
		cout << "\nEnter Operation to execute";
		cout << "\n1:Print\n2:Insert\n3:Remove\n4:Get\n5:Set\n6:Search\n7:Empty\n8:Exit\n";
		cout << "\nEnter Your Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			//print the list
			list->print();
			break;
		case 2:
			//insert to the linked list
			cout << "Enter position to insert: ";
			cin >> pos;
			cout << "Enter number to insert into position " << pos << ": ";
			cin >> in;
			list->insert(pos, in);
			break;
		case 3:
			//removing from the linked list
			cout << "Enter position to remove: ";
			cin >> pos;
			list->remove(pos);
			break;
		case 4:
			//getting a value from the linked list
			cout << "Enter position of number: ";
			cin >> pos;
			list->get(pos);
			break;
		case 5:
			//changing a value already in the linked list
			cout << "Enter position to change: ";
			cin >> pos;
			cout << "Enter number to change at postition " << pos << ": ";
			cin >> in;
			list->set(pos, in);
			break;
		case 6:
			//searching for a value in the linked list
			cout << "Enter the Value to be Searched:";
			cin >> val;
			list->search(val);
			break;
		case 7:
			//checking if the linked list is empty
			list->empty();
			break;
		case 8:
			//removing the linked list from memory and exiting the program
			delete list;
			return 0;
		}
	}
	return 0;
}

