/*
1. 递归
递归可分开理解为去和回，先深入到各个子问题中，解决了之后，再一步步回来。
2. 编写递归程序的步骤
a. 递归截止的条件
b. 递归截止如何处理
c. 提取重复步骤，进行递归
3. 分治法
首先将问题分解为子问题，然后递归的去解决这些问题，最后将子问题的解合并为原问题的解。
4. 编写分支法程序的步骤
a. 分解原问题为子问题
b. 递归解决子问题
c. 合并子问题的解
*/
/*
题目一
全排列，获得一个字符串的所有排列组合方式？

两个重复步骤：
a.先保持第一个元素不动，然后全排列后面的字符串，后面的字符串同样进行保持第一个元素不动，然后全排列
接下来的字符串，直到最后一个元素停止；
b. 交换字符串中第一个元素与其余元素的位置，继续进行步骤a；
所以步骤b在上，使用for循环实现，a步骤在下，使用递归实现。
*/
#include <iostream>
#include <string>
using namespace std;
void penmutation(string str, int begin, int length)
{
	//递归结束条件
	if (begin == length - 1)
	{
		cout << str << endl;
	}
	//提取重复步骤，进行递归
	for (int i = begin; i < length; i++)
	{
		//从首个字符开始交换
		swap(str[i], str[begin]);
		//对当前字符之后的字符串进行全排列
		penmutation(str, begin + 1, length);
		//再交换回来，继续下个字符串的递归
		swap(str[i], str[begin]);
	}
}
int main()
{
	string str = "abc";
	penmutation(str, 0, 3);
	return 0;
}