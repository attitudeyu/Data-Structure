/*
堆排序：
思路：
每次将数组调整为大顶堆，然后将完全二叉树的根节点与最后一个元素交换，再调整为大顶堆
步骤：
1.将无序序列构建成大顶堆(父结点值大于子结点值)
2.交换根结点值和最后一个结点值
3.重新将交换结点下标之前的序列构建成大顶堆
4.重复2,3步骤，直到根结点
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int Maxsize = 10;
typedef struct
{
	int r[Maxsize + 1];//r[0]是用于存储哨兵变量
	int length;
}List;
void swap(List *L, int i, int j)
{
	int temp = L->r[i];
	L->r[i] = L->r[j];
	L->r[j] = temp;
}
void print_list(List *L)
{
	cout << "排序后的数组：";
	for (int i = 1; i <= L->length; i++)
		cout << L->r[i] << " ";
	cout << endl;
}
void heap_adjust(List *L, int s, int m)//构建大顶堆 完全二叉树的所有父结点
{
	int temp, j;
	temp = L->r[s];//缓存当前父节点
	for (j = 2 * s; j <= m; j *= 2)//从当前父结点的子结点开始遍历
	{
		if (j < m && L->r[j] < L->r[j + 1])//获得子结点中较大的结点下标
			++j;
		if (temp >= L->r[j])//如果父结点大于最大的子结点则退出循环
			break;
		L->r[s] = L->r[j];//以上条件不满足，则将最大子结点赋值给父结点
		s = j;		
	}
	L->r[s] = temp;//最终完成交换最大子结点和父结点
}
void heap_sort(List *L)
{
	int i;
	//1.将无序序列构建成大顶堆(父结点值大于子结点值)
	for (i = L->length / 2; i > 0; i--)
		heap_adjust(L, i, L->length);

	for (i = L->length; i > 1; i--)
	{
		//2.交换根结点值和最后一个结点值
		swap(L, 1, i);
		//3.重新将交换结点下标之前的序列构建成大顶堆
		heap_adjust(L, 1, i - 1);
	}
}
void main()
{
	List list = { {0,50,10,90,30,70,40,80,60,20}, 9 };
	heap_sort(&list);
	print_list(&list);

	//基于STL的实现方式
	int arr[] = { 50,10,90,30,70,40,80,60,20 };
	//将数组压入vector中
	vector<int> heap(arr, arr + 9);
	//将vector中的数据排序为大顶堆
	make_heap(heap.begin(), heap.end(),less<int>());
	cout << heap.front() << endl;
	//除过最大元素之外的排序为大顶堆
	pop_heap(heap.begin(), heap.end(), less<int>());
	cout << heap.front() << endl;
	//弹出大顶堆最大元素
	heap.pop_back();
	cout << heap.front() << endl;
	//对刚压入的数据，排序为大顶堆
	heap.push_back(50);
	push_heap(heap.begin(), heap.end(), less<int>());
	cout << heap.front() << endl;
}