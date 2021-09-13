/*
    函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
    函数对象超出普通函数的概念，函数对象可以有自己的状态
    函数对象可以作为参数传递
*/

#include<iostream>
using namespace std;

class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;

    }

};

// 函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
void test1()
{
    MyAdd myadd;
    cout << myadd(10, 10) << endl;

}

class MyPrint
{
public:
    MyPrint()
    {
        this->count = 0;

    }
    void operator()(string test)
    {
        cout << test << endl;
        this->count++;
    }
    int count;
};

void test2()
{
    MyPrint myprint;
    myprint("hello world");
    myprint("hello world");
    myprint("hello world");
    myprint("hello world");
    cout << "myprint调用的次数：" << myprint.count << endl;
}

// 函数对象可以作为参数传递

void DoPrint(MyPrint &mp, string test)
{

    mp(test);


}
void test3()
{
    MyPrint myprint;
    DoPrint(myprint, "hello C++");

}

int main()
{   
    // test1();
    // test2();
    test3();

    return 0;
}