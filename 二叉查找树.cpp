/*
1.二叉查找树
a.左子树所有节点值小于根节点值
b.右子树左右节点值大于根节点值
c.左右子树分别为二叉查找树
2.二叉排序树
二叉查找树中序遍历即可得到递增的有序序列，所有也称为二叉排序树
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
//创建二叉树
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
//二叉树查找
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
	//没有查找到指定值，则插入
	if (find_node)
	{
		Node *new_node = new Node;
		new_node->data = key;
		new_node->lchild = new_node->rchild = NULL;
		//若为空树，则插入根节点
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
//中序遍历
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
	cout << "前序遍历二叉树结果：";
	pre_order_print(root);
	cout << endl;

	tree_insert_node(root, 47);
	cout << "前序遍历二叉树结果：";
	pre_order_print(root);
	cout << endl;

	Node *find_node = binary_search_tree(root, 47);
	if (find_node)
		cout << "find it,and the data of the node is " << find_node->data << endl;
	else
		cout << "not find it" << endl;
}