/*
功能描述：
    实现遍历容器
函数原型：
    for_each(iterator beg, iterator end, _func);

    // 遍历算法 遍历容器元素

    // beg 开始迭代器

    // end 结束迭代器

    // _func 函数或者函数对象
*/
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

// 普通函数
void print1(int val)
{
    cout << val << " ";

}
// 函数对象
class print2
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }

};
void test1()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }

    // 遍历算法
    for_each(v.begin(), v.end(), print1);
    cout << endl;

    for_each(v.begin(), v.end(), print2());

}
int main()
{
    test1();

    return 0;
}