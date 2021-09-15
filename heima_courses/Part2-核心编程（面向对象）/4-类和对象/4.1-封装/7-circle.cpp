// 圆类的实现
#include "7-circle.h"

// 圆类

void Circle::SetR(int r) 
{
    m_R = r;
}
// 获取半径
int Circle::GetR() 
{
    return m_R ;
}

// 设置圆心
void Circle::SetCenter(Point center) 
{
    m_Center = center;
}
// 获取圆心
Point Circle::GetCenter() 
{
    return m_Center;
}
