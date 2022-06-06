#pragma once
//
// Created by liuyubobobo on 7/16/16.
//

#ifndef INC_04_MERGE_SORT_BOTTOM_UP_MERGESORT_H
#define INC_04_MERGE_SORT_BOTTOM_UP_MERGESORT_H

#include <iostream>
#include <algorithm>
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

// ʹ���Ż��Ĺ鲢�����㷨, ��arr[l...r]�ķ�Χ��������
template<typename T>
void __mergeSort(T arr[], int l, int r) {

	// ����С��ģ����, ʹ�ò�������
	if (r - l <= 15) {
		insertionSort(arr, l, r);
		return;
	}

	int mid = (l + r) / 2;
	__mergeSort(arr, l, mid);
	__mergeSort(arr, mid + 1, r);

	// ����arr[mid] <= arr[mid+1]�����,������merge
	// ���ڽ������������ǳ���Ч,���Ƕ���һ�����,��һ����������ʧ
	if (arr[mid] > arr[mid + 1])
		__merge(arr, l, mid, r);
}

template<typename T>
void mergeSort(T arr[], int n) {

	__mergeSort(arr, 0, n - 1);
}

#endif //INC_04_MERGE_SORT_BOTTOM_UP_MERGESORT_H