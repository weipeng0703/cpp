/*
菱形继承概念：
    两个派生类继承同一个基类又有某个类同时继承刚才的两个派生类
    这种继承被称为菱形继承，或者钻石继承

菱形继承问题：
    1.羊继承了动物的数据，驼同样继承了动物的数据，当草泥马使用数据时，就会产生二义性。
    2.草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以。
总结：
菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
利用 虚继承 可以解决菱形继承问题
*/
#include<iostream>
#include<string>
using namespace std;

// 父类
class Animal
{
public:

    int m_Age;
};

// 利用虚继承解决菱形继承的问题
// 加上关键字virtual之后，Animal类变为虚基类
// 子类1
class Sheep : virtual public Animal
{
public:

};

// 子类2
class Camel : virtual public Animal
{
public:

};

// 菱形继承类
class SheepCamal : public Sheep, public Camel
{
public:

};


void test1()
{
    SheepCamal sc;

    // 使用虚继承后，m_Age数据相当于只有一份
    sc.Sheep::m_Age = 18;
    sc.Camel::m_Age = 28;

    // 当菱形继承时，两个父类拥有相同的属性需要加以作用域区分
    cout << "sc.Sheep::m_Age=" << sc.Sheep::m_Age << endl;
    cout << "sc.Camel::m_Age=" << sc.Camel::m_Age << endl;
    cout << sc.m_Age << endl;

    // 但是只有一份数据即可，菱形继承倒导致数据有两份，浪费开销

}

int main()
{
    test1();
    // test2();


    return 0;
}