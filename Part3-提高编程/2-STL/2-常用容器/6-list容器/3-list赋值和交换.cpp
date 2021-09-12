/*
功能描述：
    给list容器进行赋值，以及交换list容器
函数原型：
    assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。
    assign(n, elem); //将n个elem拷贝赋值给本身。
    list& operator=(const list &lst); //重载等号操作符
    swap(lst); //将lst与本身的元素互换
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
// 赋值
void test1()
{

    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    // 赋值
    list<int>L2;
    L2 = L1;
    PrintList(L2);

    list<int>L3;
    L3.assign(L2.begin(),L2.end());
    PrintList(L3);

    list<int>L4;
    L4.assign(10,1000);
    PrintList(L4);

}

void test2()
{
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    list<int>L2;
    L2.assign(10,1000);

    cout << "交换前:" << endl;
    PrintList(L1);
    PrintList(L2);

    L1.swap(L2);

    cout << "交换后:" << endl;
    PrintList(L1);
    PrintList(L2);



}

int main()
{
    // test1();
    test2();

    return 0;
}