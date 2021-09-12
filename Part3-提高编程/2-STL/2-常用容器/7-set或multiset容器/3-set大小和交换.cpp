/*
功能描述：
    统计set容器大小以及交换set容器
函数原型：
    size(); //返回容器中元素的数目
    empty(); //判断容器是否为空
    swap(st); //交换两个集合容器
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

    if (s1.empty())
    {
        cout << "s1为空" << endl;
    }
    else
    {
        cout << "s1不为空" << endl;
        cout << "s1的大小为:" << s1.size() << endl;
    }
    
    
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

    // test1();
    test2();

    return 0;
}