#include <iostream>

using namespace std;

// 我们的第一版bubbleSort
template<typename T>
void bubbleSort(T arr[], int n)
{
	bool swapped;

	do
	{
		swapped = false;
		for (int i = 1; i < n; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				swap(arr[i - 1], arr[i]);
				swapped = true;
			}
		}
	}while(swapped)
}

// 我们的第二版bubbleSort,使用newn进行优化
template<typename T>
void bubbleSort2(T arr[], int n)
{
	int new
}