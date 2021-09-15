/*
**作用：**用const来防止误操作
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

// void PrintStudentInfo(struct student s)

//一个指针只占4个内存，不管结构体中有多少属性。这样可以大大减少内存开销
void PrintStudentInfo(const struct student *s)  
{
    // s -> age = 150;     // 加入const后，一旦有修改的操作此处就会报错，可以防止误操作
    cout << "姓名为：" << s -> name << " 年龄为：" << s -> age << " 成绩为：" << s -> score << endl;

}

int main()
{
    struct student s1 = {"张三", 15, 70};

    PrintStudentInfo(&s1);

    cout << s1.age << endl;

    return 0;
}