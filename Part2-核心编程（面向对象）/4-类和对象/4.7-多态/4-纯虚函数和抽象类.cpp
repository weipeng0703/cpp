/*
在多态中，通常父类中虚函数的实现是毫无意义的，主要都是调用子类重写的内容
因此可以将虚函数改为纯虚函数

纯虚函数语法：virtual 返回值类型 函数名 （参数列表）= 0 ;

当类中有了纯虚函数，这个类也称为抽象类

抽象类特点：
    无法实例化对象
    子类必须重写抽象类中的纯虚函数，否则也属于抽象类
*/
#include<iostream>
#include<string>
using namespace std;

// 只要有一个纯虚函数，此类便被称为抽象类
class Base
{
public:
    // 纯虚函数
    virtual void func() = 0;

};

class Son : public Base
{
private:
    // 子类必须重写抽象类中的纯虚函数，否则也属于抽象类
    virtual void func()
    {
        cout << "抽象类的子类中func()的调用" << endl;
    };

};

void test1()
{
    // Base b;  // 报错，抽象类不允许实例化对象
    // new Base;   // 报错，抽象类不允许实例化对象

    // Son s;

    Base * base = new Son;
    base->func();

}



int main()
{
    test1();
    // test2();

    return 0;
}