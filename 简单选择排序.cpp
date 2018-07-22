/*
简单选择排序
思路：
将序列分为排序和未排序两部分，每次遍历从未排序序列中获得最小或最大下标
步骤：
1.遍历序列
2.初始化最小下标
3.遍历未排序序列
4.交换元素
*/
#include <iostream>
using namespace std;
const int Maxsize = 10;
typedef struct
{
	int r[Maxsize];
	int length;
}List;
void print_list(List *ls)
{
	for (int i = 0; i < ls->length; i++)
		cout << ls->r[i] << " ";
	cout << endl;
}
void select_sort(List *ls)
{
	//1.遍历序列
	for (int i = 0; i < ls->length - 1; i++)
	{
		//2.初始化最小下标
		int min = i;
		//3.遍历未排序序列
		for (int j = i; j < ls->length; j++)
		{
			if (ls->r[j] < ls->r[min])
				min = j;
		}
		//4.交换元素
		if (min != i)
			swap(ls->r[min], ls->r[i]);
	}
}
void main()
{
	List ls = { {9,1,5,8,3,7,4,6,2},9 };
	select_sort(&ls);
	print_list(&ls);
}