// 题目
/*
C语言参数压栈顺序
*/

// 解答
/*
Ｃ程序栈底为高地址，栈顶为低地址，因此下面的实例可以说明函数参数入栈顺序的确是从右至左的。

C方式参数入栈顺序（从右至左）的好处就是可以动态变化参数个数。

通过栈堆分析可知，自左向右的入栈方式，最前面的参数被压在栈底。
除非知道参数个数，否则是无法通过栈指针的相对位移求得最左边的参数。
这样就变成了左边参数的个数不确定，正好和动态参数个数的方向相反。

*/
// 实例

#include<iostream>
using namespace std;

void foo(int x, int y, int z)   // 栈先进后出，所以进栈顺序 300，200，100；出栈即为100，200，300
{
    cout << x << " " << &x << endl;
    cout << y << " " << &y << endl;
    cout << z << " " << &z << endl;
}

int main(int argc, char *argv[])
{
    foo(100, 200, 300);
    return 0;
}

