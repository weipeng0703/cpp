// 作用：用于处理四则运算
// + - * / % a++ ++a a-- --a

#include<iostream>
using namespace std;

int main(){

/*
    // 1.加减乘除

    int a = 10, b = 3;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;   // 两个整数相除，结果仍然是整数，去除小数部分

    //两个小数可以相除，并且结果可以是小数

	double d1 = 0.5;
	double d2 = 0.21;
	cout << d1 / d2 << endl;

    // 2.取模运算，即取余    只有整数才可以取模运算

    int a1 = 10;
	int b1 = 3;

	cout << 10 % 3 << endl;

    int a2 = 10;
	int b2 = 20;

	cout << a2 % b2 << endl;      //当对一个比自身大的数取模，结果即为其自身

    int a3 = 10;
	int b3 = 0;

	cout << a3 % b3 << endl;      //不能对0取模

    
	double d1 = 3.14;
	double d2 = 1.1;

	//cout << d1 % d2 << endl;      //两个小数不可以取模

*/

    // 3.（前置/后置）递增/递减

    int a = 10;
    ++a;      //前置递增，让变量加1
    cout << "a=" << a << endl;

    int b = 10;
    b++;      //后置递增，让变量加1
    cout << "b=" << b << endl;

    //区别
	//前置递增先对变量进行++，再计算表达式

    int a2 = 10;
    int b2 = ++a2 * 10;
    cout << "a2=" << a2 <<endl;   //11
    cout << "b2=" << b2 <<endl;   //110

    //后置递增先计算表达式，后对变量进行++

    int a3 = 10;
    int b3 = a3++ * 10;
    cout << "a3=" << a3 <<endl;   // 11
    cout << "b3=" << b3 <<endl;   // 100

    int a4 = 10;
    int b4 = --a4 * 10;
    cout << a4 <<endl;
    cout << b4 <<endl;

    int a5 = 10;
    int b5 = a5-- * 10;
    cout << a5 <<endl;
    cout << b5 <<endl;

    return 0;
}