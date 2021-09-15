/*
目的——让一个类可以访问另一个类的私有成员
*/
#include<iostream>
#include<string>
using namespace std;

class Building;

class GoodGay
{
public:
    GoodGay();

    void visit();   // 参观函数，用于访问Building中私有的成员
    void visit2();   // 让visit2函数不能访问Building中私有的成员

    Building * building;

};

class Building
{
    // 告诉编译器，GoodGay类下的visit函数作为本类的好朋友，可以访问本类内的私有属性
    friend void GoodGay::visit();
public:
    Building();  // 构造函数的声明
public:
    string m_SittingRoom;    // 客厅

private:
    string m_BedRoom;       // 卧室

};

// 类外实现成员函数

Building::Building()
{
    m_SittingRoom = "客厅";
    m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
    // 创建一个建筑物的对象
    building = new Building;

}

void GoodGay::visit()
{
    cout << "visit函数正在访问" << building->m_SittingRoom << endl;

    cout << "visit函数正在访问" << building->m_BedRoom << endl;

}      
void GoodGay::visit2()  
{
    cout << "visit2函数正在访问" << building->m_SittingRoom << endl;

    // cout << "visit2函数正在访问" << building->m_BedRoom << endl;

}


void test1()
{
    GoodGay gg;
    gg.visit();
    gg.visit2();
}


int main()
{
    test1();

    return 0;
}