/*
多态是C++面向对象三大特性之一

多态分为两类
    静态多态: 函数重载 和 运算符重载属于静态多态，复用函数名
    动态多态: 派生类和虚函数实现运行时多态

静态多态和动态多态区别：
    静态多态的函数地址早绑定 - 编译阶段确定函数地址
    动态多态的函数地址晚绑定 - 运行阶段确定函数地址
*/
#include<iostream>
#include<string>
using namespace std;

// 动物类
class Animal
{
public:
    virtual void speak()   // 虚函数实现地址晚绑定
    {
        cout << "动物在说话" << endl;

    }

};
// 猫类
class Cat : public Animal
{
    // 重写——函数返回值类型  函数名 参数列表 完全相同
    virtual void speak()   // 子类中此处的virtual可写可不写
    {
        cout << "小猫在说话" << endl;

    }


};

// 狗类
class Dog : public Animal
{
    void speak()
    {
        cout << "小狗在说话" << endl;

    }


};

// 执行说话的函数
// 地址早绑定，在编译阶段就确定函数地址——即走Animal的地址
// 若想执行让猫说话，那么这个函数的地址就不能提前绑定，需要在运行阶段进行绑定，即地址晚绑定
void DoSpeak(Animal & animal)  // Animal的一个引用 Animal & animal = cat;

// 动态多态的满足条件：
// 1.有继承关系
// 2.子类要重写父类的虚函数

// 动态多态的使用
// 父类的指针或者引用——>执行子类对象    Animal & animal = cat;
{

    animal.speak();  

}

void test1()
{
    Cat cat;
    DoSpeak(cat);

    Dog dog;
    DoSpeak(dog);
}

int main()
{
    test1();

    return 0;
}