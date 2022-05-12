#include <iostream>
#include "SortTestHelper.h"
#include "SelectionSort.h"
#include "InsertionSort.h"

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
		// �Ż�, ÿһ��Bubble Sort��������Ԫ�ط���������λ��
		// ������һ������, ����Ԫ�ؿ��Բ��ٿ���
		n--;
	}while(swapped)
}

// ���ǵĵڶ���bubbleSort,ʹ��newn�����Ż�
template<typename T>
void bubbleSort2(T arr[], int n)
{
	int newn;// ʹ��newn�����Ż�

	do
	{
		newn = 0;
		for (int i = 0; i < n; i++)
		{
			if (arr[i - 1] > arr[i])
			{
				swap(arr[i - 1], arr[i]);

				//��¼���һ�εĽ���λ��,�ڴ�֮���Ԫ������һ��ɨ���о�������
				newn = i;
			}
			n = newn;
		}
	} while (newn>0);
}

int main()
{
	int n = 20000;
	// ����1 һ�����
	cout << "Test for random array, size = " << n << ", randome range [0, " << n << "]" << endl;

	int *arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);
	int *arr3 = SortTestHelper::copyIntArray(arr1, n);
	int *arr4 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
	SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
	SortTestHelper::testSort("Bubble Sort 2", bubbleSort, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	cout << endl;


	// ����2 ���Խ������������
	int swapTimes = 100;

	cout << "Test for nNearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;

	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
	SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
	SortTestHelper::testSort("Bubble Sort 2", bubbleSort, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;

	cout << endl;


	// ����3 ������ȫ���������
	// ������ȫ��������飬ð������Ҳ����ΪO(n)������㷨
	swapTimes = 0;
	n = 10000000;    // ���ڲ������򷨺�ð����������ȫ���������¶�����ΪO(n)�㷨
					 // �������ǵĲ������ݹ�ģ���Ϊ1000,0000
	cout << "Test for ordered array, size = " << n << endl;

	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);
	arr3 = SortTestHelper::copyIntArray(arr1, n);
	arr4 = SortTestHelper::copyIntArray(arr1, n);

	// ����������£����ٲ���ѡ�������㷨
	//SortTestHelper::testSort("Selection Sort", selectionSort, arr1, n);
	SortTestHelper::testSort("Insertion Sort", insertionSort, arr2, n);
	SortTestHelper::testSort("Bubble Sort", bubbleSort, arr3, n);
	SortTestHelper::testSort("Bubble Sort 2", bubbleSort, arr4, n);

	delete[] arr1;
	delete[] arr2;
	delete[] arr3;
	delete[] arr4;


	return 0;
}