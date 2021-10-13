#include<iostream>
#include<string>
using namespace std;

// int main()
// {
//     test1();
//     return 0;
//     // return -1;    // 返回值为-1冗长被当作程序错误的标识
// }

// 标准库的四个IO对象：
    // cin  cout为标准输入输出
    // cerr输出警告和错误信息，被称为标准错误  
    // clog输出程序运行时的一般性信息

// 注释相关：

void test1()
{
    // cout << "/*" << endl;
    // cout << "*/" << endl;
    // cout << /* "*/" */<< endl;      // 错误, /* "*/ 被注释掉，后面的内容不完整
    cout << /* "*/   " /* "   /*" */<< endl;      // 正确，输出 /*
}

int test2()
{
    int i = 50, sum = 0;

    while (i>=50 && i<=100)
    {
        sum += i;
        i++;
    }
    
    return sum;
}





// for与while的优缺点：
//     在循环次数已知的情况下，for 循环的形式显然更为简洁。
//     而循环次数无法预知时，用 while 循环实现更适合。
//     用特定条件控制循环是否执行，循环体中执行的语句可能导致循环判定条件发生变化

// 读取数量不定的输入数据

int test3()
{
    int sum = 0, value = 0;

    while (cin >> value)
    {
        sum += value;
    }
    return sum;
}
// 当从键盘向程序输入数据时，从键盘输入文件结束符可以使程序结束。
//     对windows系统是ctrl+z然后enter
//     unix是ctrl+d


int main()
{
    // test1();
    cout << test3() << endl;
    return 0;

}