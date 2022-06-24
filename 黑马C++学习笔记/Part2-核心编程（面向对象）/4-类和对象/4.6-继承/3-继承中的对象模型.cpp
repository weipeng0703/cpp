/*
**问题：**从父类继承过来的成员，哪些属于子类对象中？

结论： 父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到

使用开发人员命令提示符查看类的分布：进入文件所在的文件夹 
之后使用命令     cl /d1 reportSigleClassLayoutSon 文件名.cpp
*/
#include<iostream>
#include<string>
using namespace std;

class Base1
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};

class son : public Base1
{
public:
    int m_D;

};

void test1()
{
    // 父类中所有非静态成员属性都会被子类继承下去
    // 父类中私有成员属性是呗编译器隐藏了，因此访问不到，但是确实被继承下去了
    cout << "Size of son is " << sizeof(son) << endl;

}

int main()
{
    test1();
    // test2();
    // test3();

    return 0;
}