/*
功能描述：
    对set容器进行查找数据以及统计数据
函数原型：
    find(key); //查找key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
    count(key); //统计key的元素个数
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

    // 查找
    set<int>::iterator pos = s1.find(30);

    if(pos != s1.end())
    {
        cout << "找到了元素" << *pos << endl;

    }
    else
    {
        cout << "未找到元素" << endl;
    }
    
    // 统计元素出现的次数
    int num = s1.count(40);
    cout << "num = " << num << endl;
    
}
void test2()
{
    set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int> s2;

	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);

	cout << "交换前" << endl;
	PrintSet(s1);
	PrintSet(s2);
	cout << endl;

	cout << "交换后" << endl;
	s1.swap(s2);
	PrintSet(s1);
	PrintSet(s2);

}


int main()
{

    test1();
    // test2();

    return 0;
}