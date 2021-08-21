/*
设计一个圆形类（Circle），和一个点类（Point），计算点和圆的关系。
*/
#include<iostream>
#include<string>
#include<7-point.h>
#include<7-circle.h>
using namespace std;


// 判断点和圆的关系的函数
void Val(Point &p, Circle &c)
{
    // 计算两点之间距离的平方和半径的平方
    int P_dis = 
    (c.GetCenter().GetX() - p.GetX()) * (c.GetCenter().GetX() - p.GetX()) +
    (c.GetCenter().GetY() - p.GetY()) * (c.GetCenter().GetY() - p.GetY());

    int r_dis = c.GetR() * c.GetR();

    if (P_dis == r_dis)
    {
        cout << "点在圆上" << endl;
    }
    else if (P_dis > r_dis)
    {
        cout << "点在圆外" << endl;
    }
    else if (P_dis < r_dis)
    {
        cout << "点在圆内" << endl;
    }
    
}


int main()
{
    // 创建圆
    Circle c;
    c.SetR(10);
    Point center;
    center.SetX(10);
    center.SetX(0);
    c.SetCenter(center);

    // 创建点类
    Point p;
    p.SetX(10);
    p.SetY(10);

    Val(p,c);

    return 0;
}