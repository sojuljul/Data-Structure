// MyHash.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct node
{
	int key;
	int value;
	node* next;
};

class HashMap
{
private:
	static const int tableSize = 10;
	node* hashTable[tableSize];

public:
	HashMap();

	int hashFunction(int key);
	void insert(int key, int value);
	void printTable();
	void printIndex(int index);

};

////////////////////////////////
// PRINT INDEX
///////////////////////////////
void HashMap::printIndex(int index)
{
	node* current = hashTable[index];
	
	while (current != NULL)
	{
		cout << current->key << " -> " << current->value << endl;
		current = current->next;
	}
}

////////////////////////////////
// PRINT TABLE
///////////////////////////////
void HashMap::printTable()
{
	for (int i = 0; i < tableSize; i++)
	{
		if (hashTable[i] != NULL)
		{
			cout << hashTable[i]->key << " -> " << hashTable[i]->value << endl;
		}
	}
}

////////////////////////////////
// INSERT
///////////////////////////////
void HashMap::insert(int key, int value)
{
	int index = hashFunction(key);

	node* newNode = new node;
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	if (hashTable[index] == NULL)
	{
		hashTable[index] = newNode;
	}
	else
	{
		node* current = hashTable[index];

		while (current->next != NULL)
		{
			current = current->next;
		}

		current->next = newNode;
	}
}

////////////////////////////////
// HASH FUNCTION
///////////////////////////////
int HashMap::hashFunction(int key)
{
	int hash = (key % tableSize);
	return hash;
}

////////////////////////////////
// CONSTRUCTOR
///////////////////////////////
HashMap::HashMap()
{
	for (int i = 0; i < tableSize; i++)
	{
		hashTable[i] = NULL;
	}
}

int main()
{
	HashMap loona;
	loona.insert(1, 5);
	loona.insert(2, 7);
	loona.insert(3, 4);

	loona.insert(1, 9);
	loona.insert(11, 8);

	cout << "PRINT TABLE" << endl;
	loona.printTable();

	cout << "\nPRINT INDEX 1" << endl;
	loona.printIndex(1);
}
