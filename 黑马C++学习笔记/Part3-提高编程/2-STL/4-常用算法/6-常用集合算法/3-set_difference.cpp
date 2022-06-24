/*
功能描述：
    求两个容器的差集
函数原型：
    set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

    // 求两个集合的差集

    // 注意:两个集合必须是有序序列

    // beg1 容器1开始迭代器
    // end1 容器1结束迭代器
    // beg2 容器2开始迭代器
    // end2 容器2结束迭代器
    // dest 目标容器开始迭代器
注：
    求差集的两个集合必须是有序序列
    目标容器开辟空间需要从两个容器取较大值
*/
#include <vector>
#include <algorithm>
#include<iostream>
using namespace std;

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};

void test1()
{
   vector<int> v1;
   vector<int> v2;

   for (int i = 0; i < 10; i++)
   {
       v1.push_back(i);
       v2.push_back(i+5);
   }

   cout << "v1容器：" << endl;
   for_each(v1.begin(), v1.end(), myPrint());
   cout << endl;
   cout << "v2容器：" << endl;
   for_each(v2.begin(), v2.end(), myPrint());
   cout << endl;

   vector<int> vTarget;
    // 取两个里面较大的值给目标容器开辟空间
    vTarget.resize(max(v1.size(), v2.size()));

    // 返回目标容器的最后一个元素的迭代器地址
    vector<int>::iterator itEnd = set_difference(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

    cout << "两个容器的差集为：" << endl;
    for_each(vTarget.begin(), itEnd, myPrint());
    cout << endl;

    
}

int main()
{
    test1();

    return 0;
}