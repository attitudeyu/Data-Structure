/*
1. ͼ���ڽӾ���洢���ڽӱ�洢
�����Ա�����һ������ʽ�洢��˳��洢����Լ�ڴ档
2. �ڽӱ�洢
ͼ�Ķ���������洢(�������ָ����)���ڽӵ�������洢(������Ȩ����ָ����)
3. ������ȱ���
����������ǰ���������ָ�����㿪ʼ������߱��㿪ʼ�����ݹ飬�������ѷ��ʶ���ı�־λ��ֱ�����ж��㶼�����ʵ���
4. ������ȱ���
���������Ĳ������(�����ڽӱ��ÿ��)����ָ��������㿪ʼ������ÿ���������ָ��ı߱��㣬
�����ʹ��Ķ����������У���δ�����ʹ��Ķ���ѹ�����
*/
#include <iostream>
#include <queue>
using namespace std;
const int Maxsize = 10;
bool visited[Maxsize];
typedef struct EdgeNode//�߱���
{
	int data;
	int weight;
	EdgeNode *next;
}EdgeNode;
typedef struct VertexNode//�������
{
	int data;
	EdgeNode *next;
}VertexNode,VertexList[Maxsize];
typedef struct Graph//����ͼ
{
	VertexList vertex_list;
	int vertex_num;//��������
	int edge_num;//������
}Graph;
//��ӡ�߱�����Ϣ
void print_edge_node(EdgeNode *node)
{
	cout << "the data of edge node: ";
	while (node)
	{
		cout << node->data << " ";
		node = node->next;
	}
	cout << endl;
}
//��������ͼ���ڽӱ�
void create_graph(Graph *G)
{	
	cout << "the number of vertex node and edge : ";
	cin >> G->vertex_num >> G->edge_num;
	cout << G->vertex_num << " " << G->edge_num << endl;
	//���������
	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex_list[i].data = i;
		G->vertex_list[i].next = NULL;
	}
	//�����߱� ��������ͼ��5�����㣬����ȫ����ͼ��10����
	for (int j = 0; j < G->edge_num; j++)
	{
		int a, b;
		cout << "from the vertex a to vertex b: ";
		cin >> a >> b;
		EdgeNode * e_node = new EdgeNode;
		e_node->data = b;//�ڽӶ�����b
		e_node->next = G->vertex_list[a].next;//ͷ�巨
		G->vertex_list[a].next = e_node;

		EdgeNode * e_node_ = new EdgeNode;
		e_node_->data = a;//�ڽӶ�����a
		e_node_->next = G->vertex_list[b].next;//ͷ�巨
		G->vertex_list[b].next = e_node_;
	}
}
//������ȱ���  ָ��������ʼ��
void depth_first_search_core(Graph *G, int i)
{
	visited[i] = true;
	cout << G->vertex_list[i].data << " ";
	EdgeNode *node;
	node = G->vertex_list[i].next;
	while (node)
	{
		//����߱���δ�����ʹ�����ݹ�˶����Ӧ�߱���
		if (!visited[node->data])
			depth_first_search_core(G, node->data);
		//�ݹ鷵�غ󣬼��������߱���
		node = node->next;
	}
}
void depth_first_search(Graph *G)
{
	//��ʼ�����ʱ�־λ
	for (int i = 0; i < G->vertex_num; i++)
		visited[i] = false;
	cout << "the result of depth first search is ";
	depth_first_search_core(G, 0);
	cout << endl;
}
//������ȱ���
void bread_first_search_core(Graph *G, int i)
{
	queue<int> Q;
	EdgeNode *e_node;

	if (!visited[i])
	{
		visited[i] = true;
		cout << G->vertex_list[i].data << " ";
		//��ʼ���������
		Q.push(i);
		while (!Q.empty())
		{
			//���±߱���
			i = Q.front();
			//������������
			Q.pop();
			e_node = G->vertex_list[i].next;
			while (e_node)
			{
				if (!visited[e_node->data])
				{
					visited[e_node->data] = true;
					cout << G->vertex_list[e_node->data].data << " ";
					//�߱��������
					Q.push(e_node->data);
				}
				e_node = e_node->next;
			}
		}
	}
}
void bread_first_search(Graph *G)
{
	//��ʼ�����ʱ�־λ
	for (int i = 0; i < G->vertex_num; i++)
		visited[i] = false;
	cout << "the result of bread first search is ";
	bread_first_search_core(G, 0);
	cout << endl;
}
void main()
{
	Graph graph = { NULL, 0, 0 };
	Graph *G = &graph;
	create_graph(G);
	for (int i = 0; i < G->vertex_num; i++)
	{
		EdgeNode *node = G->vertex_list[i].next;
		print_edge_node(node);
	}
	depth_first_search(G);
	bread_first_search(G);
}