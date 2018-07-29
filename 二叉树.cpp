/*
1. ������˳��洢����ʽ�洢�ĶԱ�
��������˳��洢�ǽڵ���±��Ӧ����������±����洢�ġ������������˵������ڵ�������ʱ��
������Ҫ����ȫ�������Ĺ�ģ���д洢����ʱ������ڴ�ռ���˷ѡ�
����������ʽ�洢��Ϊÿ���ڵ����������������ָ�������ڵ����������������ʱ����ʱָ����
Ϊ�գ���û���ڴ�ķ��䣬��������Ա���ʽ�洢���ص㡣
2. �������Ĵ���
�ݹ���ǰ������ķ�ʽ�����ڵ㣬ָ�������ӽڵ�Ϊ��ʱ������ֵ��
3. �������ı���
�ݹ��ӡ�ڵ��ֵ����ӡ��λ�ò�ͬ�������ķ�ʽҲ�Ͳ�ͬ��
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
//ǰ�����������
void pre_order_print(Node *root)
{
	if (root == NULL)
		return;
	cout << "the data is : " << root->data << " ";
	pre_order_print(root->lchild);
	pre_order_print(root->rchild);
}
//�������������
void mid_order_print(Node *root)
{
	if (root == NULL)
		return;
	mid_order_print(root->lchild);
	cout << "the data is : " << root->data << " ";
	mid_order_print(root->rchild);
}
//�������������
void last_order_print(Node *root)
{
	if (root == NULL)
		return;
	last_order_print(root->lchild);
	last_order_print(root->rchild);
	cout << "the data is : " << root->data << " ";
}
void main()
{
	Node * root = new Node;
	root = create_binary_tree(1, "root");
	pre_order_print(root);
	cout << endl;
}