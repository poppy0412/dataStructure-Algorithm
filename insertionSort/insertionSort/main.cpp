#include <iostream>

using namespace std;

template<typename T>
void insertionSort(T arr[], int n)
{
	for (int i = 0; i < n; i++)
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
	return 0;
}