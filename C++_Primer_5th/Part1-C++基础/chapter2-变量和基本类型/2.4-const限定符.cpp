#include<iostream>
using namespace std;

const int buffersize = 512;

// buffersize = 1024;  // 错误，试图向const对象写值

// const对象一旦创建后其值就不能更改，所以const对象必须初始化

// 初始化和const

    // 默认状态下，const仅在文件内有效

    // 如果需要只在一个文件中定义const而在其他多个文件中声明并使用它，对const声明不管是声明还是定义都添加extern关键字
    extern const int buff  = 32;   // 在.cc文件中定义并初始化

    extern const int buff;    // 在.h头文件中声明

// 2.4.1 const的引用（常量引用）
    const int ci = 0;
    const int &r1 = ci;

    // r1 = 42;    // 错误，r1是对常量的引用，常量不能修改
    // int &r2 = c1;   // 错误，试图让一个非常亮引用指向一个常量对象


    // 初始化和对const的引用
    int i = 42;

    const int &r1 = i;      // 允许将const int& 绑定到一个普通的int身上


    double dval = 3.14;      const int &ri = dval;    // 正确的
    // 编译器将上述代码转换为：
    const int temp = dval;    const int &ri = temp;    // 使ri绑定temp这个临时量



// 2.4.2 指针和const

    // 指向常量的指针不能用于改变其所指对象的值。要想存放常量对象的地址，只能使用指向常量的指针

    
    // const指针

        // 常量指针
        // 必须初始化，且一旦初始化完成，则他的值（存放在指针中的那个地址）就不能再改变了
        // 把*放在const关键字之前用以说明指针是一个常量，不变的是指针本身的值而不是指向的那个值

        int num = 0;
        int *const curnum = &num;    // curnum将一直指向num


// 2.4.3 顶层const