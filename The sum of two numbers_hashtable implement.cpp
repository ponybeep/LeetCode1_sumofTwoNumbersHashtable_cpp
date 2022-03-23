#define _CRT_SECURE_NO_WARNINGS 1
using namespace std;
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <map>					//由于需要map容器，要加载头文件，一般<>是标准头文件，而""是非系统头文件
//题目描述：
//力扣第一题，非常经典 ,用hash表实现
//给定一个整数数组 nums和一个整数目标值 target ,在该数组中找出和为目标值target的两个整数，并返回它们的数组下标
//假设每种输入只会对应一个答案。但是，数组中同一个元素在答案中不能重复出现
//创建一个类，来解决问题

//解题思路：若“目标和target"  减去  数组中第一个数至最后一个数（for循环） 的差    在容器m中找到了，那么就将这个m容器key值所指向的实值赋给 b[0],即第一个数的下标，将遍历到的那个
//数的下标赋给b[1],即第二个数的下标。
//若这个差在容器m中没找到，就将这个数的下标作为实值，这个数作为key值，存在map容器中。

//注： map<int,int>容器中第一个int为key值，第二个key值为实值，默认以key来升序排列


class Solution
{
	//基本上都是公有类
public:
	vector<int> Twosum(vector<int>& nums, int target)		//类中的一个成员函数，函数名是Twosum,返回值是一个vector<int>容器，参数列表有一个vector<int>的容器，装入数组，还有一个\
															int 的整数，装入两数的和。
	{
		map<int, int> m;									//创建一个hash表，用来存数组的下标
		vector<int> b(2, -1);								//创建一个vector<int>容器，用来存两数之和为target的数所在数组vector<int> nums中的下标，初始化为大小2个，初始值为-1。
		for (int i = 0; i < nums.size(); i++)				//开始循环了，从数组第一个开始索引
		{
			if (m.count(target - nums[i]) > 0)				
			{
				b[0] = m[target - nums[i]];
				b[1] = i;
				break;
			}
			m[nums[i]] = i;
		}
		return b;
	}
};

void test01()
{
	int testnumarray[] = { 1,4,6,7,11,14,19 };
	int target = 33;
	vector<int> nums(testnumarray, testnumarray + sizeof(testnumarray) / sizeof(int));
	Solution solution;
	cout << "数组为：";
	for (int i = 0; i < nums.size(); i++)
	{
		cout <<nums[i] << " ";
	}
	cout << endl;
	cout << "目标和为：" << target << endl;
	cout << "第一个数的下标为: " << solution.Twosum(nums, target)[0] << endl;
	cout << "第二个数的下标为：" << solution.Twosum(nums, target)[1] << endl;

}


int main() {

	test01();






	system("pause");
	return 0;
}