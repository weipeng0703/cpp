/*
在C++中 struct和class唯一的区别就在于 默认的访问权限不同

区别：

struct  默认权限为公共  public
class   默认权限为私有  private
*/
#include<iostream>
#include<string>
using namespace std;

class C1
{
    int m_A;   // 默认权限（即在成员属性前什么关键字也不写）是私有
};
struct C2
{
    int m_B;  // 默认权限是公共
};

int main()
{
    // C1 c1;
    // c1.m_A = 100;   // 默认权限是私有,因此类外不可以访问

    C2 c2;
    c2.m_B = 100;   // 默认权限是公共,因此类外可以访问
    return 0;
}

