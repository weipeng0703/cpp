/*
功能描述：
    对容器内元素进行排序
函数原型：
    sort(iterator beg, iterator end, _Pred);

    // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

    // beg 开始迭代器

    // end 结束迭代器

    // _Pred 谓词
*/
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

void MyPrint(int val)
{
    cout << val << " ";

}

void test1()
{
    vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

    // sort默认从小到大排序
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), MyPrint);
    cout << endl;

    // 从大到小排序
    sort(v.begin(), v.end(), greater<int>());
    for_each(v.begin(), v.end(), MyPrint);
    cout << endl;


}

int main()
{
    test1();

    return 0;
}