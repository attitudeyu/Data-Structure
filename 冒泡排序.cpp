/*
ð�������㷨:
˼·��
����forѭ���������Ƚ�Ԫ�ؽ��н�����
���裺
1.��ǰ������
2.�Ӻ���ǰ����
3.��ʼ����ǰ����������ı�־λ
4.�����Ƚ�
*/
#include <iostream>

using namespace std;

const int Maxsize = 10;
typedef struct
{
	int r[Maxsize + 1];//r[0]�����ڴ洢�ڱ�����
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
void bubble_sort(List *L)
{
	int num1 = 0, num2 = 0;
	bool flag = true;
	//1.��ǰ������
	for (int i = 0; i < L->length && flag; i++)//��flagΪfalse��ֹͣ��ѭ��
	{
		//3.��ʼ����ǰ����������ı�־λ
		flag = false;
		//2.�Ӻ���ǰ����
		int temp = L->length - 2;
		for (int j = temp; j >= i; j--)
		{
			num1++;
			//4.�����Ƚ�
			if (L->r[j] > L->r[j + 1])
			{
				swap(L, j, j + 1);
				flag = true;
				num2++;
			}
		}
	}
	cout << "�����Ĵ�����" << num1 << endl;
	cout << "��������Ԫ�صĴ�����" << num2 << endl;
}
void main()
{
	List list = { { 2,1,3,5,6,7,8,9,10,11 },10 };
	bubble_sort(&list);
	print_list(&list);
}