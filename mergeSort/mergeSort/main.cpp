#include <iostream>
#include "SortTestHelper.h"
#include "InsertionSort.h"

using namespace std;


// ��arr[l...mid]��arr[mid+1...r]�����ֽ��й鲢
template<typename  T>
void __merge(T arr[], int l, int mid, int r) {

	//* VS��֧�ֶ�̬��������, ������ʹ�� T aux[r-l+1]�ķ�ʽ����aux�Ŀռ�
	//* ʹ��VS��ͬѧ, ��ʹ��new�ķ�ʽ����aux�ռ�
	//* ʹ��new����ռ�, ��Ҫ������__merge���������, delete������Ŀռ�:)
	//T aux[r - l + 1];
	T *aux = new T[r-l+1];

	for (int i = l; i <= r; i++)
		aux[i - l] = arr[i];

	// ��ʼ����iָ����벿�ֵ���ʼ����λ��l��jָ���Ұ벿����ʼ����λ��mid+1
	int i = l, j = mid + 1;
	for (int k = l; k <= r; k++) {

		if (i > mid) {  // �����벿��Ԫ���Ѿ�ȫ���������
			arr[k] = aux[j - l]; j++;
		}
		else if (j > r) {  // ����Ұ벿��Ԫ���Ѿ�ȫ���������
			arr[k] = aux[i - l]; i++;
		}
		else if (aux[i - l] < aux[j - l]) {  // ��벿����ָԪ�� < �Ұ벿����ָԪ��
			arr[k] = aux[i - l]; i++;
		}
		else {  // ��벿����ָԪ�� >= �Ұ벿����ָԪ��
			arr[k] = aux[j - l]; j++;
		}
	}

	delete[] aux;
}

// �ݹ�ʹ�ù鲢����,��arr[l...r]�ķ�Χ��������
template<typename T>
void __mergeSort(T arr[], int l, int r) {

	if (l >= r)
		return;

	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);
	__merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {

	__mergeSort(arr, 0, n - 1);
}


// �Ƚ�InsertionSort��MergeSort���������㷨������Ч��
// �������, MergeSort����������, ���ڽ��������������������, ������2����ϸע��
int main() {

	// Merge Sort������ѧϰ�ĵ�һ��O(nlogn)���Ӷȵ��㷨
	// ������1��֮�����ɴ���100��������������
	// ע�⣺��Ҫ���׳���ʹ��SelectionSort, InsertionSort����BubbleSort����100�򼶵�����
	// ������ͼ�ʶ��O(n^2)���㷨��O(nlogn)�㷨�ı��ʲ��죺��
	int n = 50000;

	// ����1 һ���Բ���
	cout << "Test for random array, size = " << n << ", random range [0, " << n << "]" << endl;
	int* arr1 = SortTestHelper::generateRandomArray(n, 0, n);
	int* arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

	delete[] arr1;
	delete[] arr2;

	cout << endl;


	// ����2 ���Խ������������
	// ���ڽ������������, ����Խ����, InsertionSort��ʱ������Խ������O(n)
	// ���Կ��Գ���, ��swapTimes�Ƚϴ�ʱ, MergeSort����
	// ���ǵ�swapTimesС��һ���̶�, InsertionSort��ñ�MergeSort��
	/*int swapTimes = 10;
	assert(swapTimes >= 0);

	cout << "Test for nearly ordered array, size = " << n << ", swap time = " << swapTimes << endl;
	arr1 = SortTestHelper::generateNearlyOrderedArray(n, swapTimes);
	arr2 = SortTestHelper::copyIntArray(arr1, n);

	SortTestHelper::testSort("Insertion Sort", insertionSort, arr1, n);
	SortTestHelper::testSort("Merge Sort", mergeSort, arr2, n);

	delete[] arr1;
	delete[] arr2;*/

	return 0;
}