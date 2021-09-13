/*
功能描述：
    map容器默认排序规则为 按照key值进行 从小到大排序，掌握如何改变排序规则
函数原型：
    利用仿函数，可以改变排序规则。
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

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;

    }

};

void test1()
{
    // 插入时默认从小到大排序
    // 利用仿函数实现从大到小排序
    map<int, int, MyCompare> m;

    m.insert(pair<int, int>(1,10));
    m.insert(pair<int, int>(2,20));
    m.insert(pair<int, int>(3,30));

    for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++)
    {
        cout << "key = " << it->first << " value = "  << it->second << endl;
    }
    
    
    

}


int main()
{
    test1();

    return 0;
}