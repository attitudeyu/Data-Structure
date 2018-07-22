/*
快速排序：
思路：
每次遍历序列时，寻找当前序列的枢轴值下标，并同时将序列排序为左右子表的序列，即左子表小于枢轴值，右子表大于枢轴值
步骤：
1.获得当前序列的枢轴变量(第一个元素)
2.轮询直至首尾指针相同，返回此下标
3.若尾指针指向值大于枢轴值，则向前移动；否则，交换首尾指针对应值
4.若首指针指向值小于枢轴值，则向后移动；否则，交换首尾指针对应值
5.左子表递归排序，直到low>=(pivot-1)
6.右子表递归排序，直到(pivot+1)>=high
*/
#include <iostream>
using namespace std;
const int Maxsize = 10;
typedef struct
{
	int r[Maxsize];
	int length;
}List;//定义的结构体只有一个结构体别名
void swap(List *L, int i, int j)
{
	int temp = L->r[j];
	L->r[j] = L->r[i];
	L->r[i] = temp;
}
void print_list(List *L)
{
	cout << "排序后的数组：";
	for (int i = 0; i < L->length; i++)
		cout << L->r[i] << " ";
	cout << endl;
}
int get_pivot(List *L, int low, int high)
{
	int pivot_val = L->r[low];//初始化序列第一个元素为枢轴变量
	while (low < high)//轮询直至low==high
	{
		while (low<high&&L->r[high]>pivot_val)//r[high]大于枢轴值则向左移动
			high--;
		swap(L, low, high);//r[high]小于枢轴值则交换到前面
		while (low < high&&L->r[low] <= pivot_val)//r[low]小于等于枢轴值则向右移动
			low++;
		swap(L, low, high);//r[low]大于等于枢轴值则交换到后面
	}
	return low;
}
void quick_sort_core(List *L, int low, int high)
{
	int pivot;
	if (low < high)//用于判断是否进行递归
	{
		//1.获得当前序列的枢轴变量下标，在此过程同时进行排序
		pivot = get_pivot(L, low, high);
		
		//2.左子表递归排序，直到low >= (pivot - 1)
		quick_sort_core(L, low, pivot - 1); 
		
		//3.右子表递归排序，直到(pivot+1)>=high
		quick_sort_core(L, pivot + 1, high);
	}
}
void quick_sort(List *L)
{
	quick_sort_core(L, 0, L->length-1);
}
void main()
{
	List list = { {50,10,90,30,70,40,80,60,20},9 };
	quick_sort(&list);
	print_list(&list);
}
