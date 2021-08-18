// **作用：用于表示小数
// 浮点型变量分为两种：

// 单精度float
// 双精度double
// 两者的区别在于表示的有效数字范围不同。

// 数据类型	   占用空间	     有效数字范围
// float	    4字节	    7位有效数字
// double	    8字节	    15～16位有效数字

#include<iostream>
using namespace std;

int main(){

    // 1.单精度  float    
    //若不加f，编译器看到小数点会默认数据类型为double，后面加f会自动默认3.14为float
    float f1 = 3.14f;
    cout << "f1=" << f1 <<endl;
    cout << "f1内存空间大小为" << sizeof(f1) <<endl;  //4个字节

    // 2.双精度  double
    double d1 = 3.14;
    cout << "d1=" << d1 <<endl;
    cout << "d1内存空间大小为" << sizeof(d1) <<endl;   //8个字节
    
    // C++中如果输出小数，默认显示6位有效数字，超过的需要额外配置
    float f2 = 3.1415926f;
    cout << "f2=" << f2 <<endl;

    double d2 = 3.1415926;
    cout << "d2=" << d2 <<endl;

    // 科学计数法
    float f3 = 3e2; //3*10^2
    cout << "f3=" << f3 <<endl;

    float f4 = 3e-2; //3*10^-2
    cout << "f4=" << f4 <<endl;

    
    return 0;
}