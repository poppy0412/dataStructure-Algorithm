#include <iostream>
#include <algorithm>
#include "SelectionSort.h"
#include "SortTestHelper.h"

using namespace std;

template<typename T>
void insertionSort(T arr[], int n)
{
	for (int i = 1; i < n; i++)
	{
		// Ѱ��Ԫ��arr[i]���ʵĲ���λ��
		// д��1
//        for( int j = i ; j > 0 ; j-- )
//            if( arr[j] < arr[j-1] )
//                swap( arr[j] , arr[j-1] );
//            else
//                break;

		// д��2
//        for( int j = i ; j > 0 && arr[j] < arr[j-1] ; j -- )
//            swap( arr[j] , arr[j-1] );

		// д��3
		T e = arr[i];
		int j;// j����Ԫ��eӦ�ò����λ��
		for (j=i ; j > 0 && arr[j - 1] > e; j--)
		{
			arr[j] = arr[j - 1];
		}
		arr[j] = e;
	}
	return;
}

int main()
{
	int n = 20000;

	// ����1 һ�����
	cout<<"Test for random array,size = "<<n<<",random range [0, " << n << "]" << endl;
	int *arr1 = SortTestHelper::generateRandomArry(n, 0, n);
	int *arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

	delete[] arr1;
	delete[] arr2;
	cout << endl;

	// ����2 �����Ը�ǿ�Ĳ���
	cout << "Test for more ordered random array, size = " << n << ", random range [0, 3]" << endl;
	arr1 = SortTestHelper::generateRandomArry(n, 0, 3);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;

	// ����3 ���Խ������������
	int swapTimes = 100;
	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	return 0;
}