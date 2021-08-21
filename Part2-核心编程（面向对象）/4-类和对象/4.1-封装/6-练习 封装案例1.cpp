/*
设计立方体类(Cube)

求出立方体的面积和体积

分别用全局函数和成员函数判断两个立方体是否相等。
*/
#include<iostream>
#include<string>
using namespace std;

class Cube
{
private:
    int m_long;
    int m_width;
    int m_high;
public:
    // 长
    void SetLong(int l) 
    {
        m_long = l;
    }
    int GetLong() 
    {
        return m_long;
    }
    // 宽
    void SetWidth(int w) 
    {
        m_width = w;
    }
    int GetWidth() 
    {
        return m_width;
    }
    // 高
    void SetHigh(int h) 
    {
        m_high = h;
    }
    int GetHigh() 
    {
        return m_high;
    }

    // 计算表面积
    int GetS()
    {
        return 2 * (m_high * m_long + m_high * m_width + m_width * m_long);
    }

    // 计算体积
    int GetV()
    {
        return m_high * m_long * m_width;
    }

    // 利用成员函数判断两个立方体是否相等

    // 因为类已经定义好了一个对象，所以只需传入另一个待比较的立方体比较即可
    bool IsSame(Cube &c)   
    {
        if (m_long == c.GetLong() && m_width == c.GetWidth() && m_high == c.GetHigh() )
            {
                return true;
            }
        else
            {
                return false;
            }
    }
};

// 利用全局函数判断两个立方体是否相等
bool IsSame(Cube &c1, Cube &c2)   // 利用引用做参数，不需要再拷贝两份数据
{
    if (c1.GetLong() == c2.GetLong() && c1.GetWidth() == c2.GetWidth() && 
        c1.GetHigh() == c2.GetHigh() )
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
    // 创建立方体对象c1
    Cube c1;
    c1.SetLong(10);
    c1.SetHigh(10);
    c1.SetWidth(10);
    
    // 需求1
    cout << "立方体的表面积为：" << c1.GetS() << endl;
    cout << "立方体的体积为：" << c1.GetV() << endl;

    // 创建立方体对象c2
    Cube c2;
    c2.SetLong(11);
    c2.SetHigh(10);
    c2.SetWidth(10);

    // 利用全局函数判断
    bool flag = IsSame(c1, c2);   // 需要传入两个立方体

    if (flag == true)
    {
        cout << "全局函数判断：两个立方体相同" << endl;
    }
    else
    {
        cout << "全局函数判断：两个立方体不相同" << endl;
    }

    // 利用成员函数判断
    bool flag1 = c1.IsSame(c2);   // 只需要传入一个另外的立方体进行对比

    if (flag == true)
    {
        cout << "成员函数判断：两个立方体相同" << endl;
    }
    else
    {
        cout << "成员函数判断：两个立方体不相同" << endl;
    }

    return 0;
}