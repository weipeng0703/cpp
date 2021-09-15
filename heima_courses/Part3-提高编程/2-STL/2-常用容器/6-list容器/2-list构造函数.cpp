/*
功能描述：
    创建list容器
函数原型：
    list<T> lst; //list采用采用模板类实现,对象的默认构造形式：
    list(beg,end); //构造函数将[beg, end)区间中的元素拷贝给本身。
    list(n,elem); //构造函数将n个elem拷贝给本身。
    list(const list &lst); //拷贝构造函数。
*/
#include<iostream>
#include<list>
using namespace std;

void PrintList(const list<int> &L)
{
    for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

}
void test1()
{
    // 1.空定义
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    PrintList(L1);
    // 2.区间定义
    list<int>L2(L1.begin(),L1.end());
    PrintList(L2);

    // 3.拷贝构造
    list<int>L3(L2);
    PrintList(L3);
    // 4.n个elem
    list<int>L4(10,1000);
    PrintList(L4);



}

int main()
{
    test1();

    return 0;
}