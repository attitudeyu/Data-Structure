/*
�������Ա��Ƚϸ���ֵ����е�ÿ��Ԫ�ء�
*/
#include <iostream>
using namespace std;
int find_key(int *arr,int length, int key)
{
	//������ֵ�洢���ڱ�����λ��
	arr[0] = key;
	int idx = length;
	while (arr[idx] != arr[0]) 
		--idx;
	return idx;
}
void main()
{
	int arr[] = { 0,1,2,3,4,5 };
	int length = sizeof(arr) / sizeof(arr[0]) - 1;
	cout << "the index of key is " << find_key(arr, length, 4) << endl;
}