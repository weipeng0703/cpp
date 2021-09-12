/*
功能描述：
    set容器默认排序规则为从小到大，掌握如何改变排序规则

    利用仿函数，可以改变排序规则
*/

#include<string>
#include<iostream>
#include<set>
using namespace std;

class MyCompare
{
public:
    bool operator()(int v1, int v2)
    {
        return v1 > v2;
    }


};
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
    s1.insert(40);
    s1.insert(20);
    s1.insert(30);
    s1.insert(60);

    for (set<int>::iterator it = s1.begin(); it != s1.end(); it++)
    {
        cout << *it << ' ';
    }

    cout << endl;

    // 指定排序规则
    set<int,MyCompare> s2;

    s2.insert(10);
    s2.insert(40);
    s2.insert(20);
    s2.insert(30);
    s2.insert(60);

    for (set<int,MyCompare>::iterator it = s2.begin(); it != s2.end(); it++)
    {
        cout << *it << ' ';
    }    
    
}

class Person
{
public: 

    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;

    }

    string m_Name;
    int m_Age;
};

class ComparePerson
{
public:
    bool operator()(const Person &p1, const Person &p2)
    {
        return p1.m_Age > p2.m_Age;

    }


};

void test2()
{
    // 自定义数据类型一般都会指定排序规则
    set<Person, ComparePerson> s;

	Person p1("刘备", 23);
	Person p2("关羽", 27);
	Person p3("张飞", 25);
	Person p4("赵云", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

    for (set<Person,ComparePerson>::iterator it = s.begin(); it != s.end(); it++)
    {
        cout << "姓名为:" << (*it).m_Name << " 年龄为:" << (*it).m_Age << endl;
    }
    cout << endl;
}

int main()
{

    // test1();    // 1.set存放内置数据类型
    test2();    // 2.set存放自定义数据类型

    return 0;
}