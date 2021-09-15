// 圆类的声明
#pragma once
#include<iostream>
#include<7-point.h>
using namespace std;

// 圆类
class Circle
{
private:
    int m_R;
    // 在一个类中，可以让另一个类作为本类的成员
    Point m_Center;    // 注意，点类一定要在之前写，否则此处不知道m_Center的类型
public:
    // 设置半径
    void SetR(int r); 

    // 获取半径
    int GetR(); 


    // 设置圆心
    void SetCenter(Point center); 

    // 获取圆心
    Point GetCenter(); 

    
};