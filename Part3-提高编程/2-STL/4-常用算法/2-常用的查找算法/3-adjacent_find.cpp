/*
功能描述：
    查找相邻重复元素
函数原型：
    adjacent_find(iterator beg, iterator end);

    // 查找相邻重复元素,返回相邻元素的第一个位置的迭代器

    // beg 开始迭代器

    // end 结束迭代器
*/
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


void test2()
{
    vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);

    vector<int>::iterator it = adjacent_find(v.begin(), v.end());

    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到相邻重复元素" << *it << endl;
    }
    
    


}

int main()
{
    // test1();
    test2();

    return 0;
}