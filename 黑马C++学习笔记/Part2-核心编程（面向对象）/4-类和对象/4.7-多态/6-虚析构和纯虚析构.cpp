/*
多态使用时，如果子类中有属性开辟到堆区，那么父类指针在释放时无法调用到子类的析构代码

解决方式：将父类中的析构函数改为虚析构或者纯虚析构

虚析构和纯虚析构共性：
    可以解决父类指针释放子类对象
    都需要有具体的函数实现

虚析构和纯虚析构区别：
    如果是纯虚析构，该类属于抽象类，无法实例化对象

虚析构语法：
    virtual ~类名(){}

纯虚析构语法：
    virtual ~类名() = 0;
    类名::~类名(){}

总结：
    ​ 1. 虚析构或纯虚析构就是用来解决通过父类指针释放子类对象
    ​ 2. 如果子类中没有堆区数据，可以不写为虚析构或纯虚析构
    ​ 3. 拥有纯虚析构函数的类也属于抽象类
*/
#include<iostream>
#include<string>
using namespace std;

class Animal
{
public:

    Animal()
    {
        cout << "Animal的默认构造函数调用" << endl;
    }

    // 利用父类的虚析构可以解决父类指针释放子类对象时不干净的问题
    // virtual ~Animal()
    // {
    //     cout << "Animal的(虚)析构函数调用" << endl;
    // }

    // 纯虚析构:解决父类属性开辟到堆区的释放问题
    // 其需要声明也需要代码的实现
    // 有了纯虚函数之后,这个类也属于抽象类,无法实例化对象
    virtual ~Animal() = 0;

    // 纯虚函数
    virtual void speak() = 0;


};

// Animal纯虚析构代码的实现
Animal:: ~Animal()
{
    cout << "Animal的纯虚析构函数调用" << endl;

}

class Cat : public Animal
{
public:
    // 默认构造函数
    Cat(string name)
    {
        cout << "Cat的默认构造函数调用" << endl;
        m_Name = new string(name);

    }

    // 析构函数
    ~Cat()
    {
        if (m_Name != NULL)
        {
            cout << "Cat的析构函数调用" << endl;
            delete m_Name;
            m_Name = NULL;
        }
        

    }

    virtual void speak()
    {
        cout << *m_Name <<"小猫在说话" << endl;
    }

    string *m_Name;
};

void test1()
{
    Animal * animal = new Cat("Tom");
    animal->speak();
    // 父类指针在析构时,不会调用子类中的析构函数,导致子类如果有堆区数据会出现内存泄漏
    // 解决方式:将父类的析构改为虚析构
    delete animal;


}

int main()
{
    test1();

    return 0;
}