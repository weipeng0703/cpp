/*
功能描述：
    成对出现的数据，利用对组可以返回两个数据
两种创建方式：
    pair<type, type> p ( value1, value2 );
    pair<type, type> p = make_pair( value1, value2 );
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
    // 1.
    pair<string, int>p("Tom",20);
    cout << "姓名:" << p.first << " 年龄:" << p.second << endl;
    
    // 2.
    pair<string,int>p2 = make_pair("Jerry",20);
    cout << "姓名:" << p.first << " 年龄:" << p.second << endl;
}


int main()
{

    test1();
    // test2();

    return 0;
}