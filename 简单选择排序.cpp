/*
��ѡ������
˼·��
�����з�Ϊ�����δ���������֣�ÿ�α�����δ���������л����С������±�
���裺
1.��������
2.��ʼ����С�±�
3.����δ��������
4.����Ԫ��
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
	//1.��������
	for (int i = 0; i < ls->length - 1; i++)
	{
		//2.��ʼ����С�±�
		int min = i;
		//3.����δ��������
		for (int j = i; j < ls->length; j++)
		{
			if (ls->r[j] < ls->r[min])
				min = j;
		}
		//4.����Ԫ��
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