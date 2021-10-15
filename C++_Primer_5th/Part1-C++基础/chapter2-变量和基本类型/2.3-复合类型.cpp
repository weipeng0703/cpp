// 2.3.1 引用
#include<iostream>
using namespace std;

/*
C++11标准新增了一个右值引用，主要用于内置类
通常我们说的引用都是左值引用
*/

// 引用（reference）为对象起了另外一个名字，引用类型引用（refers to）另外一种类型。
// 通过将声明符写成&d的形式来定义引用类型，其中 d是声明的变量名

int val = 1024;
int &refval = val;   // refval指向val（是val的另一个名字）
// int &refval2;        // 错误，引用必须被初始化

// 一般在初始化变量时，初始值会被拷贝到新建的对象中。
// 然而定义引用时，程序把引用和它的初始值绑定（bind）在一起，而不是将初始值拷贝给引用。
// 一旦初始化完成，引用将和它的初始值对象一直绑定在一起。
// 因为无法令引用重新绑定到另外一个对象，因此引用必须初始化。

// 引用即别名

// 引用并非对象，相反，它只是为已有的对象新起另一个名字

// refval = 2;       // 为啥错误？    将2赋值给refval指向的对象，即val
int ii = refval;  // 与ii = val执行结果一样

int &refval3 = refval;

int i = refval;  // 利用与refval绑定的对象的值初始化变量i


// 引用的定义

// 引用只能绑定在对象身上，不能与字面值或某个表达式的计算结果绑定在一起



// 2.3.2指针
// 指针与引用的不同：
//     1.指针本身是一个对象，允许对其赋值和拷贝，而且其生命周期内可以先后指向几个不同的对象
//     2.指针无须在定义时赋初值，与内置类型一样，在块作用域内定义的指针如果没有被初始化也将拥有一个不确定的值

// 1.获取对象的地址
int val = 42;
int *p = &val;   // 指针p存放变量ival的地址

// 2.指针值
    // 指针的值应属于下列四种状态之一：
    // 1.指向一个对象。
    // 2.指向紧邻对象所占空间的下一个位置。    有效但不建议使用
    // 3.空指针，意味着指针没有指向任何对象。  有效但不建议使用
    // 4.无效指针，也就是上述情况之外的其他值。 编译器并不检查此类错误

// 试图拷贝或以其他方式访问无效指针的值都将引发错误

// 3.利用指针访问对象
int val = 42;
int *a = &val;

// cout << *a;   // 输出42

int *a = 0;
// cout << *a;  // 输出0 


// 4.空指针
int *p1 = nullptr;   // 可以被转换为任意其他的指针类型
int *p2 = 0;
int *p2 = NULL; 

// 建议初始化所有指针



// 5.赋值和指针
// 想搞清楚一条赋值语句改变了指针的值还是改变了指针所指对象的值，最好的办法是——赋值永远改变的是等号左侧的对象

// p = &val;   // p的值被改变,现在p指向val
// *p = 0;     // val的值被改变,指针p并没变

// 6.其他指针的操作

// 7. void* 指针
// 一种特殊的指针类型,可以存放任意对象的地址



// 2.3.3理解复合类型的声明

// 1.定义多个变量
// 涉及指针或引用的声明一般有两种写法：
//     1.修饰符与变量标识符写在一起，强调变量具有的复合类型
//     int *p1, *p2;
//     2.修饰符与类型名写在一起，并且每条语句只定义一个变量，强调本次声明定义了一个复合类型
//     int* p1;


// 2.指向指针的指针
int val = 1024;
int *p1 = &val;
int **p2 = &p1;

// 此时 val、*p1、**p2均代表val的值

// 3.指向指针的引用
// 引用本身并不是对象，因此不能定义指向引用的指针，但是存在对指针的引用

int i = 42;
int *p;          // p是一个int型指针
int *&r = p;     // r是对指针p的引用

r = &i;         // r引用了一个指针，因此给r赋值就是令p指向i
*r = 0;         // 解引用r得到i（也就是p指向的对象）将i的值改为0