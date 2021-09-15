/*
功能描述：
    对deque容器进行数据存取

函数原型：
    at(int idx); //返回索引idx所指的数据
    operator[]; //返回索引idx所指的数据
    front(); //返回容器中第一个数据元素
    back(); //返回容器中最后一个数据元素
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

void test3()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);

    // 通过[]方式访问元素
    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1[i] << " ";
    }
    cout << endl;

    // 通过at方式访问元素
    for (int i = 0; i < d1.size(); i++)
    {
        cout << d1.at(i) << " ";
    }
    cout << endl;

    cout << "d1的首元素为:" << d1.front() << endl;
    cout << "d1的尾元素为:" << d1.back() << endl;
    
}

int main()
{
    // test1();
    // test2();
    test3();

    return 0;
}