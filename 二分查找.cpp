/*
��˳��洢���У������м�ֵ�±꣬������ֵС���м�ֵ�������Ѱ�ң����������±ꣻ
������ֵ�����м�ֵ�����ұ�Ѱ�ң����������±ꣻֱ������ֵ�����м�ֵ����
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
		cout << "�м�ֵ��" << mid << endl;
		if (key < arr[mid])
			high = mid - 1;
		else if (key>arr[mid])
			low = mid + 1;
		else
		{
			cout << "������Ҵ�����" << num << endl;
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