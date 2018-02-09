// YeeAssignment4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class LinkedListA4
{
protected:
	struct node       //node struct to hold nodes
	{
		int data;
		struct node *next;
	};
	node *head;
	int size;

public:
	//@:constructor linkedLIstA4
	//purpose: default constructor 
	//===================================================================================================================================================
	LinkedListA4()
	{
		head = nullptr;
		size = 0;
	}
	//===================================================================================================================================================
	//@:addBack
	//purpose: takes in integer, adds to back of list  
	//===================================================================================================================================================
	void addBack(int value)
	{
		node *newNode;
		node *pointer;
		newNode = new node;
		newNode->data = value;
		newNode->next = nullptr;
		if (head == nullptr) //if first element of the node 
		{
			head = newNode;
			size++;
		}
		else
		{
			pointer = head;
			while (pointer->next) //while not at end of list
			{
				pointer = pointer->next;
			}
			pointer->next = newNode;
			size++;
		}
	}
	//===================================================================================================================================================
	//@:addFront
	//purpose: takes integer, appends to front of list 
	//===================================================================================================================================================
	void addFront(int value)
	{
		node *newNode;
		newNode = new node;
		newNode->data = value;
		newNode->next = head;
		head = newNode;
		size++;
	}
	//===================================================================================================================================================
	//@: remove  
	//purpose: given sepcified number, will remove it from the list if it exists 
	//===================================================================================================================================================
	int remove(int num)
	{
		node *nodePtr;
		node *previous = nullptr;;
		if (head == nullptr)
		{
			return 0;
		}
		if (head->data == num)   //if want to delete head 
		{
			nodePtr = head->next;
			delete head;
			head = nodePtr;
			size--;
		}
		else
		{
			nodePtr = head;
			while (nodePtr != nullptr && nodePtr->data != num)
			{
				previous = nodePtr;
				nodePtr = nodePtr->next;
			}
			if (nodePtr->next != nullptr)
			{

				previous->next = nodePtr->next;
				size--;
				delete nodePtr;
			}
			else
			{
				previous->next = nullptr;
				delete nodePtr;
				size--;
			}
		}
	}
	//===================================================================================================================================================
	//@:removeFront 
	//purpose:  will remove the first elmeent in the list 
	//===================================================================================================================================================
	int removeFront()
	{
		if (head == nullptr)
		{
			return -10;
		}
		else if (size == 1)
		{
			int temp = head->data;
			delete head;
			head = nullptr;
			return temp;
		}
		else
		{
			node *temp = head->next;
			int data = head->data;
			delete head;
			head = temp;
			size--;
			return data;
		}
	}
	//===================================================================================================================================================
	//@:removeBack
	//purpose:  will remove from the back of the list 
	//===================================================================================================================================================
	int removeBack()
	{
		if (head == nullptr)
		{
			return -10;
		}
		else if (size == 1)
		{
			int temp = head->data;
			delete head;
			head = nullptr;
			return temp;
		}
		else
		{
			size--;
			node *pointer = head;
			node *previous = nullptr;
			while (pointer->next != nullptr)
			{
				previous = pointer;
				pointer = pointer->next;
			}
			previous->next = nullptr;
			int data = pointer->data;
			delete pointer;
			size--;
			return data;
		}
	}
	//===================================================================================================================================================
	//@:print 
	//purpose: prints out all elements in the list 
	//===================================================================================================================================================
	void print()
	{
		node *temp = head;
		cout << "[";
		while (temp != nullptr)
		{
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << "]";
	}
	//===================================================================================================================================================
	//@:destructor LinkedListA4
	//purpose:  will delete list node by node 
	//===================================================================================================================================================
	~LinkedListA4()
	{
		node *pointer = head;
		while (pointer != nullptr)
		{
			node *next = pointer->next;
			delete pointer;
			pointer = next;
		}
		head = nullptr;
	}
	//===================================================================================================================================================
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class StackA4 :public LinkedListA4 
{
private:
	int size=0; 
public: 
	//@method:pop
	//purpose: pops elmeent off 
	//===================================================================================================================================================
	int pop()
	{
		int popped=removeBack();
		size--;
		return popped;
	}
	//===================================================================================================================================================
	//@method:push 
	//purpose: puts elmeent following lifo
	//===================================================================================================================================================
	void push(int value)
	{
		addBack(value);
		size++;
	}
	//===================================================================================================================================================
	//@method:peek
	//purpose: gets top element of stack 
	//===================================================================================================================================================
	int peek()
	{
		return head->data;
	}
	//===================================================================================================================================================
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class QueueA4 : public LinkedListA4
{
private:
	int size = 0;
public:
	//@method:enqueue
	//purpose: puts element in queue following fifo
	//===================================================================================================================================================
	void enqueue(int value)
	{
		addBack(value);
		size++;
	}
	//===================================================================================================================================================
	//@method:dequeue
	//purpose: puts elmeent in queue following fifo
	//===================================================================================================================================================
	int dequeue()
	{
		int temp = removeFront();
		return temp;
	}
	//===================================================================================================================================================
};
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//===================================================================================================================================================
int main()
{
	int userIn;
	while (true)
	{
		cout << "Please enter the integer corresponding to the desired action: " << endl;
		cout << "1) Manipulate Linked List  " << endl;
		cout << "2) Manipulate Stack "<<endl;
		cout << "3) Manipulate Queue "<<endl;
		cout << "4) Quit "<<endl;
		cin >> userIn;
		if (userIn == 1)
		{
			LinkedListA4 list;
			while (true)
			{
				cout << "Please enter the integer corresponding to the desired action: " << endl;
				cout << "1) add to the front of the list" << endl;
				cout << "2) add to the back of the list" << endl;
				cout << "3) delete from the back of the list" << endl;
				cout << "4) delete from the front of the list: <<endl";
				cout << "5) Print the list" << endl;
				cout << "6) done" << endl;
				int temp, temp2;
				cin >> temp;
				if (temp == 1)
				{
					cout << "Please enter the number you would like to add" << endl;
					cin >> temp2;
					cout << endl;
					list.addFront(temp2);
					list.print();
					cout << endl;
				}
				else if (temp ==2)
				{
					cout << "Please enter the number you would like to add" << endl;
					cin >> temp2;
					cout << endl;
					list.addBack(temp2);
					list.print();
					cout << endl;
				}
				else if (temp == 3)
				{
					cout << "deleting: " << list.removeBack() << endl;
					list.print();
					cout << endl;
				}
				else  if (temp == 4)
				{
					cout << "deleting: " << list.removeFront() << endl;
					list.print();
					cout << endl;
				}
				else if (temp == 5)
				{
					list.print();
					cout << endl;
				}
				else if (temp == 6)
				{
					list.~LinkedListA4();
					cout << endl;
					break;
				}
				else
				{
					cout << "Invalid input" << endl;
				}

			}
		}
		else if (userIn == 2)
		{
			StackA4 stack;
			int temp, temp2;
			while (true)
			{
				
				cout << "Please enter the integer corresponding to the desired action: ";
				cout << "1) push" << endl;
				cout << "2) pop" << endl;
				cout << "3) peek" << endl;
				cout << "4) done" << endl;
				cin >> temp;
				if (temp == 1)
				{
					cout << "Please enter an integer to push" << endl;
					cin >> temp2;
					stack.push(temp2);
					stack.print();
				}
				else if (temp == 2)
				{
					cout << " Popping " << stack.pop() << endl;
					stack.print();

				}
				else if (temp == 3)
				{
					cout << "The element at the top of the stack is " << stack.peek() << endl;
				}
				else if (temp == 4)
				{
					break;
				}
				else
				{
					cout << "Invalid input" << endl;
				}
			}
		}
		else if (userIn == 3)
		{
			QueueA4 queue;
			int temp, temp2;
			while (true)
			{
				cout << "PLease enter the integer corresponding to the desired action: " << endl;
				cout << "1) enqueue" << endl;
				cout << "2)dequeue" << endl;
				cout << "3) done" << endl;
				cin >> temp;
				if (temp == 1)
				{
					cout << "PLease enter the integer to enqueue" << endl;
					cin >> temp2;
					queue.enqueue(temp2);
					queue.print();
				}
				else if (temp == 2)
				{
					cout << "Dequeueing: " << queue.dequeue() << endl;
					queue.print();
				}
				else if (temp == 3)
				{
					break;
				}
				else
				{
					cout << "invalid input" << endl;
				}
			}
		}
		else if (userIn == 4)
		{
			cout << "Quitting..." << endl;
			exit(0);
		}
		else
		{
			cout << "Invalid input" << endl;
		}

	}
	
	return 0;
	
}
//===================================================================================================================================================

 # C-Stack-Queue-LinkedList
