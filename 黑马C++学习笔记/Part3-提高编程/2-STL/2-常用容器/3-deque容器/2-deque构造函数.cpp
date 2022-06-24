/*
功能描述：
    deque容器构造
函数原型：

    deque<T> deqT; //默认构造形式
    deque(beg, end); //构造函数将[beg, end)区间中的元素拷贝给本身。
    deque(n, elem); //构造函数将n个elem拷贝给本身。
    deque(const deque &deq); //拷贝构造函数
*/

#include<iostream>
#include<string>
#include<vector>
#include<deque>
using namespace std;

void PrintDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        // 现在容器内的数据不可以修改
        cout << *it << ' ';
    }
    
    cout << endl;

}

void test1()
{
    deque<int> d1;  // 默认/无参构造

    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }

    PrintDeque(d1);

    // // 通过区间的方式构造
    deque<int>d2(d1.begin(), d1.end());
    PrintDeque(d2);

    // // n个elem的方式构造
    deque<int> d3(10,100);
    PrintDeque(d3);

    // // 拷贝构造
    deque<int> d4(d3);
    PrintDeque(d4);
}


int main()
{
    test1();

    return 0;
}