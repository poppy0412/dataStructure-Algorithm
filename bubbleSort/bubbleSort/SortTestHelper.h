#pragma once
#ifndef SORTTESTHELPER_H
#define SORTTESTHELPER_H

#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

namespace SortTestHelper
{
	// 生成有n个元素的随机数组,每个元素的随机范围为[rangeL, rangeR]
	int * generateRandomArray(int n, int range_l, int range_r)
	{
		int * arr = new int[n];

		srand(time(NULL));
		for (int  i = 0; i < n; i++)
		{
			arr[i] = rand() % (range_r - range_l + 1) + range_l;
			return arr;
		}
	}

	// 生成一个近乎有序的数组
	// 首先生成一个含有[0...n-1]的完全有序数组, 之后随机交换swapTimes对数据
	// swapTimes定义了数组的无序程度:
	// swapTimes == 0 时, 数组完全有序
	// swapTimes 越大, 数组越趋向于无序
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

	// 拷贝整型数组a中的所有元素到一个新的数组, 并返回新的数组
	int * copyIntArray(int a[], int n)
	{
		int * arr = new int[n];

		for (int i = 0; i < n; i++)
		{
			arr[i] = a[i];
		}

		return arr;
	}

	// 打印arr数组的所有内容
	template<typename T>
	void printArray(T arr[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << arr[i];
		}
		cout << endl;
	}

	// 判断arr数组是否有序
	template<typename T>
	bool isSorted(T arr[], int n)
	{
		for (int i = 0; i < n-1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				return false;
			}
		}

		return true;
	}

	// 测试sort排序算法排序arr数组所得到结果的正确性和算法运行时间
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
