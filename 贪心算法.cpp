/*
贪心算法
制定贪心策略，每次仅考虑局部最优解(贪心策略下)，而不是从全局上来考虑最优解，所以最终的结果是
通过局部最优解近似全局最优解。

所以关键问题是贪心策略如何选择！

其与动态规划的相似之处是都是求解最小问题的最优解，最大区别是动态规划需要保存之前的最小问题的最优解，
以此来计算另一问题的最优解，而贪心算法则不需要保存之前的最小问题的最优解。
*/
/*
题目一
背包问题，若背包总容量是150，有七个物品，但每个物品的重量与价值不定，选择可以存入背包中的最大价值的
总容量。
物品： A  B  C  D  E  F  G
重量： 35 30 60 50 40 10 25
价值： 10 40 30 50 35 40 30

贪心策略：单位重量的价值最大的先进入背包
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
		//计算单位重量的价值
		unit_val[i] = float(value[i]) / float(weight[i]);
		//键为重量 值为单位重量的价值   map在插入过程中已按照键的大小升序排序
		weight_of_unit_val.insert(pair<int, float>(weight[i], unit_val[i]));
	}
	print_map(weight_of_unit_val);

	//排序单位重量的价值
	sort(unit_val.begin(), unit_val.end());
	//print_vecotr(unit_val);

	//声明背包剩余的容量
	int remaining_weight = 150;
	vector<int> bag;
	for (int i = unit_val.size() - 1; i >= 0; i--)
	{
		//获得最大单位价值的物体重量
		int optimial_weight = get_optimial_weight(unit_val[i], weight_of_unit_val);
		remaining_weight = remaining_weight - optimial_weight;
		//若将此物品放入背包后，剩余容量>=0,则可将此物体放入背包中
		if (remaining_weight >= 0)
			bag.push_back(optimial_weight);
		else
			break;
	}
	cout << "存入背包的物品重量为：";
	print_vecotr(bag);

	return 0;
}
/*
题目二
活动选择问题，有n个需要在同一个教室进行的活动a1,a2...an，但是同一时段只能有一个活动，所以最多安排的活动数量？
		a1   a2   a3  a4  a5   a6  a7  a8   a9   a10   a11
start	1    3	  0	   5   3    5   6   8    8     2    12
final	4	 5    6	   7   8    9   10  11   12    13   14

贪心策略：要举办更多的活动，所以需选择更早结束的活动
本题已将结束时间进行了递增排序，若题目中的时间表是乱序的，需首先按照结束时间进行递增排序
可使用STL vector容器，将结束时间进行排序。
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
	//首先将第一个活动存入容器中
	arrange.insert(pair<int, int>(start[0], final[0]));

	//比较容器中活动的结束时间和接下来活动的开始时间
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
题目三
找零钱的最少张数，假设50,20，10,5,1,0.5,0.1面值的纸币，若购物消费n元，付款(n/100+1)*100,则找零钱使用的最少纸币数量

贪心策略：在找钱时，使用面值最大的来找钱，则会使用较少的纸币数量
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	float n = 67.5;
	int pay_money = int(n / 100 + 1) * 100;
	//计算应找的零钱
	float give_money = pay_money - n;

	//降序存储面值在数组中
	float arr[7] = { 50,20,10,5,1,0.5,0.1 };

	vector<float> small_money;
	//遍历面值数组，寻找合适的面值
	for (int i = 0; i < 7; i++)
	{
		//若此面值合适，则减去此面值
		if (arr[i] <= give_money)
		{
			give_money -= arr[i];
			small_money.push_back(arr[i]);
			//使用此面值再判断一次，是否还可以继续找零钱
			i--;
		}
		//若找零钱完毕，则退出
		if (give_money == 0)
			break;
	}
	for (int i = 0; i < small_money.size(); i++)
		cout << small_money[i] << " ";
	cout << endl;

	return 0;
}