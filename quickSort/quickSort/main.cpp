//#include <iostream>
//#include <algorithm>
//#include "SortTestHelper.h"
//#include "MergeSort.h"
//#include "InsertionSort.h"
//
//using namespace std;
//
//// ��arr[l...r]���ֽ���partition����
//// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
//template <typename T>
//int __partition(T arr[], int l, int r)
//{
//	T v = arr[l];
//
//	// arr[l+1...j] < v ; arr[j+1...i) > v i�ǵ�ǰ�����Ԫ��
//	int j = l;
//	for (int i = l+1; i <=r; i++)
//	{
//		if (arr[i] < v)
//		{
//			j++;
//			swap(arr[j], arr[i]);
//		}
//	}
//	swap(arr[l], arr[j]);
//	return j;
//}
//
//// ��arr[l...r]���ֽ��п�������
//template <typename T>
//void __quickSort(T arr[], int l, int r)
//{
//	if (l>=r)
//	{
//		return;
//	}
//	int p = __partition(arr, l, r);
//	__quickSort(arr, l, p - 1);
//	__quickSort(arr, p + 1, r);
//}
//
//template <typename T>
//void quickSort(T arr[], int n)
//{
//	__quickSort(arr, 0, n - 1);
//}
//
//int main()
//{
//	int n = 1000000;
//
//	// ����1 һ���Բ���
//	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
//	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
//	int* arr2 = SortTestHelper::copyIntArray(arr1, n);
//
//	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
//	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
//
//	delete[] arr1;
//	delete[] arr2;
//
//	cout << endl;
//
//
//	// ����2 ���Խ������������
//	// ���Ƕ��ڽ������������, ���ǵĿ��������㷨�˻�����O(n^2)������㷨
//	// ˼��һ��Ϊʲô���ڽ������������, �����˻�����O(n^2)���㷨? :)
////    int swapTimes = 100;
////    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
////    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
////    arr2 = SortTestHelper::copyIntArray(arr1, n);
////
////    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
////    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
////
////    delete[] arr1;
////    delete[] arr2;
//
//	return 0;
//}




#include <iostream>
#include <algorithm>
#include "SortTestHelper.h"
#include "MergeSort.h"
#include "InsertionSort.h"

using namespace std;

// ��arr[l...r]���ֽ���partition����
// ����p, ʹ��arr[l...p-1] < arr[p] ; arr[p+1...r] > arr[p]
template <typename T>
int __partition(T arr[], int l, int r) {

	T v = arr[l];

	int j = l; // arr[l+1...j] < v ; arr[j+1...i) > v
	for (int i = l + 1; i <= r; i++)
		if (arr[i] < v) {
			j++;
			swap(arr[j], arr[i]);
		}

	swap(arr[l], arr[j]);

	return j;
}

// ��arr[l...r]���ֽ��п�������
template <typename T>
void __quickSort(T arr[], int l, int r) {

	if (l >= r)
		return;

	int p = __partition(arr, l, r);
	__quickSort(arr, l, p - 1);
	__quickSort(arr, p + 1, r);
}

template <typename T>
void quickSort(T arr[], int n) {

	__quickSort(arr, 0, n - 1);
}


// �Ƚ�Merge Sort��Quick Sort���������㷨������Ч��
// ���������㷨��Ȼ����O(nlogn)�����, ����Quick Sort�㷨�г�����������
// Quick SortҪ��Merge Sort��, ��ʹ���Ƕ�Merge Sort�������Ż�
int main() {

	int n = 1000000;

	// ����1 һ���Բ���
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
	SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;


	// ����2 ���Խ������������
	// ���Ƕ��ڽ������������, ���ǵĿ��������㷨�˻�����O(n^2)������㷨
	// ˼��һ��Ϊʲô���ڽ������������, �����˻�����O(n^2)���㷨? :)
//    int swapTimes = 100;
//    cout<<"Test for nearly ordered array, size = "<<n<<", swap time = "<<swapTimes<<endl;
//    arr1 = SortTestHelper::generateNearlyOrderedArray(n,swapTimes);
//    arr2 = SortTestHelper::copyIntArray(arr1, n);
//
//    SortTestHelper::testSort("Merge Sort", mergeSort, arr1, n);
//    SortTestHelper::testSort("Quick Sort", quickSort, arr2, n);
//
//    delete[] arr1;
//    delete[] arr2;


	return 0;
}