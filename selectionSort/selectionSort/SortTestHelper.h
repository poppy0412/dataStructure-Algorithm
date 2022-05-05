#pragma once
#ifndef SORTTESTHELPERR
#define SORTTESTHELPERR

#include <iostream>
#include <ctime>
#include <cassert>

using namespace std;


namespace SortTestHelper {

	// ������n��Ԫ�ص��������,ÿ��Ԫ�ص������ΧΪ[rangeL, rangeR]
	int *generateRandomArray(int n, int rangeL, int rangeR) {

		assert(rangeL <= rangeR);

		int *arr = new int[n];

		srand(time(NULL));
		for (int i = 0; i < n; i++)
			arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
		return arr;
	}

	// ��ӡarr�������������
	template<typename T>
	void printArray(T arr[], int n) {

		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;

		return;
	}

};
#endif // !SORTTESTHELPERR
