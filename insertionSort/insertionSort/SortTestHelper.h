#pragma once
#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H

#include <iostream>
#include <ctime>

using namespace std;

namespace SortTestHelper
{
	// ������n��Ԫ�ص��������,ÿ��Ԫ�ص������ΧΪ[rangeL, rangeR]
	int * generateRandomArry(int n, int range_l, int range_r)
	{
		int * arr = new int[n];

		srand(time(NULL));
		for (int  i = 0; i < n; i++)
		{
			arr[i] = rand() % (range_r - range_l + 1) + range_l;
			return arr;
		}
	}

	// ����һ���������������
	// ��������һ������[0...n-1]����ȫ��������, ֮���������swapTimes������
	// swapTimes���������������̶�:
	// swapTimes == 0 ʱ, ������ȫ����
	// swapTimes Խ��, ����Խ����������
	int * generateNearlyOrderedArray(int  n, int swapTimes)
	{
		int * arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = i;
		}

		srand(time(NULL));
		for (int i = 0; i < swapTimes; i++)
		{
			int pos1 = rand() % n;
			int pos2 = rand() % n;
			swap(arr[pos1], arr[pos2]);
		}

		return arr;
	}

	// ������������a�е�����Ԫ�ص�һ���µ�����, �������µ�����
	int * copyIntArray(int a[], int n)
	{
		int * arr = new int[n];

		for (int i = 0; i < n; i++)
		{
			arr[i] = a[i];
		}

		return arr;
	}

	// ��ӡarr�������������
	template<typename T>
	void printArray(T arr[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i];
		}
		cout << endl;
	}

	// �ж�arr�����Ƿ�����
	template<typename T>
	bool isSorted(T arr[], int n)
	{
		for (ont i = 0; i < n-1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				return false;
			}
		}

		return true;
	}

	// ����sort�����㷨����arr�������õ��������ȷ�Ժ��㷨����ʱ��
	template<typename T>
	void testSort(const string &sortName, void(*sort)(T[], int), T arr[], int n)
	{
		clock_t startTime = clock();
		sort(arr, n);
		clock_t endTime = clock();
		cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;

		assert(isSorted(arr, n));

		return;
	}


}

#endif//SORTTESTHELPER_H
