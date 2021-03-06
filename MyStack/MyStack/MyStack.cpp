// MyStack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;

class MyStack {

private:
	int top;
	int length;
	int arr[10];

public:
	MyStack()
	{
		top = -1;
		length = 0;
	}

	void push(int value)
	{
		top++;
		arr[top] = value;
		length++;
	};

	int pop() 
	{
		if (top == -1)
		{
			return -1;
		}
		int temp = arr[top];
		top--;
		length--;
		return temp;
	};

	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	int topValue()
	{
		return arr[top];
	};

	int size()
	{
		return length;
	};
};

int main()
{
	// using own stack
	MyStack loona;
	cout << "empty: " << loona.isEmpty() << endl;
	loona.push(1);
	loona.push(5);
	loona.push(3);
	loona.push(2);
	cout << "top value: " << loona.topValue() << endl;
	cout << "empty: " << loona.isEmpty() << endl;
	cout << "size: " << loona.size() << endl;
	cout << "pop: " << loona.pop() << endl;
	cout << "top: " << loona.topValue() << endl;

	//////////////////////////////
	/////////////////////////////
	
	// using STL stack
	cout << "\nSTL STACK" << endl;
	stack <int> test;
	test.push(1);
	test.push(2);
	test.push(5);
	cout << "top: " << test.top() << endl;
	cout << "size: " << test.size() << endl;
	test.pop();
	cout << "size: " << test.size() << endl;
}


