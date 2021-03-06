// MySort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void printArray(int arr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " , ";
	}
	cout << endl;
}

// store the index of the min value
// in 2nd for loop, check the list to see if theres a min value than the current stored
// outside 2nd for loop, swap
void selectionSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{	
		int minIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[minIndex] > arr[j])
			{
				minIndex = j;
			}
		}

		int temp = arr[minIndex];
		arr[minIndex] = arr[i];
		arr[i] = temp;
	}
}


// store the value to be inserted
// j is the index of the previous value
// while loop checks if previous value is > the current
// if so, move the previous value up
// outside of loop, places current value at the correct spot
void insertionSort(int arr[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int temp = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > temp)
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = temp;
	}
}

void bubbleSort(int arr[], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (arr[j] > arr[i])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int arr1[] = { 3, 1, 5, 2, 4 };
	int length = sizeof(arr1) / sizeof(arr1[0]);

	cout << "BEFORE SORT" << endl;
	printArray(arr1, length);

	cout << "\nAFTER SORT" << endl;
	//bubbleSort(arr1, length);
	//insertionSort(arr1, length);
	selectionSort(arr1, length);
	printArray(arr1, length);

}

