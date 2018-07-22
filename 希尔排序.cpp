/*
ϣ������
˼·��
����������ֱ�Ӳ�������ÿ�α��������л�������ֱ������Ϊ1,ʹ�ý������ݵ��������.
���裺
1.��������
2.�Ƚ��������������е�Ԫ��
3.ֱ�Ӳ�������
*/
#include <iostream>

using namespace std;

const int Maxsize = 10;
typedef struct
{
	int r[Maxsize + 1];//r[0]�����ڴ洢�ڱ�����
	int length;
}List;//����Ľṹ��ֻ��һ���ṹ�����

//��ӡ����������
void print_list(List *L)
{
	cout << "���������飺";
	for (int i = 1; i < L->length; i++)
		cout << L->r[i] << " ";
	cout << endl;
}
void shell_sort(List *L)
{
	int i, j, num=0;
	int increment = L->length-1;//������鳤��
	while (increment > 1)
	{
		//1.��������
		increment = increment / 3 + 1;
		for (i = increment + 1; i <= L->length; i++)
		{
			//2.�Ƚ��������������е�Ԫ��
			if (L->r[i] < L->r[i - increment])//��ǰԪ��С����һ������Ԫ��
			{
				//3.ֱ�Ӳ�������
				L->r[0] = L->r[i];//����ǰԪ�ش����ڱ�������
				for (j = i - increment; j > 0 && L->r[j] > L->r[0]; j -= increment)//ֱ���ƶ�Ԫ��>�ڱ�Ԫ��
				{
					L->r[j + increment] = L->r[j];//��Ԫ�غ���
					num++;
				}
				L->r[j + increment] = L->r[0];
			}
		}
	}
	cout << "����Ԫ���ƶ��Ĵ�����" << num << endl;
}
void main()
{
	List list = { {0,9,5,8,10,3,7,4,6,2,1},11 };

	shell_sort(&list);
	print_list(&list);
}
