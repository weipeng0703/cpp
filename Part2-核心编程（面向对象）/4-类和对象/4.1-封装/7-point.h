// 点类的声明
#pragma once
#include<iostream>
using namespace std;

// 点类
class Point
{
private:
    int m_X;
    int m_Y;
public:
    // 设置x坐标
    void SetX(int x);

    // 获取x坐标
    int GetX(); 

    
    // 设置y坐标
    void SetY(int x); 


    // 获取y坐标
    int GetY(); 

};