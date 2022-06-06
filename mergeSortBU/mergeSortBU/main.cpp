#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"

using namespace std;

// ʹ���Ե����ϵĹ鲢�����㷨
template <typename T>
void mergeSortBU(T arr[], int n) {

	// Merge Sort Bottom Up ���Ż��汾
//    for( int sz = 1; sz < n ; sz += sz )
//        for( int i = 0 ; i < n - sz ; i += sz+sz )
//            // �� arr[i...i+sz-1] �� arr[i+sz...i+2*sz-1] ���й鲢
//            __merge(arr, i, i+sz-1, min(i+sz+sz-1,n-1) );


	// Merge Sort Bottom Up �Ż�
	// ����С����, ʹ�ò��������Ż�
	for (int i = 0; i < n; i += 16)
		insertionSort(arr, i, min(i + 15, n - 1));

	for (int sz = 16; sz < n; sz += sz)
		for (int i = 0; i < n - sz; i += sz + sz)
			// ����arr[mid] <= arr[mid+1]�����,������merge
			if (arr[i + sz - 1] > arr[i + sz])
				__merge(arr, i, i + sz - 1, min(i + sz + sz - 1, n - 1));

	// Merge Sort BU Ҳ��һ��O(nlogn)���Ӷȵ��㷨����Ȼֻʹ������forѭ��
	// ���ԣ�Merge Sort BUҲ������1��֮�����ɴ���100��������������
	// ע�⣺��Ҫ���׸���ѭ���������ж��㷨�ĸ��Ӷȣ�Merge Sort BU����һ������
	// �����ⲿ�����壬�Ƽ����ҵġ���ת�㷨���ԡ��γ̣��ڶ��£��������еĸ��Ӷȷ���������

}

// �Ƚ�Merge Sort��Merge Sort Bottom Up���������㷨������Ч��
// �������, �����㷨��Ч���ǲ��ġ��������������ϸ����, �Ե����ϵĹ鲢�������ʤһ�
// ����ϸ�Ĳ���, ���Բο��γ̵��������: http://coding.imooc.com/learn/questiondetail/3208.html
// ���½ڵĴ����Ҳ���������ϸ�Ĳ��Դ���
int main() {

	int n = 1000000;

	// ����1 һ���Բ���
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Merge Sort Bottom Up", mergeSortBU, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;


	// ����2 ���Խ������������
	int swapTimes = 100;
	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Merge Sort Bottom Up", mergeSortBU, arr2, n);

	delete[] arr1;
	delete[] arr2;

	return 0;
}