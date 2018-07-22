/*
������
˼·��
ÿ�ν��������Ϊ�󶥶ѣ�Ȼ����ȫ�������ĸ��ڵ������һ��Ԫ�ؽ������ٵ���Ϊ�󶥶�
���裺
1.���������й����ɴ󶥶�(�����ֵ�����ӽ��ֵ)
2.���������ֵ�����һ�����ֵ
3.���½���������±�֮ǰ�����й����ɴ󶥶�
4.�ظ�2,3���裬ֱ�������
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int Maxsize = 10;
typedef struct
{
	int r[Maxsize + 1];//r[0]�����ڴ洢�ڱ�����
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
	cout << "���������飺";
	for (int i = 1; i <= L->length; i++)
		cout << L->r[i] << " ";
	cout << endl;
}
void heap_adjust(List *L, int s, int m)//�����󶥶� ��ȫ�����������и����
{
	int temp, j;
	temp = L->r[s];//���浱ǰ���ڵ�
	for (j = 2 * s; j <= m; j *= 2)//�ӵ�ǰ�������ӽ�㿪ʼ����
	{
		if (j < m && L->r[j] < L->r[j + 1])//����ӽ���нϴ�Ľ���±�
			++j;
		if (temp >= L->r[j])//����������������ӽ�����˳�ѭ��
			break;
		L->r[s] = L->r[j];//�������������㣬������ӽ�㸳ֵ�������
		s = j;		
	}
	L->r[s] = temp;//������ɽ�������ӽ��͸����
}
void heap_sort(List *L)
{
	int i;
	//1.���������й����ɴ󶥶�(�����ֵ�����ӽ��ֵ)
	for (i = L->length / 2; i > 0; i--)
		heap_adjust(L, i, L->length);

	for (i = L->length; i > 1; i--)
	{
		//2.���������ֵ�����һ�����ֵ
		swap(L, 1, i);
		//3.���½���������±�֮ǰ�����й����ɴ󶥶�
		heap_adjust(L, 1, i - 1);
	}
}
void main()
{
	List list = { {0,50,10,90,30,70,40,80,60,20}, 9 };
	heap_sort(&list);
	print_list(&list);

	//����STL��ʵ�ַ�ʽ
	int arr[] = { 50,10,90,30,70,40,80,60,20 };
	//������ѹ��vector��
	vector<int> heap(arr, arr + 9);
	//��vector�е���������Ϊ�󶥶�
	make_heap(heap.begin(), heap.end(),less<int>());
	cout << heap.front() << endl;
	//�������Ԫ��֮�������Ϊ�󶥶�
	pop_heap(heap.begin(), heap.end(), less<int>());
	cout << heap.front() << endl;
	//�����󶥶����Ԫ��
	heap.pop_back();
	cout << heap.front() << endl;
	//�Ը�ѹ������ݣ�����Ϊ�󶥶�
	heap.push_back(50);
	push_heap(heap.begin(), heap.end(), less<int>());
	cout << heap.front() << endl;
}