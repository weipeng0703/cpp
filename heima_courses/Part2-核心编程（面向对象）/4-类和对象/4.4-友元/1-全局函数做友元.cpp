/*
生活中你的家有客厅(Public)，有你的卧室(Private)

    客厅所有来的客人都可以进去，但是你的卧室是私有的，也就是说只有你能进去
    但是呢，你也可以允许你的好闺蜜好基友进去。
    在程序里，有些私有属性 也想让类外特殊的一些函数或者类进行访问，就需要用到友元的技术

友元的目的——————就是让一个函数或者类 访问另一个类中私有成员

友元的关键字为 friend

友元的三种实现

    全局函数做友元
    类做友元
    成员函数做友元
*/
#include<iostream>
#include<string>
using namespace std;

// 建筑物类
class Building
{
    // GoodGay()全局函数是 Building 类的好朋友，可以访问Building类内的私有成员
    friend void GoodGay(Building *building);

public:
    Building()
    {
        m_SittingRoom = "客厅";
        m_BedRoom = "卧室";

    }

public:
    string m_SittingRoom;   // 客厅

private:
    string m_BedRoom;   // 卧室


};

// 全局函数
void GoodGay(Building *building)
{   
    cout << "好基友正在访问：" << building->m_SittingRoom << endl;

    cout << "好基友正在访问：" << building->m_BedRoom << endl;

}

void test1()
{
    Building building1;
    GoodGay(&building1);


}
int main()
{
    test1();

    return 0;
}