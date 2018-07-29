/*
1. 图的邻接矩阵存储和邻接表存储
和线性表问题一样，链式存储比顺序存储更节约内存。
2. 邻接表存储
图的顶点用数组存储(顶点域和指针域)，邻接点用链表存储(顶点域、权重域、指针域)
3. 深度优先遍历
类似于树的前序遍历，从指定顶点开始，从其边表顶点开始遍历递归，并设置已访问顶点的标志位，直至所有顶点都被访问到。
4. 广度优先遍历
类似于树的层序遍历(遍历邻接表的每行)，从指定顶点表顶点开始，遍历每个顶点表顶点指向的边表顶点，
将访问过的顶点表顶点出队列，将未被访问过的顶点压入队列
*/
#include <iostream>
#include <queue>
using namespace std;
const int Maxsize = 10;
bool visited[Maxsize];
typedef struct EdgeNode//边表顶点
{
	int data;
	int weight;
	EdgeNode *next;
}EdgeNode;
typedef struct VertexNode//顶点表顶点
{
	int data;
	EdgeNode *next;
}VertexNode,VertexList[Maxsize];
typedef struct Graph//无向图
{
	VertexList vertex_list;
	int vertex_num;//顶点数量
	int edge_num;//边数量
}Graph;
//打印边表顶点信息
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
//创建无向图的邻接表
void create_graph(Graph *G)
{	
	cout << "the number of vertex node and edge : ";
	cin >> G->vertex_num >> G->edge_num;
	cout << G->vertex_num << " " << G->edge_num << endl;
	//创建顶点表
	for (int i = 0; i < G->vertex_num; i++)
	{
		G->vertex_list[i].data = i;
		G->vertex_list[i].next = NULL;
	}
	//创建边表 假设无向图有5个顶点，则完全无向图有10条边
	for (int j = 0; j < G->edge_num; j++)
	{
		int a, b;
		cout << "from the vertex a to vertex b: ";
		cin >> a >> b;
		EdgeNode * e_node = new EdgeNode;
		e_node->data = b;//邻接顶点是b
		e_node->next = G->vertex_list[a].next;//头插法
		G->vertex_list[a].next = e_node;

		EdgeNode * e_node_ = new EdgeNode;
		e_node_->data = a;//邻接顶点是a
		e_node_->next = G->vertex_list[b].next;//头插法
		G->vertex_list[b].next = e_node_;
	}
}
//深度优先遍历  指定遍历起始点
void depth_first_search_core(Graph *G, int i)
{
	visited[i] = true;
	cout << G->vertex_list[i].data << " ";
	EdgeNode *node;
	node = G->vertex_list[i].next;
	while (node)
	{
		//如果边表顶点未被访问过，则递归此顶点对应边表顶点
		if (!visited[node->data])
			depth_first_search_core(G, node->data);
		//递归返回后，继续遍历边表顶点
		node = node->next;
	}
}
void depth_first_search(Graph *G)
{
	//初始化访问标志位
	for (int i = 0; i < G->vertex_num; i++)
		visited[i] = false;
	cout << "the result of depth first search is ";
	depth_first_search_core(G, 0);
	cout << endl;
}
//广度优先遍历
void bread_first_search_core(Graph *G, int i)
{
	queue<int> Q;
	EdgeNode *e_node;

	if (!visited[i])
	{
		visited[i] = true;
		cout << G->vertex_list[i].data << " ";
		//起始顶点入队列
		Q.push(i);
		while (!Q.empty())
		{
			//更新边表顶点
			i = Q.front();
			//顶点表顶点出队列
			Q.pop();
			e_node = G->vertex_list[i].next;
			while (e_node)
			{
				if (!visited[e_node->data])
				{
					visited[e_node->data] = true;
					cout << G->vertex_list[e_node->data].data << " ";
					//边表顶点入队列
					Q.push(e_node->data);
				}
				e_node = e_node->next;
			}
		}
	}
}
void bread_first_search(Graph *G)
{
	//初始化访问标志位
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