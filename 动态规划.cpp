/*
动态规划思想：
通过状态转移方程将大问题分解为小问题，找到小问题的最优解，
然后基于此小问题的最优状态获得另一问题的最优解。
具体做法是将各个小问题的最优解存入数组中，然后基于其来获取当前问题的最优解。
*/

/*
题目一：
有1,3,5三种面值的硬币，找到总值为16元的最少硬币数量？

获得d(0)、d(1)、d(2)小问题的最优解
d(0) = 0
d(1) = d(1-1)+1 = d(0)+1 = 1  
d(2) = d(2-1)+1 = d(1)+1 = 1+1 = 2
d(3) = d(3-3)+1 = d(0)+1 = 1
d(3) = d(3-1)+1 = d(2)+1 = 3
d(4) = d(4-3)+1 = d(1)+1 = 2

状态转移方程：
d(x) = min( d(x-v)+1 )
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	//面值
	int v[3] = { 1,3,5 };
	//索引为总值，元素为硬币数量
	vector<int> arr1;
	arr1.push_back(0);
	for (int i = 1; i <= 16; i++)
	{
		//所有面值对应的硬币数量
		vector<int> arr2;
		for (int j = 0; j < 3; j++)
		{
			//总值需大于等于面值
			if (i - v[j] >= 0)
			{
				arr2.push_back(arr1[i - v[j]] + 1);
			}
		}
		//获得当前总值对应的最少硬币数量
		sort(arr2.begin(), arr2.end());
		arr1.push_back(arr2[0]);
	}
	for (int i = 0; i < arr1.size(); i++)
		cout << arr1[i] << " ";
  cout<<"最终结果为："<< arr1[arr1.size()-1]<<endl;

	return 0;
}

/*
题目二：
给定长度为N的序列，获得最长的非降序列?
4,3,5,7,5,8

d(0) = 1
d(1) = 1
d(2) = d(1)+1 = 2
d(3) = d(2)+1 = 3
d(4) = 1
d(5) = d(4)+1 = 2

状态转移方程：
if arr[i]>arr[i-1]
d(i) = d(i-1)+1  
else
d(i) = 1
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int seq[6] = { 4,3,5,7,5,8 };
	vector<int > arr;
	arr.push_back(1);
	for (int i = 1; i < 6; i++)
	{
		if (seq[i] > seq[i - 1])
			arr.push_back(arr[i - 1] + 1);
		else
			arr.push_back(1);
	}
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
	sort(arr.begin(), arr.end());
	cout <<"最优结果为："<< arr[arr.size() - 1] << endl;
	return 0;
}
/*
题目三：
上台阶有两种方式，一种是一次上一阶，另一种是一次上两阶，若有N个台阶，则有多少种走法?

获得d(n-2)、d(n-1)小问题的最优解，然后再此基础上再走一步或两步台阶
d(1) = d(0) = 1
d(2) = d(2-2) + d(2-1) = 1+1 = 2
d(3) = d(3-2) + d(3-1) = 1+2 = 3
d(4) = d(4-2) + d(4-1) = 2+4 = 5

状态转移方程
d(n) = d(n-2) + d(n-1)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n = 4;
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(1);
	if (n == 1)
		cout << "走法：" << n << endl;
	for (int i = 2; i < n; i++)
		arr.push_back(arr[i - 2] + arr[i - 1]);
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "走法：" << arr[arr.size() - 1] << endl;
	return 0;
}
/*
题目四：
给定二维数组，从左上角开始到右下角仅能向右或向下移动，获得最优路径？
2,6,4,6
1,5,7,0
3,7,4,7
1,3,0,2

创建二维数组，获得每个位置在当前位置处的最优路径
d(0,0) = a(0,0) = 2
d(0,1) = a(0,1) + d(0,0) = 8
d(0,2) = a(0,2) + d(0,1) = 4+8=12   第一行仅能向右移动
...
d(1,0) = a(1,0) + d(0,0) = 1+2 = 3  第一列仅能向下移动
d(2,0) = a(2,0) + d(1,0) = 3+3 = 6
...
d(1,1) = a(1,1) + min{d(0,1), d(1,0)} = 5+3= 8  非第一行列的最优路径与其上或左的最小路径有关
d(1,2) = a(1,2) + min{d(0,2), d(1,1)} = 7+8 = 15
...

状态转移方程
d(i,j) = a(i,j) + min{d(i-1,j) + d(i,j-1)}
*/
#include <iostream>
using namespace std;
int min(int a, int b)
{
	return a < b ? a : b;
}
int main()
{
	int arr[4][4] = { 2,6,4,6,1,5,7,0,3,7,4,7,1,3,0,2 };
	int d[4][4] = {};
	//将当前位置的最优解存储在数组中
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == 0 && j == 0)
				d[i][j] = arr[i][j];
			else if (i == 0 && j != 0)
				d[i][j] = arr[i][j] + d[i][j - 1];
			else if (i != 0 && j == 0)
				d[i][j] = arr[i][j] + d[i - 1][j];
			else
				d[i][j] = arr[i][j] + min(d[i][j-1],d[i-1][j]);
		}
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	cout << "最终解：" << d[3][3] << endl;
	return 0;
}