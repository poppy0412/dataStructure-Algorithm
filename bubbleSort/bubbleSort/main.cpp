#include <iostream>

using namespace std;

// ���ǵĵ�һ��bubbleSort
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

// ���ǵĵڶ���bubbleSort,ʹ��newn�����Ż�
template<typename T>
void bubbleSort2(T arr[], int n)
{
	int new
}