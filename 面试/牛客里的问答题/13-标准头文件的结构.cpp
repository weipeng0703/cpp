// 题目  为什么标准头文件都有类似以下的结构？

#ifndef __INCvxWorksh 
#define __INCvxWorksh  
#ifdef __cplusplus 
extern "C" { 
#endif  
/*...*/  
#ifdef __cplusplus 
} 
#endif  
#endif /* __INCvxWorksh */ 


// 解答
/*
1.
#ifndef　__INCvxWorksh 
#define　__INCvxWorksh 
#endif  
作用是防止被重复引用
2.
作为一种面向对象的语言，C++支持函数重载，而过程式语言C则不支持。函数被C++编译后在symbol库中的名字与C语言的不同。
例如，假设某个函数的原型为：
void foo(int x, int y);
该函数被C编译器编译后在symbol库中的名字为_foo，而C++编译器则会产生像_foo_int_int之类的名字。
_foo_int_int这样的名字包含了函数名和函数参数数量及类型信息，C++就是靠这种机制来实现函数重载的。
3.
为了实现C和C++的混合编程，C++提供了C连接交换指定符号extern "C"来解决名字匹配问题，
函数声明前加上extern "C"后，则编译器就会按照C语言的方式将该函数编译为_foo，这样C语言中就可以调用C++的函数了。
*/

// 知识点
/*

*/