// 题目
/*
栈溢出问题
*/

// 解答
/*
栈溢出概念：
    栈溢出指的是程序向栈中某个变量中写入的字节数超过了这个变量本身所申请的字节数，因而导致栈中与其相邻的变量的值被改变。

栈溢出的原因：

    1. 局部数组过大。当函数内部的数组过大时，有可能导致堆栈溢出。
    局部变量是存储在栈中的，因此这个很好理解。
    解决这类问题的办法有两个，一是增大栈空间,二是改用动态分配，使用堆（heap）而不是栈（stack）。

    2. 递归调用层次太多。递归函数在运行时会执行压栈操作，当压栈次数太多时，也会导致堆栈溢出。

    3. 指针或数组越界。这种情况最常见，例如进行字符串拷贝，或处理用户输入等等。


*/

// 栈溢出例子：

#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[]) 
{
    char buf[256];
    strcpy(buf,argv[1]);    // 缓冲区溢出错误，因为源缓冲区内容是用户输入的。
    printf("Input:%s\n",buf);
    return 0;
}
