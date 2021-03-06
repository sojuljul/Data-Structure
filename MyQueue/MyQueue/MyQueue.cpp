// MyQueue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <queue>

using namespace std;

class MyQueue {
private:
	int front;
	int rear;
	int arr[10];
	int length;

public:

	MyQueue()
	{
		front = 0;
		rear = -1;
		length = 0;
	}

	void enqueue(int value)
	{
		if (rear == length)
		{
			cout << "full" << endl;
			return;
		}

		rear++;
		arr[rear] = value;
		length++;
	};

	int dequeue()
	{
		if (rear == -1)
		{
			cout << "empty array" << endl;
			return -1;
		}

		int temp = arr[front];
		front++;
		length--;
		return temp;
	};

	int frontValue()
	{
		if (rear == -1)
		{
			cout << "empty" << endl;
			return -1;
		}
		return arr[front];
	};

	int rearValue()
	{
		return arr[rear];
	};

	bool isEmpty()
	{
		if (rear == -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	};

	int size()
	{
		return length;
	};
};

int main()
{
	MyQueue loona;
	cout << "isempty: " << loona.isEmpty() << endl;
	cout << "front: " << loona.frontValue() << endl;
	cout << "rear: " << loona.rearValue() << endl;
	cout << "size: " << loona.size() << endl;

	loona.enqueue(1);
	loona.enqueue(3);
	loona.enqueue(5);

	cout << "front: " << loona.frontValue() << endl;
	cout << "rear: " << loona.rearValue() << endl;
	cout << "size: " << loona.size() << endl;
	cout << "isempty: " << loona.isEmpty() << endl;

	cout << "dequeue: " << loona.dequeue() << endl;
	cout << "front: " << loona.frontValue() << endl;
	cout << "rear: " << loona.rearValue() << endl;
	cout << "size: " << loona.size() << endl;

	//////////////////////////////////////////////////
	///////////////////////////////////////////////////

	//using stl queue
	cout << "\nSTL QUEUE" << endl;

	queue <int> test;

	test.push(1);
	test.push(2);
	test.push(5);

	cout << "size: " << test.size() << endl;
	cout << "front: " << test.front() << endl;
	cout << "back: " << test.back() << endl;

	test.pop();

	cout << "size: " << test.size() << endl;
	cout << "front: " << test.front() << endl;
	cout << "back: " << test.back() << endl;
}


