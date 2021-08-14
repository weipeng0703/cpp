/*
**作用：**用于根据表达式的值返回真值或假值

逻辑运算符有以下符号：

运算符	术语	    示例	                     结果
!	    非	        !a	        如果a为假，则!a为真； 如果a为真，则!a为假。
&&	    与	      a && b	    如果a和b都为真，则结果为真，否则为假。
||	    或	      a || b	    如果a和b有一个为真，则结果为真，二者都为假时，结果为假。

*/
#include<iostream>
using namespace std;

int main(){

    // 1.非
    // int a = 0;

    // cout << a << endl;
    // cout << !a << endl;

    // 2.与

    // int a = 10;
    // int b = 0;

    // cout << (a && b) << endl;

    // 3.或

    int a = 0;
    int b = 0;

    cout << (a || b) << endl;


    return 0;
}