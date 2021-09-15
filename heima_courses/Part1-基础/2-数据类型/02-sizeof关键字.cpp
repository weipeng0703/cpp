// **作用：**利用sizeof关键字可以统计——数据类型所占内存大小
// 语法： sizeof( 数据类型 / 变量)
// short < int <= long <= long long

#include<iostream>
using namespace std;

int main(){
    // 1.短整型(-32768~32767)
    short num1 = 32768;
    cout << "short所占的内存空间为" << sizeof(short) << endl;
    cout << "num1所占的内存空间为" << sizeof(num1) << endl;
    // 2.整型
    int num2 = 10;
    cout << "int所占的内存空间为" << sizeof(int) << endl;
    cout << "num2所占的内存空间为" << sizeof(num2) << endl;
    // 3.长整型
    long num3 = 10;
    cout << "long所占的内存空间为" << sizeof(long) << endl;
    cout << "num3所占的内存空间为" << sizeof(num3) << endl;
    // 4.长长整型
    long long num4 = 10;
    cout << "long long所占的内存空间为" << sizeof(long long) << endl;
    cout << "num4所占的内存空间为" << sizeof(num4) << endl;

    return 0;
}