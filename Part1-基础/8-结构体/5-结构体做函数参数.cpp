/*
**作用：**将结构体作为参数向函数中传递

传递方式有两种：

1.值传递：形参改变不影响实参
2.地址传递：形参改变实参也会改变

总结：如果不想修改主函数中的数据，用值传递，反之用地址传递
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

// 打印学生信息的函数
// 1.值传递
void PrintStudentInfo1(struct student s)
{
    cout << "子函数1中：" << endl;
    // s.age = 100;   // 形参改变不会改变实参
    // cout << s.age << endl;
    cout << "姓名：" << s.name << " 年龄：" << s.age << " 成绩：" << s.score << endl;
}


// 2.地址传递
void PrintStudentInfo2(struct student *p)
{
    cout << "子函数2中：" << endl;
    p -> age = 100;   // 形参改变会改变实参
    cout << p -> age << endl;
    cout << "姓名：" << p->name << " 年龄：" << p->age << " 成绩：" << p->score << endl;
}

int main()
{
    struct student s;
    s.name = "张三";
    s.age = 20;
    s.score = 100;

    cout << "main函数中：" << endl;
    cout << "姓名：" << s.name << " 年龄：" << s.age << " 成绩：" << s.score << endl;
    
    PrintStudentInfo1(s);
    PrintStudentInfo2(&s);

    // 测试改变形参对实参的影响
    cout << s.age << endl;
    return 0;
}
