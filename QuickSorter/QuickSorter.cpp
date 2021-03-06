// QuickSorter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<array>


using namespace std;

void printArray(int  anArray[]);
void quickSort(int anArray[], int start, int end);
int partition(int anArray[], int start, int end);


int main()
{

    int anArray[] = {5,4,3,2,1};
	printArray(anArray);

	quickSort(anArray, 0, 4);

	printArray(anArray);

	cin.get();
	cin.get();

    return 0;
}

void printArray(int anArray[])
{
	cout << endl << "the contents of the array are: ";
	
	for (int i = 0;i < 5;i++)
	{
		cout << anArray[i] << ", ";

	}
}

void quickSort(int anArray[], int start, int end)
{
	if (start < end)
	{
		int positionIndex = partition( anArray,  start,  end); // gets index from partition starts at the last element
		quickSort(anArray, start, positionIndex - 1); // left side of partition
		quickSort(anArray, positionIndex + 1, end);   // right side of partition

	}
}

int partition(int anArray[], int start, int end)
{
	int pivot = anArray[end];
	int partitionIndex = start; // set to start initially 

	for (int i = start;i < end;i++)
	{
		if (anArray[i] <= pivot)
		{
			swap(anArray[i], anArray[partitionIndex]); //swap if less than pivot
			partitionIndex++;
		}
	}
	swap(anArray[partitionIndex], anArray[end]); //swap pivot with element at partitionIndex
	return partitionIndex;
}

