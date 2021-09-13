/*
功能描述：
    对map容器进行查找数据以及统计数据
函数原型：
    find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
    count(key); //统计key的元素个数。
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
    // 插入
    map<int, int> m;

    m.insert(pair<int, int>(1,10));
    m.insert(pair<int, int>(2,20));
    m.insert(pair<int, int>(3,30));

    // 查找
    map<int, int>::iterator pos = m.find(3);

    if (pos != m.end())
    {
        cout << "找到了元素，key = " << (*pos).first << " value = " << (*pos).second << endl; 
    }
    else
    {
        cout << "未找到该元素" << endl;
    }

    // 统计
    int num = m.count(3);
    cout << "3出现的次数为：" << num << endl;
    
    

}


int main()
{
    test1();

    return 0;
}