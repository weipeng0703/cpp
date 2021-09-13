/*
功能描述：
    对map容器进行构造和赋值操作
函数原型：
构造：
    map<T1, T2> mp; //map默认构造函数:
    map(const map &mp); //拷贝构造函数
赋值：
    map& operator=(const map &mp); //重载等号操作符
*/
#include<string>
#include<iostream>
#include<map>
using namespace std;

void PrintMap(map<int, int> &m)
{
    for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = " << it->second << endl;
    }
    

}

void test1()
{
    map<int, int> m;
    m.insert(pair<int ,int> (1,10));
    m.insert(pair<int ,int> (2,20));
    m.insert(pair<int ,int> (3,30));
    PrintMap(m);

    // 拷贝构造
    map<int ,int> m2(m);
    PrintMap(m2);

    map<int, int> m3;
    m3 = m2;
    PrintMap(m3);

}

int main()
{
    test1();

    return 0;
}