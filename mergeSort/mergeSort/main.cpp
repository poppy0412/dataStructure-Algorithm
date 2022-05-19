#include <iostream>
#include <algorithm>

using namespace std;

// 递归使用归并排序,对arr[l...r]的范围进行排序
template<typename T>
void __mergeSort(T arr[], int l,int r)//l第一个元素位置，r最后一个元素位置
{
	
}

template<typename T>
void mergeSort(T arr[], int n)
{
	//创建子函数，__开头的函数只应该被所在函数调用，不应该用户调用，但实际用户能调用
	__mergeSort(arr, 0, n - 1);
}

int main()
{
	return 0;
	
}