// MyBinTree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

struct node
{
	int data;
	node* left;
	node* right;
};

class MyBinTree 
{
private:

	node* root;

	void insertPrivate(int data, node* current);
	node* searchPrivate(int data, node* current);
	void destroyTreePrivate(node* current);

	void printInOrderPrivate(node* current);
	void printPreOrderPrivate(node* current);
	void printPostOrderPrivate(node* current);

	int sizePrivate(node* current);
	node* removePrivate(int data, node* current);
	node* findSmallestPrivate(node* current);

public:

	MyBinTree();
	//~MyBinTree();

	void insert(int data);
	node* search(int data);
	void destroyTree();

	void printInOrder();
	void printPreOrder();
	void printPostOrder();
	
	int size();
	node* remove(int data);
	node* findSmallest();


};

///////////////////////////////
// DESTROY TREE
//////////////////////////////
void MyBinTree::destroyTreePrivate(node* current)
{
	if (current != NULL)
	{
		destroyTreePrivate(current->left);
		destroyTreePrivate(current->right);
		delete current;
	}
	
}

void MyBinTree::destroyTree()
{
	if (root == NULL)
	{
		cout << "empty tree" << endl;
		return;
	}

	destroyTreePrivate(root);

	root = NULL;
}


///////////////////////////////
// REMOVE, DELETE
//////////////////////////////
node* MyBinTree::removePrivate(int data, node* current)
{
	// if root is null
	// if data < node, traverse left subtree
	// if data > node, traverse right subtree

	if (root == NULL)
	{
		return NULL;
	}
	else if (data < current->data)
	{
		current->left = removePrivate(data, current->left);
	}
	else if (data > current->data)
	{
		current->right = removePrivate(data, current->right);
	}
	else
	{
		// no children
		if (current->left == NULL && current->right == NULL)
		{
			current = NULL;
			delete current;
		}

		// 1 left child
		else if (current->right == NULL)
		{
			node* temp = current->left;
			delete current;
			return temp;
		}

		// 1 right child
		else if (current->left == NULL)
		{
			node* temp = current->right;
			delete current;
			return temp;
		}

		// 2 child
		else
		{
			// get the smallest value on right subtree
			// replace to be deleted node with small value
			// traverse right tree to delete that small value
			node* temp = findSmallestPrivate(current->right);
			current->data = temp->data;
			current->right = removePrivate(temp->data, current->right);
		}
	}

	return current;
}


node* MyBinTree::remove(int data)
{
	return removePrivate(data, root);
}



///////////////////////////////
// FIND SMALLEST
//////////////////////////////
node* MyBinTree::findSmallestPrivate(node* current)
{
	if (current == NULL)
	{
		return NULL;
	}
	else
	{
		if (current->left != NULL)
		{
			return findSmallestPrivate(current->left);
		}
		else
		{
			return current;
		}
	}
}

node* MyBinTree::findSmallest()
{
	return findSmallestPrivate(root);
}


///////////////////////////////
// SIZE
//////////////////////////////
int MyBinTree::sizePrivate(node* current)
{
	if (current == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + sizePrivate(current->left) + sizePrivate(current->right);
	}
}

int MyBinTree::size()
{
	return sizePrivate(root);
}


///////////////////////////////
// SEARCH
//////////////////////////////
node* MyBinTree::searchPrivate(int data, node* current)
{
	if (current == NULL)
	{
		return NULL;
	}
	else
	{
		if (current->data == data)
		{
			return current;
		}
		else if (data < current->data)
		{
			searchPrivate(data, current->left);
		}
		else
		{
			searchPrivate(data, current->right);
		}
	}
}

node* MyBinTree::search(int data)
{
	return searchPrivate(data, root);
}

///////////////////////////////
// POST ORDER
//////////////////////////////
void MyBinTree::printPostOrderPrivate(node* current)
{
	if (current != NULL)
	{
		printPostOrderPrivate(current->left);
		printPostOrderPrivate(current->right);
		cout << current->data << " , ";
	}
}

void MyBinTree::printPostOrder()
{
	printPostOrderPrivate(root);
}

///////////////////////////////
// PRE ORDER
//////////////////////////////
void MyBinTree::printPreOrderPrivate(node* current)
{
	if (current != NULL)
	{
		cout << current->data << " , ";
		printPreOrderPrivate(current->left);
		printPreOrderPrivate(current->right);
	}
}

void MyBinTree::printPreOrder()
{
	printPreOrderPrivate(root);
}

///////////////////////////////
// IN ORDER
//////////////////////////////
void MyBinTree::printInOrder()
{
	printInOrderPrivate(root);
}

void MyBinTree::printInOrderPrivate(node* current)
{
	if (current != NULL)
	{
		printInOrderPrivate(current->left);
		cout << current->data << " , ";
		printInOrderPrivate(current->right);
	}
}

///////////////////////////////
// CONSTRUCTOR
//////////////////////////////
MyBinTree::MyBinTree()
{
	root = NULL;
}

///////////////////////////////
// INSERT
//////////////////////////////
void MyBinTree::insertPrivate(int data, node* current)
{
	node* newNode = new node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	if (root == NULL)
	{
		root = newNode;
	}
	else if (data < current->data)
	{
		if (current->left == NULL)
		{
			current->left = newNode;
		}
		else
		{
			insertPrivate(data, current->left);
		}

	}
	else
	{
		if (current->right == NULL)
		{
			current->right = newNode;
		}
		else
		{
			insertPrivate(data, current->right);
		}
	}
}

void MyBinTree::insert(int data)
{
	insertPrivate(data, root);
}

///////////////////////////////
// MAIN
//////////////////////////////
int main()
{
	MyBinTree loona;

	loona.insert(50);
	loona.insert(30);
	loona.insert(20);
	loona.insert(40);
	loona.insert(70);
	loona.insert(60);
	loona.insert(80);

	cout << "IN ORDER" << endl;
	loona.printInOrder();

	cout << "\nPRE ORDER" << endl;
	loona.printPreOrder();

	cout << "\nPOST ORDER" << endl;
	loona.printPostOrder();

	cout << "\nSEARCH" << endl;
	cout << loona.search(1) << endl;
	cout << loona.search(100) << endl;

	cout << "\nSIZE" << endl;
	cout << loona.size();

	cout << "\nSMALLEST" << endl;
	cout << loona.findSmallest();

	cout << "\nDELETE" << endl;
	loona.remove(20);
	loona.printPreOrder();
	cout << endl;
	cout << loona.size();

	cout << endl;

	loona.remove(30);
	loona.printPreOrder();
	cout << endl;
	cout << loona.size();

	cout << "\nDESTROY TREE" << endl;
	loona.destroyTree();
	cout << loona.size();
}
