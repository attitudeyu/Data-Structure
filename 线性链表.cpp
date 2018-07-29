/*
线性表顺序存储和链式存储的优缺点？
顺序存储：
a.不需要增加额外的存储空间，快速存取指向位置的元素；
b.在插入和删除过程中，需要移动大量元素；
c.需要预先分配存储空间；
链式存储：
a.插入删除操作时间为O(1);
b.用任意位置的存储单元存储元素；
*/
#include <iostream>
using namespace std;
typedef struct Node
{
	int data;
	Node *next;
}Node;
//头插法创建链表
void head_insert_create_list(Node *L, int n)
{
	//创建节点
	for (int i = 0; i < n; i++)
	{
		Node *new_node = new Node;
		new_node->data = i;
		new_node->next = L->next;
		L->next = new_node;
	}
}
//尾插法创建链表
void tail_insert_create_list(Node *L, int n)
{
	//初始化尾部节点为头节点
	Node *r = L;
	for (int i = 0; i < n; i++)
	{
		Node *new_node = new Node;
		new_node->data = i;
		r->next = new_node;
		//更新尾节点为新节点
		r = new_node;
	}
	//尾节点的指针域为空
	r->next = NULL;
}
//在第i个位置后插入节点
void insert_node(Node *L, int i, int num)
{
	Node *node = L->next;
	int j = 1;
	//找到第i个节点
	while (node&&j < i)
	{
		node = node->next;
		++j;
	}
	//鲁棒性设计
	if (!node || j > i)
		return;
	Node *new_node = new Node;
	new_node->data = num;
	new_node->next = node->next;
	node->next = new_node;
}
//在第i个位置删除节点
void delete_node(Node *L, int i)
{
	Node *node = L->next;
	int j = 1;
	//找到第i个节点的上一个节点
	while (node&&j < i-1)
	{
		node = node->next;
		++j;
	}
	//鲁棒性设计
	if (!node->next || j > i)
		return;
	Node *delete_node = node->next;
	node->next = delete_node->next;
	free(delete_node);
}
//遍历链表
void print_list(Node *L)
{
	//第一个节点
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
	//创建头节点
	Node *L = new Node;
	L->data = 5;//链表长度
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