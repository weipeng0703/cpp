/*
功能描述：
    查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()
函数原型：
    find(iterator beg, iterator end, value);

    // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

    // beg 开始迭代器

    // end 结束迭代器

    // value 查找的元素
*/
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

void test1()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i+1);
    }

    // 查找容器中是否有5这个元素
    vector<int>::iterator it = find(v.begin(), v.end(), 5);

    if (it != v.end())
    {
        cout << "找到" << *it << endl;
    }
    else
    {
        cout << "未找到" << endl;
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

    // 重载==
    bool operator==(const Person &p)
    {
        if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
        {
            return true;
        }
        return false;
    }


public:
    string m_Name;
    int m_Age;
};

void test2()
{
    vector<Person> v;

	//创建数据
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

    vector<Person>::iterator it = find(v.begin(), v.end(), p2);

    if (it == v.end())
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到" << (*it).m_Name << " 年龄为" << (*it).m_Age << endl;
    }
    
    


}

int main()
{
    // test1();
    test2();

    return 0;
}