/*
注意事项：
    1.自动类型推导，必须推导出一致的数据类型T,才可以使用
    2.模板必须要确定出T的数据类型，才可以使用
*/

#include<string>
#include<iostream>
using namespace std;

template<class T>
void MySwap(T &a,T &b)
{
    T temp = a;
    a = b;
    b = temp;

}

template<class T>
void func()
{
    cout << "func的调用" << endl;

}


void test1()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    // MySwap(a,c);   // 报错,推导出不一致的T类型
    // swapInt(a,b);

    // 利用函数模板进行交换
    // 两种方式使用模板
    MySwap(a,b);

    
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;


}

void test2()
{
    func<int>();

}

int main()
{
    test1();
    test2();
    
    return 0;
}