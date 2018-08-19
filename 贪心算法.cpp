/*
̰���㷨
�ƶ�̰�Ĳ��ԣ�ÿ�ν����Ǿֲ����Ž�(̰�Ĳ�����)�������Ǵ�ȫ�������������Ž⣬�������յĽ����
ͨ���ֲ����Ž����ȫ�����Ž⡣

���Թؼ�������̰�Ĳ������ѡ��

���붯̬�滮������֮���Ƕ��������С��������Ž⣬��������Ƕ�̬�滮��Ҫ����֮ǰ����С��������Ž⣬
�Դ���������һ��������Ž⣬��̰���㷨����Ҫ����֮ǰ����С��������Ž⡣
*/
/*
��Ŀһ
�������⣬��������������150�����߸���Ʒ����ÿ����Ʒ���������ֵ������ѡ����Դ��뱳���е�����ֵ��
��������
��Ʒ�� A  B  C  D  E  F  G
������ 35 30 60 50 40 10 25
��ֵ�� 10 40 30 50 35 40 30

̰�Ĳ��ԣ���λ�����ļ�ֵ�����Ƚ��뱳��
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
void print_map(map<int, float> m)
{
	map<int, float>::iterator ite = m.begin();
	for (ite; ite != m.end(); ite++)
	{
		cout << ite->first << " " << ite->second << endl;
	}
}
void print_vecotr(vector<int> v)
{
	vector<int>::iterator ite = v.begin();
	for (ite; ite != v.end(); ite++)
	{
		cout << *ite << " ";
	}
}
int get_optimial_weight(float key, map<int, float> m)
{
	map<int, float>::iterator ite = m.begin();
	for (ite; ite != m.end(); ite++)
	{
		if (ite->second == key)
		{
			return ite->first;
		}
	}
}
int main()
{
	int weight[7] = { 35, 30, 60, 50, 40,10, 25 };
	int value[7] = { 10, 40, 30, 50, 35, 40, 30 };

	vector<float> unit_val(7);
	map<int, float> weight_of_unit_val;

	for (int i = 0; i < unit_val.size(); i++)
	{
		//���㵥λ�����ļ�ֵ
		unit_val[i] = float(value[i]) / float(weight[i]);
		//��Ϊ���� ֵΪ��λ�����ļ�ֵ   map�ڲ���������Ѱ��ռ��Ĵ�С��������
		weight_of_unit_val.insert(pair<int, float>(weight[i], unit_val[i]));
	}
	print_map(weight_of_unit_val);

	//����λ�����ļ�ֵ
	sort(unit_val.begin(), unit_val.end());
	//print_vecotr(unit_val);

	//��������ʣ�������
	int remaining_weight = 150;
	vector<int> bag;
	for (int i = unit_val.size() - 1; i >= 0; i--)
	{
		//������λ��ֵ����������
		int optimial_weight = get_optimial_weight(unit_val[i], weight_of_unit_val);
		remaining_weight = remaining_weight - optimial_weight;
		//��������Ʒ���뱳����ʣ������>=0,��ɽ���������뱳����
		if (remaining_weight >= 0)
			bag.push_back(optimial_weight);
		else
			break;
	}
	cout << "���뱳������Ʒ����Ϊ��";
	print_vecotr(bag);

	return 0;
}
/*
��Ŀ��
�ѡ�����⣬��n����Ҫ��ͬһ�����ҽ��еĻa1,a2...an������ͬһʱ��ֻ����һ�����������ల�ŵĻ������
		a1   a2   a3  a4  a5   a6  a7  a8   a9   a10   a11
start	1    3	  0	   5   3    5   6   8    8     2    12
final	4	 5    6	   7   8    9   10  11   12    13   14

̰�Ĳ��ԣ�Ҫ�ٰ����Ļ��������ѡ���������Ļ
�����ѽ�����ʱ������˵�����������Ŀ�е�ʱ���������ģ������Ȱ��ս���ʱ����е�������
��ʹ��STL vector������������ʱ���������
*/
#include <iostream>
#include <map>
using namespace std;
void print_map(map<int, int> m)
{
	map<int, int>::iterator ite = m.begin();
	for (ite; ite != m.end(); ite++)
	{
		cout << ite->first << " " << ite->second << endl;
	}
}
int main()
{
	int start[11] = { 1,3,0,5,3,5,6,8,8,2,12 };
	int final[11] = { 4,5,6,7,8,9,10,11,12,13,14 };

	map<int, int> arrange;
	//���Ƚ���һ�������������
	arrange.insert(pair<int, int>(start[0], final[0]));

	//�Ƚ������л�Ľ���ʱ��ͽ�������Ŀ�ʼʱ��
	int m = 0;
	for (int i = m+1; i < 11; i++)
	{
		if (start[i] > final[m])
		{
			arrange.insert(pair<int, int>(start[i], final[i]));
			m = i;
		}
	}
	print_map(arrange);
	return 0;
}
/*
��Ŀ��
����Ǯ����������������50,20��10,5,1,0.5,0.1��ֵ��ֽ�ң�����������nԪ������(n/100+1)*100,������Ǯʹ�õ�����ֽ������

̰�Ĳ��ԣ�����Ǯʱ��ʹ����ֵ��������Ǯ�����ʹ�ý��ٵ�ֽ������
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	float n = 67.5;
	int pay_money = int(n / 100 + 1) * 100;
	//����Ӧ�ҵ���Ǯ
	float give_money = pay_money - n;

	//����洢��ֵ��������
	float arr[7] = { 50,20,10,5,1,0.5,0.1 };

	vector<float> small_money;
	//������ֵ���飬Ѱ�Һ��ʵ���ֵ
	for (int i = 0; i < 7; i++)
	{
		//������ֵ���ʣ����ȥ����ֵ
		if (arr[i] <= give_money)
		{
			give_money -= arr[i];
			small_money.push_back(arr[i]);
			//ʹ�ô���ֵ���ж�һ�Σ��Ƿ񻹿��Լ�������Ǯ
			i--;
		}
		//������Ǯ��ϣ����˳�
		if (give_money == 0)
			break;
	}
	for (int i = 0; i < small_money.size(); i++)
		cout << small_money[i] << " ";
	cout << endl;

	return 0;
}