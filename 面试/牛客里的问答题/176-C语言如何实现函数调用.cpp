// 题目
/*
C语言是怎么进行函数调用的？
*/

// 解答
/*
每一个函数调用都会分配函数栈，在栈内进行函数执行过程。
调用前，先把返回地址压栈，然后把当前函数的esp指针压栈。
*/
