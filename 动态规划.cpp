/*
��̬�滮˼�룺
ͨ��״̬ת�Ʒ��̽�������ֽ�ΪС���⣬�ҵ�С��������Ž⣬
Ȼ����ڴ�С���������״̬�����һ��������Ž⡣
���������ǽ�����С��������Ž���������У�Ȼ�����������ȡ��ǰ��������Ž⡣
*/

/*
��Ŀһ��
��1,3,5������ֵ��Ӳ�ң��ҵ���ֵΪ16Ԫ������Ӳ��������

���d(0)��d(1)��d(2)С��������Ž�
d(0) = 0
d(1) = d(1-1)+1 = d(0)+1 = 1  
d(2) = d(2-1)+1 = d(1)+1 = 1+1 = 2
d(3) = d(3-3)+1 = d(0)+1 = 1
d(3) = d(3-1)+1 = d(2)+1 = 3
d(4) = d(4-3)+1 = d(1)+1 = 2

״̬ת�Ʒ��̣�
d(x) = min( d(x-v)+1 )
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	//��ֵ
	int v[3] = { 1,3,5 };
	//����Ϊ��ֵ��Ԫ��ΪӲ������
	vector<int> arr1;
	arr1.push_back(0);
	for (int i = 1; i <= 16; i++)
	{
		//������ֵ��Ӧ��Ӳ������
		vector<int> arr2;
		for (int j = 0; j < 3; j++)
		{
			//��ֵ����ڵ�����ֵ
			if (i - v[j] >= 0)
			{
				arr2.push_back(arr1[i - v[j]] + 1);
			}
		}
		//��õ�ǰ��ֵ��Ӧ������Ӳ������
		sort(arr2.begin(), arr2.end());
		arr1.push_back(arr2[0]);
	}
	for (int i = 0; i < arr1.size(); i++)
		cout << arr1[i] << " ";
  cout<<"���ս��Ϊ��"<< arr1[arr1.size()-1]<<endl;

	return 0;
}

/*
��Ŀ����
��������ΪN�����У������ķǽ�����?
4,3,5,7,5,8

d(0) = 1
d(1) = 1
d(2) = d(1)+1 = 2
d(3) = d(2)+1 = 3
d(4) = 1
d(5) = d(4)+1 = 2

״̬ת�Ʒ��̣�
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
	cout <<"���Ž��Ϊ��"<< arr[arr.size() - 1] << endl;
	return 0;
}
/*
��Ŀ����
��̨�������ַ�ʽ��һ����һ����һ�ף���һ����һ�������ף�����N��̨�ף����ж������߷�?

���d(n-2)��d(n-1)С��������Ž⣬Ȼ���ٴ˻���������һ��������̨��
d(1) = d(0) = 1
d(2) = d(2-2) + d(2-1) = 1+1 = 2
d(3) = d(3-2) + d(3-1) = 1+2 = 3
d(4) = d(4-2) + d(4-1) = 2+4 = 5

״̬ת�Ʒ���
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
		cout << "�߷���" << n << endl;
	for (int i = 2; i < n; i++)
		arr.push_back(arr[i - 2] + arr[i - 1]);
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "�߷���" << arr[arr.size() - 1] << endl;
	return 0;
}
/*
��Ŀ�ģ�
������ά���飬�����Ͻǿ�ʼ�����½ǽ������һ������ƶ����������·����
2,6,4,6
1,5,7,0
3,7,4,7
1,3,0,2

������ά���飬���ÿ��λ���ڵ�ǰλ�ô�������·��
d(0,0) = a(0,0) = 2
d(0,1) = a(0,1) + d(0,0) = 8
d(0,2) = a(0,2) + d(0,1) = 4+8=12   ��һ�н��������ƶ�
...
d(1,0) = a(1,0) + d(0,0) = 1+2 = 3  ��һ�н��������ƶ�
d(2,0) = a(2,0) + d(1,0) = 3+3 = 6
...
d(1,1) = a(1,1) + min{d(0,1), d(1,0)} = 5+3= 8  �ǵ�һ���е�����·�������ϻ������С·���й�
d(1,2) = a(1,2) + min{d(0,2), d(1,1)} = 7+8 = 15
...

״̬ת�Ʒ���
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
	//����ǰλ�õ����Ž�洢��������
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
	cout << "���ս⣺" << d[3][3] << endl;
	return 0;
}