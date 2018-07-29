/*
队列是先进先出的线性表，其在队尾进行插入操作，在队首进行删除操作。                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
*/
#include <iostream>
using namespace std;
typedef struct Node //定义队列节点
{
	int data;
	Node *next;
}Node;
typedef struct Queue // 定义链队列的首尾指针，其指向的是首尾节点
{
	Node *front;
	Node *rear;
}Queue;
//创建队列
void create_queue(Queue *Q, int n)
{
	for (int i = 0; i < n; i++)
	{
		Node *new_node = new Node;
		new_node->data = i;
		new_node->next = NULL;
		Q->rear->next = new_node;//队尾插入节点
		Q->rear = new_node;
	}
}
//队尾插入节点
void insert_node(Queue *Q, int num)
{
	Node *new_node = new Node;
	new_node->data = num;
	new_node->next = NULL;
	Q->rear->next = new_node;
	Q->rear = new_node;
}
//队首删除节点
void delete_node(Queue *Q)
{
	//鲁棒性设计
	if (Q->front == Q->rear)
		return;
	Node *delete_node;
	//获得第一个节点
	delete_node = Q->front->next;
	Q->front->next = delete_node->next;
	cout << "删除节点的值：" << delete_node->data << endl;
	free(delete_node);
}
void main()
{
	//创建空队列 队首队尾指针指向头节点
	Queue *Q = new Queue;
	Node *head_node = new Node;
	head_node->next = NULL;
	head_node->data = 5;
	Q->front = head_node;
	Q->rear = head_node;
	
	create_queue(Q, 5);
	delete_node(Q);
	delete_node(Q);


	insert_node(Q, 3);
	delete_node(Q);
}