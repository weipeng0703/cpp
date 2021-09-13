/*
功能描述：
    map容器进行插入数据和删除数据
函数原型：
    insert(elem); //在容器中插入元素。
    clear(); //清除所有元素
    erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
    erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
    erase(key); //删除容器中值为key的元素。
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
    // 1.
    m.insert(pair<int, int>(1,10));

    // 2.
    m.insert(make_pair(2,20));

    // 3.
    m.insert(map<int, int>::value_type(3,30));

    // 4.
    m[4] = 40;
    // PrintMap(m);

    // 删除
    m.erase(m.begin());
    // PrintMap(m);

    m.erase(3);
    // PrintMap(m);

    // 清空
    // m.erase(m.begin(), m.end());

    m.clear();
    PrintMap(m);



}


int main()
{
    test1();

    return 0;
}