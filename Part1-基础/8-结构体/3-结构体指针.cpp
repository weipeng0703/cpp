/*
**作用：**通过指针访问结构体中的成员

利用操作符 -> 可以通过结构体指针访问结构体属性
*/
#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

struct Student
{
    string name;
    int age;
    int score;
};

int main()
{
    // 1.创建学生的结构体变量
    struct Student s1 = {"张三" , 18 , 100};

    // 2.通过指针指向结构体变量
    struct Student * p = &s1;

    // 3.通过指针访问结构体变量中的数据
    cout << "姓名："  << p->name << " 年龄："  << p->age << " 成绩："  << p->score << endl;

    return 0;
}