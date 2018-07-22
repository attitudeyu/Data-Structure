/*
希尔排序：
思路：
基于增量的直接插入排序，每次遍历令序列基本有序，直至增量为1,使得交换数据的情况减少.
步骤：
1.计算增量
2.比较相邻增量序列中的元素
3.直接插入排序
*/
#include <iostream>

using namespace std;

const int Maxsize = 10;
typedef struct
{
	int r[Maxsize + 1];//r[0]是用于存储哨兵变量
	int length;
}List;//定义的结构体只有一个结构体别名

//打印排序后的数组
void print_list(List *L)
{
	cout << "排序后的数组：";
	for (int i = 1; i < L->length; i++)
		cout << L->r[i] << " ";
	cout << endl;
}
void shell_sort(List *L)
{
	int i, j, num=0;
	int increment = L->length-1;//获得数组长度
	while (increment > 1)
	{
		//1.计算增量
		increment = increment / 3 + 1;
		for (i = increment + 1; i <= L->length; i++)
		{
			//2.比较相邻增量序列中的元素
			if (L->r[i] < L->r[i - increment])//当前元素小于上一个增量元素
			{
				//3.直接插入排序
				L->r[0] = L->r[i];//将当前元素存入哨兵变量处
				for (j = i - increment; j > 0 && L->r[j] > L->r[0]; j -= increment)//直到移动元素>哨兵元素
				{
					L->r[j + increment] = L->r[j];//将元素后移
					num++;
				}
				L->r[j + increment] = L->r[0];
			}
		}
	}
	cout << "数组元素移动的次数：" << num << endl;
}
void main()
{
	List list = { {0,9,5,8,10,3,7,4,6,2,1},11 };

	shell_sort(&list);
	print_list(&list);
}
