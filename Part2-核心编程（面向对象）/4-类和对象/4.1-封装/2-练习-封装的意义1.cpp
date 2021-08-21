/*
设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
*/
#include<iostream>
#include<string>
using namespace std;

/*
class Student
{
public:     // 公共权限
    // 属性 
    int num;
    string name;

    // 行为
    void ShowInfo()
    {
        cout << "学生的学号为："  << num << endl;
    	cout << "学生的姓名为："  << name << endl;
	}
};

int main()
{
    // 通过 学生类 创建具体的 学生（一个对象）
    // 实例化（通过一个类创建一个对象的过程）
    Student student1;
    // 给圆对象的 属性 进行赋值
    student1.num = 1;
	student1.name = "张三";
	
    student1.ShowInfo();

    return 0;
}
*/

class Student
{
public:     // 公共权限

    // 类中的（属性和行为）统称为 成员
    // 属性：成员属性/成员变量
    // 行为：成员函数/成员方法

    // 属性 
    int s_num;
    string s_name;

    // 行为
    void ShowInfo()
    {
        cout << "学生的学号为："  << s_num << endl;
    	cout << "学生的姓名为："  << s_name << endl;
	}

    // 通过行为赋值
    void SetName(string name)
    {
        s_name = name;
    }
    void SetNum(int num)
    {
        s_num = num;
    }
};

int main()
{
    // 通过 学生类 创建具体的 学生（一个对象）
    // 实例化（通过一个类创建一个对象的过程）
    Student student1;
    // 给圆对象的 属性 进行赋值
    student1.SetNum(1);
	student1.SetName("张三");
	
    student1.ShowInfo();

    return 0;
}