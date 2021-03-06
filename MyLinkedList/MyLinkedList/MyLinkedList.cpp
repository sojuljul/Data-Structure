// MyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct node
{
	int value;
	node* next;
};

class MyLinkedList 
{

public:

	node* head;
	
	MyLinkedList();
	~MyLinkedList();
	void insert(int value);
	void deleteValue(int value);
	void print();
	void insertAtStart(int value);
	void insertAtIndex(int value, int index);
};

MyLinkedList::MyLinkedList()
{
	this->head = NULL;
}

MyLinkedList::~MyLinkedList()
{
	cout << "destructor" << endl;

	node* current = head;

	while (current != NULL)
	{
		node* delNode = new node;
		delNode = current;
		current = current->next;
		delete delNode;
	}
}

void MyLinkedList::insert(int value)
{
	node* newNode = new node;
	newNode->value = value;
	newNode->next = NULL;

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		node* current = head;

		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = newNode;
	}
	
}

void MyLinkedList::print()
{
	node* current = head;

	while (current != NULL)
	{
		cout << current->value << " -> ";
		current = current->next;
	}
	cout << endl;
}

void MyLinkedList::insertAtStart(int value)
{
	node* newNode = new node;
	newNode->value = value;
	newNode->next = head;

	head = newNode;
}

void MyLinkedList::insertAtIndex(int value, int index)
{
	node* newNode = new node;
	newNode->value = value;
	newNode->next = NULL;

	if (index == 0)
	{
		insertAtStart(value);
	}
	else
	{
		node* current = head;
		
		for (int i = 0; i < index - 1; i++)
		{
			current = current->next;
		}

		newNode->next = current->next;
		current->next = newNode;
	}
	
}

void MyLinkedList::deleteValue(int value)
{
	if (head == NULL)
	{
		cout << "empty" << endl;
		return;
	}

	if (head->value == value)
	{
		node* delNode = new node;
		delNode = head;
		head = head->next;
		delete delNode;
		return;
	}
	else
	{
		node* current = head;
		
		while (current->next != NULL)
		{
			if (current->next->value == value)
			{
				node* delNode = new node;
				delNode = current->next;

				current->next = current->next->next;
				delete delNode;
				return;
			}

			current = current->next;
		}
	}
	
}

int main()
{
	MyLinkedList test;
	test.insert(1);
	test.insert(3);
	test.insert(5);
	//test.insertAtStart(9);
	//test.insertAtIndex(9, 1);
	test.deleteValue(5);
	test.print();
}

