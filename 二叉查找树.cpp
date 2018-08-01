/*
1.���������
a.���������нڵ�ֵС�ڸ��ڵ�ֵ
b.���������ҽڵ�ֵ���ڸ��ڵ�ֵ
c.���������ֱ�Ϊ���������
2.����������
�������������������ɵõ��������������У�����Ҳ��Ϊ����������
*/
#include <iostream>
#include <string>
using namespace std;
typedef struct Node
{
	int data;
	Node *lchild;
	Node *rchild;
}Node;
//����������
Node * create_binary_tree(int depth, string pos)
{
	cout << "the depth is : " << depth << "  the pos is : " << pos << endl;
	int data;
	cin >> data;
	if (data == 0)
		return NULL;
	Node * new_node = new Node;
	new_node->data = data;
	new_node->lchild = create_binary_tree(depth + 1, "lchild");
	new_node->rchild = create_binary_tree(depth + 1, "rchild");
	return new_node;
}
//����������
Node * binary_search_tree(Node *node, int key)
{
	while (node != NULL)
	{
		if (node->data == key)
			return node;
		else if (key<node->data)
			node = node->lchild;
		else
			node = node->rchild;
	}
	if (node = NULL)
	{
		return node;
	}
}
void tree_insert_node(Node *T, int key)
{
	Node *find_node = binary_search_tree(T, key);
	//û�в��ҵ�ָ��ֵ�������
	if (find_node)
	{
		Node *new_node = new Node;
		new_node->data = key;
		new_node->lchild = new_node->rchild = NULL;
		//��Ϊ�������������ڵ�
		if (T == NULL)
			T = new_node;
		else if (key < find_node->data)
			find_node->lchild = new_node;
		else
			find_node->rchild = new_node;
	}
	else
		cout << "no need to insert key!" << endl;
}
void pre_order_print(Node *node)
{
	if (node == NULL)
		return;
	cout << node->data << " ";
	pre_order_print(node->lchild);
	pre_order_print(node->rchild);
}
//�������
void mid_order_print(Node *node)
{
	if (node == NULL)
		return;
	pre_order_print(node->lchild);
	cout << node->data << " ";
	pre_order_print(node->rchild);
}
void main()
{
	Node * root = new Node;
	root = create_binary_tree(1, "root");
	cout << "ǰ����������������";
	pre_order_print(root);
	cout << endl;

	tree_insert_node(root, 47);
	cout << "ǰ����������������";
	pre_order_print(root);
	cout << endl;

	Node *find_node = binary_search_tree(root, 47);
	if (find_node)
		cout << "find it,and the data of the node is " << find_node->data << endl;
	else
		cout << "not find it" << endl;
}