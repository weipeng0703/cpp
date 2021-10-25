// 题目
/*
给定三角形ABC和一点P(x,y,z)，判断点P是否在ABC内，给出思路并手写代码
*/

// 解答
/*
根据面积法，如果P在三角形ABC内，那么三角形ABP的面积+三角形BCP的面积+三角形ACP的面积应该等于三角形ABC的面积。

*/

#include <iostream>
#include <math.h>
using namespace std;
#define ABS_FLOAT_0 0.0001

struct point_float
{
    float x;
    float y;
};

// 计算三角形面积
float GetTriangleSquar(const point_float pt0, const point_float pt1, const point_float pt2)
{
    point_float AB, BC;
    AB.x = pt1.x - pt0.x;
    AB.y = pt1.y - pt0.y;
    BC.x = pt2.x - pt1.x;
    BC.y = pt2.y - pt1.y;
    return fabs((AB.x * BC.y - AB.y * BC.x)) / 2.0f;
}

// 判断
bool IsInTriangle(const point_float A, const point_float B, const point_float C, const point_float D)
{
    float SABC, SADB, SBDC, SADC;
    SABC = GetTriangleSquar(A, B, C);
    SADB = GetTriangleSquar(A, D, B);
    SBDC = GetTriangleSquar(B, D, C);
    SADC = GetTriangleSquar(A, D, C);

    float SumSuqar = SADB + SBDC + SADC;
    
    if ((-ABS_FLOAT_0 < (SABC - SumSuqar)) && ((SABC - SumSuqar) < ABS_FLOAT_0))
        {
            return true;
        }
        
        else
        {
            return false;
        }
}

int main()
{
    // 三角形
    point_float p1{0,0};
    point_float p2{2,0};
    point_float p3{0,2};

    // 测试点
    // point_float p_test{1,1};    
    point_float p_test{10,10};

    bool flag = IsInTriangle(p1, p2, p3, p_test);
    if (flag == 1)
    {
        cout << "测试点在三角形内" << endl;
    }
    else
    {
        cout << "测试点不在三角形内" << endl;
    }    
    return 0;
}
// 知识点
/*

*/