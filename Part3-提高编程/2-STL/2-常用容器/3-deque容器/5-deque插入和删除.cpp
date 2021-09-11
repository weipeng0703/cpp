/*
功能描述：
    对deque容器进行插入和删除

函数原型：
两端插入操作：
    push_back(elem); //在容器尾部添加一个数据
    push_front(elem); //在容器头部插入一个数据
    pop_back(); //删除容器最后一个数据
    pop_front(); //删除容器第一个数据

指定位置操作：

    insert(pos,elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置。

    insert(pos,n,elem); //在pos位置插入n个elem数据，无返回值。

    insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值。

    clear(); //清空容器的所有数据

    erase(beg,end); //删除[beg,end)区间的数据，返回下一个数据的位置。

    erase(pos); //删除pos位置的数据，返回下一个数据的位置。
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

// 两端操作
void test1()
{
    deque<int> d1;  

    // 尾插
    d1.push_back(10);
    d1.push_back(20);

    // 头插
    d1.push_front(100);
    d1.push_front(200);

    PrintDeque(d1);

    // 尾删
    d1.pop_back();
    PrintDeque(d1);

    // 头删
    d1.pop_front();
    PrintDeque(d1);



}

// 对指定位置的操作
void test2()
{
    deque<int> d1;  

    // 尾插
    d1.push_back(10);
    d1.push_back(20);

    // 头插
    d1.push_front(100);
    d1.push_front(200);

    PrintDeque(d1);

    // insert
    d1.insert(d1.begin(), 1000);
    PrintDeque(d1);

    d1.insert(d1.begin(), 2, 10000);
    PrintDeque(d1);

    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);

    d1.insert(d1.begin(), d2.begin(), d2.end());
    PrintDeque(d1);
}

// 删除
void test3()
{
    deque<int> d2;
    d2.push_back(1);
    d2.push_back(2);
    d2.push_back(3);
    PrintDeque(d2);

    // 删除
    deque<int>::iterator it = d2.begin();
    it++;
    d2.erase(it);
    PrintDeque(d2);

    // d2.erase(d2.begin(),d2.end());
    // PrintDeque(d2);

    // 清空操作
    d2.clear();
    PrintDeque(d2);

}


int main()
{
    // test1();
    // test2();
    test3();

    return 0;
}