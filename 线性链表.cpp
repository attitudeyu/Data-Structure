/*
���Ա�˳��洢����ʽ�洢����ȱ�㣿
˳��洢��
a.����Ҫ���Ӷ���Ĵ洢�ռ䣬���ٴ�ȡָ��λ�õ�Ԫ�أ�
b.�ڲ����ɾ�������У���Ҫ�ƶ�����Ԫ�أ�
c.��ҪԤ�ȷ���洢�ռ䣻
��ʽ�洢��
a.����ɾ������ʱ��ΪO(1);
b.������λ�õĴ洢��Ԫ�洢Ԫ�أ�
*/
#include <iostream>
using namespace std;
typedef struct Node
{
	int data;
	Node *next;
}Node;
//ͷ�巨��������
void head_insert_create_list(Node *L, int n)
{
	//�����ڵ�
	for (int i = 0; i < n; i++)
	{
		Node *new_node = new Node;
		new_node->data = i;
		new_node->next = L->next;
		L->next = new_node;
	}
}
//β�巨��������
void tail_insert_create_list(Node *L, int n)
{
	//��ʼ��β���ڵ�Ϊͷ�ڵ�
	Node *r = L;
	for (int i = 0; i < n; i++)
	{
		Node *new_node = new Node;
		new_node->data = i;
		r->next = new_node;
		//����β�ڵ�Ϊ�½ڵ�
		r = new_node;
	}
	//β�ڵ��ָ����Ϊ��
	r->next = NULL;
}
//�ڵ�i��λ�ú����ڵ�
void insert_node(Node *L, int i, int num)
{
	Node *node = L->next;
	int j = 1;
	//�ҵ���i���ڵ�
	while (node&&j < i)
	{
		node = node->next;
		++j;
	}
	//³�������
	if (!node || j > i)
		return;
	Node *new_node = new Node;
	new_node->data = num;
	new_node->next = node->next;
	node->next = new_node;
}
//�ڵ�i��λ��ɾ���ڵ�
void delete_node(Node *L, int i)
{
	Node *node = L->next;
	int j = 1;
	//�ҵ���i���ڵ����һ���ڵ�
	while (node&&j < i-1)
	{
		node = node->next;
		++j;
	}
	//³�������
	if (!node->next || j > i)
		return;
	Node *delete_node = node->next;
	node->next = delete_node->next;
	free(delete_node);
}
//��������
void print_list(Node *L)
{
	//��һ���ڵ�
	Node *node = L->next;
	while (node)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}
void main()
{
	//����ͷ�ڵ�
	Node *L = new Node;
	L->data = 5;//������
	L->next = NULL;

	//head_insert_create_list(L, L->data);
	//print_list(L);

	tail_insert_create_list(L, L->data);
	print_list(L);

	insert_node(L, 2, 6);
	print_list(L);

	delete_node(L, 3);
	print_list(L);
}