// MyMapExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;


int main()
{
	unordered_map<int, int> loona;
	unordered_map<int, int>::iterator itr;

	loona[1] = 5;
	loona[2] = 7;
	loona[3] = 9;

	loona.insert(make_pair(4, 6));
	loona.insert({ 5, 10 });
	loona.insert(make_pair(5, 22));

	cout << "ITERATOR PRINT" << endl;
	for (itr = loona.begin(); itr != loona.end(); itr++)
	{
		cout << itr->first << " -> " << itr->second << endl;
	}

	cout << "\nAUTO PRINT" << endl;
	for (auto i : loona)
	{
		cout << i.first << " -> " << i.second << endl;
	}

	cout << "\nSIZE" << endl;
	cout << loona.size() << endl;

	cout << "\nFINDING KEY 2" << endl;
	unordered_map<int, int>::iterator value = loona.find(2);

	if (value == loona.end())
	{
		cout << "Not found" << endl;
	}
	else
	{
		cout << "Found: " << value->first << " -> " << value->second << endl;
	}
	
}
