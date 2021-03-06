// MyTrie.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

const int alphabetSize = 26;

struct node
{
	node* charTable[alphabetSize];
	bool isEndOfWord;
};

node* createNode()
{
	node* newNode = new node;
	newNode->isEndOfWord = false;

	for (int i = 0; i < alphabetSize; i++)
	{
		newNode->charTable[i] = NULL;
	}

	return newNode;
}

bool searchNode(node* root, string key)
{
	node* current = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';

		if (current->charTable[index] == NULL)
		{
			return false;
		}

		current = current->charTable[index];
	}

	if (current != NULL && current->isEndOfWord == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void insert(node* root, string key)
{
	node* current = root;
	
	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';

		if (current->charTable[index] == NULL)
		{
			current->charTable[index] = createNode();
		}

		current = current->charTable[index];
	}

	current->isEndOfWord = true;
}



int main()
{
	node* root = createNode();

	string keys[] = { "the", "a", "there", "answer", "any" };
	int size = sizeof(keys) / sizeof(keys[0]);

	for (int i = 0; i < size; i++)
	{
		insert(root, keys[i]);
	}

	if (searchNode(root, "the"))
	{
		cout << "FOUND IT" << endl;
	}
	else
	{
		cout << "NOT FOUND" << endl;
	}

}

