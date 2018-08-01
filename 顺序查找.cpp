/*
遍历线性表，比较给定值与表中的每个元素。
*/
#include <iostream>
using namespace std;
int find_key(int *arr,int length, int key)
{
	//将查找值存储到哨兵变量位置
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