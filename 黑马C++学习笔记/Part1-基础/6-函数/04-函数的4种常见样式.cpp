/*
常见的函数样式有4种

1.无参无返
2.有参无返
3.无参有返
4.有参有返
*/

#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

// 1.无参无返
void test1()
{
    cout << "this is test1" <<endl;
}

// 2.有参无返
void test2(int a)
{
    cout << "this is test2,a=" << a <<endl;
}

// 3.无参有返
int test3()
{
    cout << "this is test3" << endl;
    return 1000;
}

// 4.有参有返
int test4(int num1, int num2)   // 函数定义时，num1与num2并无真实数据，称为形参
{
    cout << "this is test4" << endl;
    int sum = num1 + num2;
    return sum;
}


int main()
{
    test1();

    test2(100);

    int num3 = test3();
    cout << "num3=" << num3 << endl;

    int num4 = test4(10,20);
    cout << "num4=" << num4 << endl;

    return 0;
}