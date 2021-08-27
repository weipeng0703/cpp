/*
继承的语法：class 子类 : 继承方式 父类

继承方式一共有三种：

    公共继承
    保护继承
    私有继承
*/
#include<iostream>
#include<string>
using namespace std;

// 公共继承
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
    void func()
    {
        m_A = 10;   // 父类中的公共权限成员依然是公共权限
        m_B = 10;   // 父类中的保护权限成员依然是保护权限
        // m_C= 10；   // 父类中的私有权限成员子类访问不到
    }

};

void test1()
{
    son son1;
    son1.m_A = 100;
    // son1.m_B = 200;    // son1中m_B是一个保护权限成员，类外访问不到
 
}


// 保护继承
class Base2
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};


class son2 : protected Base2
{
public:
    void func()
    {
        m_A = 10;       // 父类中的公共权限成员,到子类中变为保护权限
        m_B = 10;       // 父类中的保护权限成员依然是保护权限
        // m_C= 10；    // 父类中的私有权限成员子类访问不到
    }

};

void test2()
{
    son2 son1;
    // son1.m_A = 100;       // son1中m_B是一个保护权限成员，类外访问不到
    // son1.m_B = 200;       // son1中m_B是一个保护权限成员，类外访问不到
 
}

// 私有继承
class Base3
{
public:
    int m_A;
protected:
    int m_B;
private:
    int m_C;
};


class son3 : private Base3
{
public:
    void func()
    {
        m_A = 10;       // 父类中的公共权限成员,到子类中变为私有权限
        m_B = 10;       // 父类中的保护权限成员，到子类中变为私有权限
        // m_C= 10；    // 父类中的私有权限成员子类访问不到
    }

};

void test3()
{
    son3 son1;
    // son1.m_A = 100;       // son1中m_B是一个私有权限成员，类外访问不到
    // son1.m_B = 200;       // son1中m_B是一个私有权限成员，类外访问不到
 
}

class GrandSon : public son3
{
public:
    void func()
    {
        // 因为m_A,m_B由Base3继承到son3中后均变为private，所以GrandSon就算公共继承Son3，其成员也均变为私有
        // m_A = 1000;
        // m_B = 1000;

    }
};



int main()
{
    test1();
    test2();
    test3();

    return 0;
}