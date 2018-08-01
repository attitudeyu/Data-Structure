/*
插值查找仅仅修改了二分查找计算中间值下标的公式,二分查找不考虑查找值是否偏大或偏小。
插值查找则考虑了线性表中最大最小的值，如此减少了迭代的次数。
*/
#include <iostream>
using namespace std;
int interpolation_search(int *arr, int length, int key)
{
	int low = 1, high = length;
	int mid;
	int num = 0;
	while (low <= high)
	{
		++num;
		mid = low + (high - low)*(key - arr[low]) / (arr[high] - arr[low]);
		cout << "中间值：" << mid << endl;
		if (key < arr[mid])
			high = mid - 1;
		else if (key>arr[mid])
			low = mid + 1;
		else
		{
			cout << "所需查找次数：" << num << endl;
			return mid;
		}
	}
	return 0;
}
void main()
{
	int arr[] = { 0,1,2,3,4,5,6,7,8,9 };
	int length = sizeof(arr) / sizeof(arr[0]);
	cout << "the index of key is " << interpolation_search(arr, length, 2) << endl;
}