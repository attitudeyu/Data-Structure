/*
冒泡排序算法:
思路：
两个for循环，两两比较元素进行交换。
步骤：
1.从前向后遍历
2.从后向前遍历
3.初始化当前序列已有序的标志位
4.两两比较
*/
#include <iostream>

using namespace std;

const int Maxsize = 10;
typedef struct
{
	int r[Maxsize + 1];//r[0]是用于存储哨兵变量
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
void bubble_sort(List *L)
{
	int num1 = 0, num2 = 0;
	bool flag = true;
	//1.从前向后遍历
	for (int i = 0; i < L->length && flag; i++)//若flag为false则停止外循环
	{
		//3.初始化当前序列已有序的标志位
		flag = false;
		//2.从后向前遍历
		int temp = L->length - 2;
		for (int j = temp; j >= i; j--)
		{
			num1++;
			//4.两两比较
			if (L->r[j] > L->r[j + 1])
			{
				swap(L, j, j + 1);
				flag = true;
				num2++;
			}
		}
	}
	cout << "遍历的次数：" << num1 << endl;
	cout << "交换数组元素的次数：" << num2 << endl;
}
void main()
{
	List list = { { 2,1,3,5,6,7,8,9,10,11 },10 };
	bubble_sort(&list);
	print_list(&list);
}