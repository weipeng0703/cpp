/*
结构体属于用户自定义的数据类型，允许用户存储不同的数据类型

通过结构体创建变量的方式有三种：（1 ，2常用）

1.struct 结构体名 变量名
2.struct 结构体名 变量名 = { 成员1值 ， 成员2值…}
3.定义结构体时顺便创建变量
*/

#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

// 1.创建学生数据类型：学生（姓名，年龄，分数）
// 自定义数据类型，一些类型的集合体组成的一个类型
// 语法    strucu 类型名称 {  成员列表  }
struct Student
{
    string name;
    int age;
    int score;
}s3;   //顺便创建一个结构体变量

// 2.通过学生类型创建具体学生

int main()
{

    // 1.struct 结构体名 变量名
    // struct在创建结构体变量时可以省略，但是在之前定义时不能省略
    struct Student s1;
    // 给s1属性赋值，通过 . 访问结构体变量中的属性
    s1.name = "张三";
    s1.age = 18;
    s1.score = 100;

    cout << "姓名：" << s1.name << " 年龄：" << s1.age << " 成绩：" << s1.score << endl;
    
    // 2.struct 结构体名 变量名 = { 成员1值 ， 成员2值…}
    struct Student s2 = {"李四",19,80};
    cout << "姓名：" << s2.name << " 年龄：" << s2.age << " 成绩：" << s2.score << endl;
    
    // 3.定义结构体时顺便创建变量
    s3.name = "王五";
    s3.age = 21;
    s3.score = 60;
    cout << "姓名：" << s3.name << " 年龄：" << s3.age << " 成绩：" << s3.score << endl;
    
    return 0;
}