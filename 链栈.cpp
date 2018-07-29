/*
栈是后进先出的线性表，其仅可以在表尾进行删除和插入操作。
*/
#include <iostream>
using namespace std;
typedef struct Node // 定义链栈节点
{
	int data;
	Node *next;
}Node;
typedef struct Stack 
{
	Node *top;  // 定义链栈栈顶节点
	int count;
}Stack;
//创建链栈
void create_stack(Stack *S, int n)
{
	Node *node = S->top;
	for (int i = 0; i < n; i++)
	{
		Node *new_node = new Node;
		new_node->data = i;
		new_node->next = S->top;
		S->top = new_node;
	}
}
//插入栈节点
void insert_node(Stack *S, int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = S->top;
	S->top = new_node;
	S->count++;
}
//删除栈节点
void pop_node(Stack *S)
{
	//鲁棒设计
	if (S->top == NULL)
		return;
	Node *top_node;
	top_node = S->top;
	S->top = top_node->next;
	cout << "删除节点值是： " << top_node->data << endl;
	free(top_node);
}
//打印栈节点
void print_stack(Stack *S)
{
	Node *node = S->top;
	cout << "打印栈节点：";
	while (node)
	{
		cout << node->data << " ";
		node = node->next;
	}
}
void main()
{
	//创建空栈
	Stack *S = new Stack;
	S->top = NULL;
	S->count = 0;

	create_stack(S, 5);
	print_stack(S);

	insert_node(S, 5);
	print_stack(S);

	pop_node(S);
}
