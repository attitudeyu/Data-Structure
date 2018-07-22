/*
��������
˼·��
ÿ�α�������ʱ��Ѱ�ҵ�ǰ���е�����ֵ�±꣬��ͬʱ����������Ϊ�����ӱ�����У������ӱ�С������ֵ�����ӱ��������ֵ
���裺
1.��õ�ǰ���е��������(��һ��Ԫ��)
2.��ѯֱ����βָ����ͬ�����ش��±�
3.��βָ��ָ��ֵ��������ֵ������ǰ�ƶ������򣬽�����βָ���Ӧֵ
4.����ָ��ָ��ֵС������ֵ��������ƶ������򣬽�����βָ���Ӧֵ
5.���ӱ�ݹ�����ֱ��low>=(pivot-1)
6.���ӱ�ݹ�����ֱ��(pivot+1)>=high
*/
#include <iostream>
using namespace std;
const int Maxsize = 10;
typedef struct
{
	int r[Maxsize];
	int length;
}List;//����Ľṹ��ֻ��һ���ṹ�����
void swap(List *L, int i, int j)
{
	int temp = L->r[j];
	L->r[j] = L->r[i];
	L->r[i] = temp;
}
void print_list(List *L)
{
	cout << "���������飺";
	for (int i = 0; i < L->length; i++)
		cout << L->r[i] << " ";
	cout << endl;
}
int get_pivot(List *L, int low, int high)
{
	int pivot_val = L->r[low];//��ʼ�����е�һ��Ԫ��Ϊ�������
	while (low < high)//��ѯֱ��low==high
	{
		while (low<high&&L->r[high]>pivot_val)//r[high]��������ֵ�������ƶ�
			high--;
		swap(L, low, high);//r[high]С������ֵ�򽻻���ǰ��
		while (low < high&&L->r[low] <= pivot_val)//r[low]С�ڵ�������ֵ�������ƶ�
			low++;
		swap(L, low, high);//r[low]���ڵ�������ֵ�򽻻�������
	}
	return low;
}
void quick_sort_core(List *L, int low, int high)
{
	int pivot;
	if (low < high)//�����ж��Ƿ���еݹ�
	{
		//1.��õ�ǰ���е���������±꣬�ڴ˹���ͬʱ��������
		pivot = get_pivot(L, low, high);
		
		//2.���ӱ�ݹ�����ֱ��low >= (pivot - 1)
		quick_sort_core(L, low, pivot - 1); 
		
		//3.���ӱ�ݹ�����ֱ��(pivot+1)>=high
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
