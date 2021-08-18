/*
作用： 结构体中的成员可以是另一个结构体

**例如：**每个老师辅导一个学员，一个老师的结构体中，记录一个学生的结构体
*/
#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

// 定义学生结构体
struct student
{
    string name;
    int age;
    int score;
};

// 定义老师结构体
struct teacher
{
    int id;
    string name;
    int age;
    struct student stu1;
};

int main()
{
    struct teacher t;
    t.id = 1000;
    t.name = "老王";
    t.age = 30;
    t.stu1.name = "小王";
    t.stu1.age = 18;
    t.stu1.score = 100;

    cout << "\n老师编号为：" << t.id << "\n老师姓名为：" << t.name 
         << "\n老师年龄为：" << t.age << "\n老师辅导的学生姓名为：" << t.stu1.name 
         << "\n老师辅导的学生年龄为：" << t.stu1.age 
         << "\n老师辅导的学生成绩为：" << t.stu1.score << endl;

    return 0;
}