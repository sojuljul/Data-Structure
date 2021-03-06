// MyArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	// ARRAY
	int arr1[5];

	int length = sizeof(arr1) / sizeof(arr1[0]);
	cout << "length: " << length << endl;

	for (int i = 0; i < length; i++)
	{
		arr1[i] = i;
	}

	for (int i = 0; i < length; i++)
	{
		cout << arr1[i] << " -> ";
	}
	cout << endl;

	/////////////////////////////////////
	////////////////////////////////////
	// VECTOR

	vector <int> arr2;
	arr2.push_back(1);
	arr2.push_back(3);
	arr2.push_back(5);

	cout << "\nvector 2: " << endl;
	for (int i = 0; i < arr2.size(); i++)
	{
		cout << arr2[i] << " -> ";
	}
	cout << endl;

	cout << "\nvector 3" << endl;
	vector <int> arr3(arr2.begin(), arr2.end());

	for (int i = 0; i < arr3.size(); i++)
	{
		cout << arr3[i] << " -> ";
	}
	cout << endl;

	cout << "begin to end" << endl;
	for (auto it = arr3.begin(); it != arr3.end(); it++)
	{
		cout << *it << " -> ";
	}
	cout << endl;

	cout << "rbegin to rend" << endl;
	for (auto it = arr3.rbegin(); it != arr3.rend(); it++)
	{
		cout << *it << " -> ";
	}
	cout << endl;

	//arr3.clear();
	//arr3.pop_back();

	vector<int>::iterator itTest;
	itTest = arr3.begin();
	arr3.erase(itTest);

	for (int i = 0; i < arr3.size(); i++)
	{
		cout << arr3[i] << " -> ";
	}
	cout << endl;
}


