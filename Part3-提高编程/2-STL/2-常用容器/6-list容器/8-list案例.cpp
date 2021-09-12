/*
案例描述：将Person自定义数据类型进行排序，Person中属性有姓名、年龄、身高

排序规则：按照年龄进行升序，如果年龄相同按照身高进行降序
*/
#include<iostream>
#include<list>
using namespace std;

class Person
{
public:
    Person(string name,int age, int height)
    {
        this->m_Name = name;
        this->m_Age = age;
        this->m_Height = height;

    }

    string m_Name;
    int m_Age;
    int m_Height;    

};  

bool myCompare(Person &p1,Person &p2)
{
    if (p1.m_Age == p2.m_Age)
    {
        // 年龄相同,按照身高排序
        return p1.m_Height > p2.m_Height;
    }
    else
    {    
        // 年龄升序
        return p1.m_Age < p2.m_Age;
    }

    
}

void test1()
{
    list<Person> L;

    // 准备数据
    Person p1("刘备", 35 , 175);
	Person p2("曹操", 45 , 180);
	Person p3("孙权", 40 , 170);
	Person p4("赵云", 25 , 190);
	Person p5("张飞", 35 , 160);
	Person p6("关羽", 35 , 200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

    cout << "-----------排序前-----------:" << endl;
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名:" << (*it).m_Name << " 年龄:" << (*it).m_Age << " 身高:" << (*it).m_Height << endl;
    }

    // 排序
    cout << "-----------排序后-----------:" << endl;
    L.sort(myCompare);
    for (list<Person>::iterator it = L.begin(); it != L.end(); it++)
    {
        cout << "姓名:" << (*it).m_Name << " 年龄:" << (*it).m_Age << " 身高:" << (*it).m_Height << endl;
    }

}


int main()
{
    test1();
    // test2();

    return 0;
}