/*
功能描述：
    对list容器的大小进行操作
函数原型：
    size(); //返回容器中元素的个数
    empty(); //判断容器是否为空
    resize(num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
    ​ //如果容器变短，则末尾超出容器长度的元素被删除。
    resize(num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置
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

    if (L1.empty())
    {
        cout << "L1为空" << endl;
    }
    else
    {
        cout << "L1不为空" << endl;
        cout << "L1的大小为:" << L1.size() <<  endl;
    }
    // 重新指定大小
    // L1.resize(20);
    // PrintList(L1);

    L1.resize(2);
    PrintList(L1);
} 


int main()
{
    test1();
    // test2();

    return 0;
}