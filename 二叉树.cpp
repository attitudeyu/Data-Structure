/*
1. 二叉树顺序存储和链式存储的对比
二叉树的顺序存储是节点的下标对应数组的索引下标来存储的。对于深度树来说，若其节点数不多时，
由于需要以完全二叉树的规模进行存储，此时会造成内存空间的浪费。
二叉树的链式存储是为每个节点设置数据域和两个指针域，若节点的左右子树不存在时，此时指针域
为空，即没有内存的分配，其具有线性表链式存储的特点。
2. 二叉树的创建
递归以前序遍历的方式创建节点，指定左右子节点为空时的输入值。
3. 二叉树的遍历
递归打印节点的值，打印的位置不同，遍历的方式也就不同。
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
//前序遍历二叉树
void pre_order_print(Node *root)
{
	if (root == NULL)
		return;
	cout << "the data is : " << root->data << " ";
	pre_order_print(root->lchild);
	pre_order_print(root->rchild);
}
//中序遍历二叉树
void mid_order_print(Node *root)
{
	if (root == NULL)
		return;
	mid_order_print(root->lchild);
	cout << "the data is : " << root->data << " ";
	mid_order_print(root->rchild);
}
//后序遍历二叉树
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