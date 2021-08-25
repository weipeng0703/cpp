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

    void visit();   // 参观函数，用于访问Building类内的属性

    Building * building;

};

class Building
{
    // GoodGay类是本类的好朋友，可以访问本类的私有属性
    friend class GoodGay;
public:
    Building();
public:
    string m_SittingRoom;    // 客厅


private:
    string m_BedRoom;       // 卧室

};

// 类外写成员函数

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
    cout << "好基友类正在访问" << building->m_SittingRoom << endl;

    cout << "好基友类正在访问" << building->m_BedRoom << endl;

}

void test1()
{
    GoodGay gg;
    gg.visit();

}


int main()
{
    test1();

    return 0;
}