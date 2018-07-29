/*
ջ�Ǻ���ȳ������Ա���������ڱ�β����ɾ���Ͳ��������
*/
#include <iostream>
using namespace std;
typedef struct Node // ������ջ�ڵ�
{
	int data;
	Node *next;
}Node;
typedef struct Stack 
{
	Node *top;  // ������ջջ���ڵ�
	int count;
}Stack;
//������ջ
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
//����ջ�ڵ�
void insert_node(Stack *S, int data)
{
	Node *new_node = new Node;
	new_node->data = data;
	new_node->next = S->top;
	S->top = new_node;
	S->count++;
}
//ɾ��ջ�ڵ�
void pop_node(Stack *S)
{
	//³�����
	if (S->top == NULL)
		return;
	Node *top_node;
	top_node = S->top;
	S->top = top_node->next;
	cout << "ɾ���ڵ�ֵ�ǣ� " << top_node->data << endl;
	free(top_node);
}
//��ӡջ�ڵ�
void print_stack(Stack *S)
{
	Node *node = S->top;
	cout << "��ӡջ�ڵ㣺";
	while (node)
	{
		cout << node->data << " ";
		node = node->next;
	}
}
void main()
{
	//������ջ
	Stack *S = new Stack;
	S->top = NULL;
	S->count = 0;

	create_stack(S, 5);
	print_stack(S);

	insert_node(S, 5);
	print_stack(S);

	pop_node(S);
}
