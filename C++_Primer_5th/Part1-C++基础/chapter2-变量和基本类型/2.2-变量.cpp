// 变量初始化：
#include<iostream>
using namespace std;

// 练习2.9：
    // cin >> int a;   // 错误，输入运算符右边需要一个明确的变量名称而不是定义变量的语句
    // 以下两种方式会引发警告，是不被建议的窄化操作
    // int a = {3.14};
    // int a = 3.14;
    // int a = b = 5;   // 声明多个变量时需要用逗号将变量名隔开，不可以直接用赋值运算符连接

// 练习2.10：
    // 对于string类型的变量，因为string本身接受无参数的初始化方式，所以变量无论在函数内还是函数外均默认初始化为空串
    // int ，函数体外默认定义为0，函数体内将不被初始化，若程序试图拷贝或者输出未初始化的int，将遇到一个未定义的奇异值

// 变量声明：
    extern int i;       // 变量声明
    int i;          // 变量定义


// 嵌套的作用域：
// int reused = 42;
// int main()
// {
//     int unique = 0;
//     cout << reused << endl;

//     int reused = 0;
//     cout << reused << endl;

//     cout << ::reused << "&" << unique << endl;

//     return 0;
// }

// 练习2.14
int main()
{
    int i = 100, sum = 0;

    for (int i = 0; i <10; i++)
    {
        sum += i;
    }

    cout << "i = " << i << " sum = " << sum << endl;
    


    return 0;
}
