/*
学习目标：vector中存放自定义数据类型，并打印输出
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// 存放自定义数据类型——类
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

void test1()
{
    vector<Person>v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    // 向容器中插入数据
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);

    // 遍历容器数据
    for (vector<Person>::iterator it = v.begin();it != v.end(); it++)
    {
        // cout << "姓名为：" << (*it).m_Name << " 年龄为：" << (*it).m_Age << endl;  (*it)是指针解引用出的数据
        // ()里的数据类型解出来就是上面<>内的数据类型

        cout << "姓名为：" << it->m_Name << " 年龄为：" << it->m_Age << endl;  // 因为it就是指针
    }
    
}

// 存放自定义数据类型——指针

void test2()
{
    vector<Person*>v;
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    // 向容器中插入数据
    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
    {
         cout << "姓名为：" << (*it)->m_Name << " 年龄为：" << (*it)->m_Age  << endl;  // 因为it就是指针
    }
    

}

int main()
{
    // test1();
    test2();


    return 0;
}