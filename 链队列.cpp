/*
�������Ƚ��ȳ������Ա����ڶ�β���в���������ڶ��׽���ɾ��������                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
*/
#include <iostream>
using namespace std;
typedef struct Node //������нڵ�
{
	int data;
	Node *next;
}Node;
typedef struct Queue // ���������е���βָ�룬��ָ�������β�ڵ�
{
	Node *front;
	Node *rear;
}Queue;
//��������
void create_queue(Queue *Q, int n)
{
	for (int i = 0; i < n; i++)
	{
		Node *new_node = new Node;
		new_node->data = i;
		new_node->next = NULL;
		Q->rear->next = new_node;//��β����ڵ�
		Q->rear = new_node;
	}
}
//��β����ڵ�
void insert_node(Queue *Q, int num)
{
	Node *new_node = new Node;
	new_node->data = num;
	new_node->next = NULL;
	Q->rear->next = new_node;
	Q->rear = new_node;
}
//����ɾ���ڵ�
void delete_node(Queue *Q)
{
	//³�������
	if (Q->front == Q->rear)
		return;
	Node *delete_node;
	//��õ�һ���ڵ�
	delete_node = Q->front->next;
	Q->front->next = delete_node->next;
	cout << "ɾ���ڵ��ֵ��" << delete_node->data << endl;
	free(delete_node);
}
void main()
{
	//�����ն��� ���׶�βָ��ָ��ͷ�ڵ�
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