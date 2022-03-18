#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <stdio.h>
#include<iomanip>
#include<algorithm>
using namespace std; 

class Person { 
public:     
    Person(const string& name, int age) : m_name(name), m_age(age) {     }
    void ShowInfo() {
        cout << "姓名：" << m_name << endl;         
        cout << "年龄：" << m_age << endl;     
    }     
protected:     
    string m_name;     //姓名  
private:
    int m_age;      //年龄 
};
class Teacher : public Person
{
public:
    Teacher(const string& name, int age, const string& title)
         : Person(name, age), m_title(title){}
    void ShowTeacherInfo()
    {
        ShowInfo();                             //正确，public属性子类可见
        cout << "姓名：" << m_name << endl;      //正确，protected属性子类可见
        cout << "年龄：" << m_age << endl;     //错误，private属性子类不可见

        cout << "职称：" << m_title << endl;   //正确，本类中可见自己的所有成员
    }

private:
    string  m_title;        //职称
};