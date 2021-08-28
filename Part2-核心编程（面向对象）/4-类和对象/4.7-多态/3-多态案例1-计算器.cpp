/*
分别利用普通写法和多态技术，设计实现两个操作数进行运算的计算器类

多态的优点：
    代码组织结构清晰
    可读性强
    利于前期和后期的扩展以及维护
*/
#include<iostream>
#include<string>
using namespace std;

// // 利用普通写法
// class Calculator1
// {
// public:

//     int GetResult(string oper)
//     {
//         if (oper == "+")
//         {
//             return m_Num1 + m_Num2 ;
//         }
//         else if (oper == "-")
//         {
//             return m_Num1 - m_Num2 ;
//         }
//         else if (oper == "*")
//         {
//             return m_Num1 * m_Num2 ;
//         }
//         else if (oper == "/")
//         {
//             return m_Num1 / m_Num2 ;
//         }

//         // 若想拓展新的功能，需要修改源码
//         // 开发中一个原则——开闭原则：对扩展进行开发，对修改进行关闭
        
//     }

//     int m_Num1;
//     int m_Num2;


// };

// void test1()
// {
//     Calculator1 c;
//     c.m_Num1 = 10;
//     c.m_Num2 = 20;

//     cout << "num1 + num2 = " << c.GetResult("+") << endl;
//     cout << "num1 - num2 = " << c.GetResult("-") << endl;
//     cout << "num1 * num2 = " << c.GetResult("*") << endl;
//     cout << "num1 / num2 = " << c.GetResult("/") << endl;

// }   

// 利用多态实现计算器
class calculator2
{
public:
    virtual int GetResult()
    {
        return 0;
    }

    int m_Num1;
    int m_Num2;

};

// 加法计算器子类
class Add : public calculator2
{
public:
    int GetResult()
    {
        return m_Num1 + m_Num2;
    }

};

// 减法计算器子类
class Sub : public calculator2
{
public:
    int GetResult()
    {
        return m_Num1 - m_Num2;
    }

};

// 乘法计算器子类
class Multi : public calculator2
{
public:
    int GetResult()
    {
        return m_Num1 * m_Num2;
    }

};

// 除法计算器子类
class Divide : public calculator2
{
public:
    int GetResult()
    {
        return m_Num1 / m_Num2;
    }

};

void test2()
{
    // 多态的使用条件：父类的指针或引用指向子类对象
    calculator2 * abc = new Add;

    abc->m_Num1 = 10;
    abc->m_Num2 = 20;

    cout << abc->m_Num1 << "+" << abc->m_Num2 << "=" << abc->GetResult() << endl;
    // 用完后记得销毁
    delete abc;

    abc = new Sub;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->m_Num1 << "-" << abc->m_Num2 << "=" << abc->GetResult() << endl;
    // 用完后记得销毁
    delete abc;

    abc = new Multi;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->m_Num1 << "*" << abc->m_Num2 << "=" << abc->GetResult() << endl;
    // 用完后记得销毁
    delete abc;

    abc = new Divide;
    abc->m_Num1 = 10;
    abc->m_Num2 = 20;
    cout << abc->m_Num1 << "/" << abc->m_Num2 << "=" << abc->GetResult() << endl;
    // 用完后记得销毁
    delete abc;

}


int main()
{
    // test1();
    test2();

    return 0;
}