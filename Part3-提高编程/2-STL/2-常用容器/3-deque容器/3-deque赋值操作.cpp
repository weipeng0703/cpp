/*
功能描述：
    deque容器的赋值
函数原型：
    deque& operator=(const deque &deq); //重载等号操作符

    assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。

    assign(n, elem); //将n个elem拷贝赋值给本身
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

    // 1.operator = 
    deque<int> d2;
    d2 = d1;
    PrintDeque(d2);

    // 2.assign区间
    deque<int> d3;
    d3.assign(d1.begin(), d1.end());
    PrintDeque(d3);

    // 3.assign赋值n个相同的数据
    deque<int> d4;
    d4.assign(10,100);
    PrintDeque(d4);
}


int main()
{
    test1();

    return 0;
}