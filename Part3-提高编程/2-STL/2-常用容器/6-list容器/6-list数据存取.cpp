/*
功能描述：
    对list容器内的数据进行存取
函数原型：
    front(); //返回第一个元素。
    back(); //返回最后一个元素。
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
// 插入和删除
void test1()
{
    // 尾插
    list<int> L1;
    L1.push_back(10);
    L1.push_back(20);
    L1.push_back(30);
    L1.push_back(40);

    // cout << L1.at(0) << endl;  // 错误,list容器不支持at访问数据
    // cout << L1[0] << endl;  // 错误,list容器不支持[]访问数据

    cout << "第一个元素为:" << L1.front() << endl;
    cout << "最后一个元素为:" << L1.back() << endl;

    // list容器的迭代器是双向迭代器,不支持随机访问
    list<int>::iterator it = L1.begin();
    // it++;   // 错误,不可以跳跃访问,即使是+1

} 


int main()
{
    test1();
    // test2();

    return 0;
}