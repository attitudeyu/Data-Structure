/*
���ڻƽ�ָ�0.618:1�������������飬������鳤��n��쳲�����������±꣬���n<F[k]��Ҫ��ȫ���顣
���ƶ��ֲ��ң����ݻƽ��������ָ�ֵ���±ꡣ�������ֵ����ߣ���쳲�������������k-1��
�������ֵ���ұߣ���쳲�������������k-2��
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
	cout << "���鳤����쳲��������е�λ�ã�" << k << endl;
	for (int i = high; i < fibo_arr[k]; i++)
	{
		arr[i] = arr[high];
		cout << "���鲹��ֵ��" << arr[i]<<"�����±꣺"<< i << endl;
	}
	while (low<=high)
	{
		//���ݻƽ�������·ָ�ֵ�±�
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
				return length;//����ֵ�ǲ�ȫֵ
		}
	}
	return 0;
}
void main()
{
	int arr[Maxsize] = { 1, 16, 24, 35, 47, 59, 62, 73, 88, 99 };
	cout << "the index of key is " << fibonacci_search(arr, 10, 59) << endl;
}