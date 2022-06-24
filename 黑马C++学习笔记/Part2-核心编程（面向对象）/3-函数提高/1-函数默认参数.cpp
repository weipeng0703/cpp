#include<iostream>
#include<string>
using namespace std;

//1. 如果某个位置参数有默认值，那么从这个位置往后，从左向右，必须都要有默认值
int func(int a, int b = 10, int c = 10) {
	return a + b + c;
}

// int func1(int a, int b = 10, int c) {   // 语法错误
// 	return a + b + c;
// }

//2. 如果函数声明有默认值，函数实现的时候就不能有默认参数
//   即声明与定义中只能有一处有默认参数
int func2(int a = 10, int b = 10);
int func2(int a, int b) {
	return a + b;
}

int func3(int a = 10, int b = 10);
int func3(int a = 20, int b= 20)   // 防止出现这样的二义性错误 
{
	return a + b;
}

int main() {

	cout << "ret = " << func(20, 20, 20) << endl;
    cout << "ret = " << func2(20, 20) << endl;
    cout << "ret = " << func3(20, 20) << endl;   // 报错

	return 0;
}
