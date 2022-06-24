/*
功能描述：
    将容器中的元素反转，以及将容器中的数据进行排序
函数原型：
    reverse(); //反转链表
    sort(); //链表排序
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
bool MyCompare(int val1, int val2)
{

    return val1 > val2;

}
// 反转和排序
void test1()
{
    // 尾插
    list<int> L1;
    L1.push_back(20);
    L1.push_back(50);
    L1.push_back(10);
    L1.push_back(40);

    PrintList(L1);

    // 反转容器内元素
    // L1.reverse();
    // PrintList(L1);

    // 排序
    // L1.sort();   // 默认是从小到大排序
    L1.sort(MyCompare);   // 按照指定规则排序
    PrintList(L1);

} 


int main()
{
    test1();
    // test2();

    return 0;
}