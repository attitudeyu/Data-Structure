/*
基于黄金分割0.618:1来划分有序数组，获得数组长度n在斐波那契数组的下标，如果n<F[k]需要补全数组。
类似二分查找，依据黄金比例计算分隔值的下标。如果查找值在左边，则斐波那契数组索引k-1；
如果查找值在右边，则斐波那契数组索引k-2；
*/
#include <iostream>
using namespace std;
const int fibo_arr[10] = { 0,1,1,2,3,5,8,13,21,34 };
const int Maxsize = 20;
int fibonacci_search(int *arr, int length, int key)
{
	int low = 0, high = length-1, mid = 0, k = 0;
	while (length > fibo_arr[k])
		k++;
	cout << "数组长度在斐波那契数列的位置：" << k << endl;
	for (int i = high; i < fibo_arr[k]; i++)
	{
		arr[i] = arr[high];
		cout << "数组补充值：" << arr[i]<<"数组下标："<< i << endl;
	}
	while (low<=high)
	{
		//依据黄金比例更新分隔值下标
		mid = low + fibo_arr[k-1];
		if (key < arr[mid])
		{
			k = k - 1;
			high = mid - 1;
		}
		else if (key > arr[mid])
		{
			k = k - 2;
			low = mid + 1;
		}
		else
		{
			if (mid <= length)
				return mid;
			else
				return length;//查找值是补全值
		}
	}
	return 0;
}
void main()
{
	int arr[Maxsize] = { 1, 16, 24, 35, 47, 59, 62, 73, 88, 99 };
	cout << "the index of key is " << fibonacci_search(arr, 10, 59) << endl;
}