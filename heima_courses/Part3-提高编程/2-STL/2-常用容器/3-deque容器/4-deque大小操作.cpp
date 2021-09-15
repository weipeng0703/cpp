/*
功能描述：
    对deque容器的大小进行操作
函数原型：
    deque.empty(); //判断容器是否为空

    deque.size(); //返回容器中元素的个数

    deque.resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。

    ​ //如果容器变短，则末尾超出容器长度的元素被删除。

    deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。

    ​ //如果容器变短，则末尾超出容器长度的元素被删除
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
    deque<int> d1;  

    for (int i = 0; i < 10; i++)
    {
        d1.push_back(i);
    }

    PrintDeque(d1);

    if (d1.empty())
    {
        cout << "d1为空" << endl;
    }
    else
    {
        cout << "d1不为空" << endl;
        cout << "d1 的大小为：" << d1.size() << endl;
        // deque容器没有容量概念，因为它可以任意扩充大小
    }

    // d1.resize(15);
    // PrintDeque(d1);
    cout << "d1 的大小为：" << d1.size() << endl;

    d1.resize(16,1);
    PrintDeque(d1);

    d1.resize(6);
    PrintDeque(d1);



}


int main()
{
    test1();

    return 0;
}