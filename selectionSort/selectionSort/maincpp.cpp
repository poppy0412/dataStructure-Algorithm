#include <iostream>
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void selectionSort(T arr[], int n) {

	for (int i = 0; i < n; i++) {

		int minIndex = i;
		for (int j = i + 1; j < n; j++)
			if (arr[j] < arr[minIndex])
				minIndex = j;

		swap(arr[i], arr[minIndex]);
	}
}

int main()
{
	// ²âÊÔÅÅÐòËã·¨¸¨Öúº¯Êý
	int N = 100;
	int *arr = SortTestHelper::generateRandomArray(N, 0, 100000);
	selectionSort(arr, N);
	SortTestHelper::printArray(arr, N);
	delete[] arr;
	cout << "22" << endl;
	return 0;
}