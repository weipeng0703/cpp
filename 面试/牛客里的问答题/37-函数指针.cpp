// 题目
/*
函数指针
*/

// 解答
/*
1、定义
    如果在程序中定义了一个函数，那么在编译时系统就会为这个函数代码分配一段存储空间，
    这段存储空间的首地址称为这个函数的地址，而且函数名表示的就是这个地址。
    既然是地址就可以定义一个指针变量来存放，这个指针变量就叫作函数指针变量，简称函数指针。
    即函数指针是指向函数的指针变量。

    函数指针本身首先是一个指针变量，该指针变量指向一个具体的函数。
    这正如用指针变量可指向整型变量、字符型、数组一样，这里是指向函数。

    C在编译时，每一个函数都有一个入口地址，该入口地址就是函数指针所指向的地址。
    有了指向函数的指针变量后，可用该指针变量调用函数，就如同用指针变量可引用其他类型变量一样。

2、用途：

    调用函数和做函数的参数，比如回调函数。 

    PS：回调函数
    回调函数就是一个通过函数指针调用的函数。
    如果你把函数的指针（地址）作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。
    回调函数不是由该函数的实现方法直接调用，而是在特定的事件或条件发生时由另外的一方调用的，用于对该事件或条件进行响应。

    其实：回调就是该函数写在高层，低层通过一个函数指针保存这个函数，在某个事件的触发下，低层通过该函数指针调用高层那个函数。

    类成员函数需要this指针访问函数，而全局或者静态函数不需要this指针。
    即——类的成员函数需要隐含的this指针 而回调函数没有办法提供。

3、示例：
    int(*p)(int, int);

    这个语句就定义了一个指向函数的指针变量 p。
    首先它是一个指针变量，所以要有一个“*”，即（*p）；
    其次前面的 int 表示这个指针变量可以指向返回值类型为 int 型的函数；
    后面括号中的两个 int 表示这个指针变量可以指向有两个参数且都是 int 型的函数。
    
    所以合起来这个语句的意思就是：定义了一个指针变量 p，该指针变量可以指向返回值类型为 int 型，且有两个整型参数的函数。p 的类型为 int(*)(int，int)。

    所以函数指针的定义方式为：
    函数返回值类型 (* 指针变量名) (函数参数列表);
    “函数返回值类型”表示该指针变量可以指向具有什么返回值类型的函数；
    “函数参数列表”表示该指针变量可以指向具有什么参数列表的函数。这个参数列表中只需要写函数的参数类型即可。

我们看到，函数指针的定义就是将“函数声明”中的“函数名”改成“（*指针变量名）”。
但是这里需要注意的是：“（*指针变量名）”两端的括号不能省略，括号改变了运算符的优先级。
如果省略了括号，就不是定义函数指针而是一个函数声明了，即声明了一个返回值类型为指针型的函数。

    指向函数的指针变量没有 ++ 和 -- 运算

*/

// 示例：
/*
int Func(int x);   // 声明一个函数
int (*p) (int x);  // 定义一个函数指针
p = Func;          // 将Func函数的首地址赋给指针变量p

赋值时函数 Func 不带括号，也不带参数。
由于函数名 Func 代表函数的首地址，因此经过赋值以后，指针变量 p 就指向函数 Func() 代码的首地址了。
*/
# include<iostream>
using namespace std;
int Max(int, int);  //函数声明


int main(void)
{
    int(*p)(int, int);  //定义一个函数指针
    int a = 1, b = 2, c = 0;
    p = Max;  //把函数Max赋给指针变量p, 使p指向Max函数

    
    c = (*p)(a, b);  //通过函数指针调用Max函数

    cout << c << endl;
    return 0;
}

int Max(int x, int y)  //定义Max函数
{
    int z;
    
    if (x > y)
    {
        z = x;
    }
    else
    {
        z = y;
    }
    return z;
}

