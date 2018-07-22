/*
直接插入排序:
思路：
将序列分为有序和无序两部分，通过比较有序和无序的相邻两个元素将元素插入有序序列中。
步骤：
1.外部for循环从下标i=2开始遍历,即遍历无序部分
2.增加判断条件(当前元素<上一个元素，则进行插入操作)
3.在数组下标i=0处存储哨兵变量，也就是当前元素
4.内部for循环从有序部分下标从后向前遍历，将元素后移，直到大于哨兵变量
5.将哨兵变量放到需要插入的位置
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
void print_list(List *ls)
{
	cout << "排序后的数组：";
	for (int i = 1; i < ls->length; i++)
		cout << ls->r[i] << " ";
	cout << endl;
}

void insert_sort(List *ls)
{
	int num=0,i,j;
	//1.外部for循环从下标i=2开始遍历,即遍历无序部分
	for (i = 2; i <= ls->length; i++)
	{
		//2.增加判断条件(当前元素<上一个元素，则进行插入操作)
		if (ls->r[i] < ls->r[i - 1])
		{
			//3.在数组下标i=0处存储哨兵变量，也就是当前元素
			ls->r[0] = ls->r[i];
			//4.内部for循环从有序部分下标从后向前遍历，将元素后移，直到大于哨兵变量
			for (j = i - 1; ls->r[j] > ls->r[0]; j--)
			{
				ls->r[j + 1] = ls->r[j];
				num++;
			}
			//5.将哨兵变量放到需要插入的位置
			ls->r[j + 1] = ls->r[0];
		}
	}
	cout << "元素后移的次数：" << num << endl;
}
void main()
{
	List list = { {0,9,10,5,8,3,7,4,6,2,1},11 };

	insert_sort(&list);
	print_list(&list);
}