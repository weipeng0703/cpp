/*
作用： 通过重载递增运算符，实现自己的整型数据.前置递增返回引用，后置递增返回值
递减运算符类似.
*/
#include<iostream>
#include<string>
using namespace std;

class MyInteger
{
    friend ostream& operator<<(ostream&cout, MyInteger myint);
public:
    MyInteger()
    {
        m_Num = 10;

    }
    // 重载前置++运算符
    MyInteger& operator++()   // 返回引用是为了一直对同一个数据进行++操作
    {
        m_Num++;
        return *this;   // 解引用自身
    }
    // 重载后置++运算符
    MyInteger operator++(int)  // int代表占位参数,可以用于区分前置和后置递增
    {
        // 先记录临时结果
        MyInteger temp = *this;
        // 后递增
        m_Num++;
        // 最后返回临时结果
        return temp;
    }
private:
    int m_Num;
};

// 重载左移运算符
ostream& operator<<(ostream&cout, MyInteger myint)
{
    cout << myint.m_Num;
    return cout;

}


void test1()
{
    MyInteger myint;

    cout << ++myint << endl;

}

void test2()
{
    MyInteger myint;

    cout << myint++ << endl;
    cout << myint << endl;

}

int main()
{
    // test1();
    test2();

    return 0;
}