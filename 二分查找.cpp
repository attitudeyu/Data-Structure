/*
在顺序存储表中，迭代中间值下标，若给定值小于中间值则在左边寻找，更新最右下标；
若给定值大于中间值则在右边寻找，更新最左下标；直到给定值等于中间值返回
*/
#include <iostream>
using namespace std;
int binary_search(int *arr, int length, int key)
{
	int low = 1, high = length;
	int mid;
	int num = 0;
	while (low <= high)
	{
		++num;
		mid = (low + high) / 2;
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
	cout << "the index of key is " << binary_search(arr, length, 8) << endl;
}