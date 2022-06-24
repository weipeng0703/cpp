/*
3.3 比较运算符
**作用：**用于表达式的比较，并返回一个真值或假值

比较运算符有以下符号：

运算符	术语	    示例	结果
==	   相等于	  4 == 3	0
!=	   不等于	  4 != 3	1
<	   小于	      4 < 3	    0
>	   大于	      4 > 3	    1
<=	   小于等于	  4 <= 3	0
>=	   大于等于	  4 >= 1	1

*/
#include<iostream>
using namespace std;

int main(){

    int a = 10;
    int b = 20;

    cout << (a == b) << endl;
    cout << (a != b) << endl;
    cout << (a > b) << endl;
    cout << (a < b) << endl;
    cout << (a <= b) << endl;
    cout << (a >= b) << endl;
    
    return 0;
}