/*
功能描述
    创建set容器以及赋值
构造：
    set<T> st; //默认构造函数：
    set(const set &st); //拷贝构造函数
赋值：
    set& operator=(const set &st); //重载等号操作符
*/

#include<string>
#include<iostream>
#include<set>
using namespace std;

void PrintSet(set<int> s)
{
    for (set<int>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;


}
void test1()
{
    set<int> s1;

    s1.insert(10);
    s1.insert(20);
    s1.insert(30);
    s1.insert(40);

    PrintSet(s1);

    // 拷贝构造
    set<int> s2(s1);
    PrintSet(s2);

    // 赋值
    set<int> s3;
    s3 = s2;
    PrintSet(s3);
}


int main()
{

    test1();

    return 0;
}