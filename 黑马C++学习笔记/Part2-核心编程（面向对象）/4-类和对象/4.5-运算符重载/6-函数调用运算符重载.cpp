/*
1.函数调用运算符 () 也可以重载
2.由于重载后使用的方式非常像函数的调用，因此称为仿函数
3.仿函数没有固定写法，非常灵活
*/
#include<iostream>
#include<string>
using namespace std;

class MyPrint
{
public:
    // 重载函数调用运算符
    void operator()(string test)
    {
        cout << test << endl;

    }

};

class MyAdd
{
public:
    int operator()(int num1, int num2)
    {
        return num1 + num2;

    }

};

void test1()
{
    MyPrint myprint;

    myprint("hello world");

}

void test3()
{
    MyAdd myadd;

    int num = myadd(10, 1);
    cout << num << endl;

    // 匿名仿函数对象,就类似上面的类中创建一个对象并进行初始化。
    // 匿名对象用完即释放
    cout << MyAdd()(10,1) << endl;
}

// 函数调用
void test2(string test)
{
    cout << test << endl;  

}


int main()
{
    test1();
    test2("hello world");
    test3();

    return 0;
}