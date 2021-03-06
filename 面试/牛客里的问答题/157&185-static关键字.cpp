// 题目
/*
static
*/

// 解答
/*
1.加了static关键字的全局变量只能在本文件中使用。例如在a.c中定义了static int a=10;
那么在b.c中用extern int a是拿不到a的值得，a的作用域只在a.c中。 

2.static定义的静态局部变量分配在数据段上，普通的局部变量分配在栈上，会因为函数栈帧的释放而被释放掉。

3. 对一个类中成员变量和成员函数来说，加了static关键字，则此变量/函数就没有this指针了，必须通过类名才能访问

*/