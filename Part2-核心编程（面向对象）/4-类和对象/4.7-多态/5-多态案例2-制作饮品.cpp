/*
制作饮品的大致流程为：煮水 - 冲泡 - 倒入杯中 - 加入辅料

利用多态技术实现本案例，提供抽象制作饮品基类，提供子类制作咖啡和茶叶
*/
#include<iostream>
#include<string>
using namespace std;

class AbstractDrink
{
public:
    // 煮水
    virtual void Boil() = 0;

    // 冲泡
    virtual void Brew() = 0;

    // 倒入杯中
    virtual void PourIn() = 0;

    // 导入辅料
    virtual void PutElse() = 0;

    // 制作饮料
    void MakeDrink()
    {
        Boil();
        Brew();
        PourIn();
        PutElse();

    }


};

// 咖啡类
class Coffee : public AbstractDrink
{
public:
    // 煮水
    virtual void Boil()
    {
        cout << "现在正在煮水" << endl; 

    } ;

    // 冲泡
    virtual void Brew()
    {
        cout << "现在正在冲泡" << endl;
        
    } ;

    // 倒入杯中
    virtual void PourIn()
    {
        cout << "将咖啡倒入杯中" << endl;
        
    } ;

    // 倒入辅料
    virtual void PutElse()
    {
        cout << "倒入辅料" << endl;
        
    } ;



};

// c茶叶类
class Tea : public AbstractDrink
{
public:
    // 煮水
    virtual void Boil()
    {
        cout << "现在正在煮水" << endl; 

    } ;

    // 冲泡
    virtual void Brew()
    {
        cout << "现在正在冲泡" << endl;
        
    } ;

    // 倒入杯中
    virtual void PourIn()
    {
        cout << "将茶叶倒入杯中" << endl;
        
    } ;

    // 倒入辅料
    virtual void PutElse()
    {
        cout << "倒入辅料" << endl;
        
    } ;



};

// 制作
// 形参接收实参时  AbstractDrink * abs = new Coffee;
// 父类指针指向子类对象，调用父类中的MakeDrink（），
// 其里面的调用是去子类中寻找具体的实现，因为子类中做了重写的操作
void DoWork(AbstractDrink * abs)
{
    abs->MakeDrink();
    delete abs;    // 防止堆区数据内存泄漏
}


void test1()
{
    // 制作咖啡

    DoWork(new Coffee);

    cout << "----------" << endl;

    // 制作茶叶

    DoWork(new Tea);

}

int main()
{
    test1();

    return 0;
}