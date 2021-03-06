// 题目
/*
如果同时定义了两个函数，一个带const，一个不带，会有问题吗？
*/

// 解答
/*
如果函数名相同，在相同的作用域内，其参数类型、参数个数，参数顺序不同等能构成函数重载。
有趣的是如果同时在类中，对于函数名相同参数列表也相同的成员函数的const函数和非const函数能够构成重载。
它们被调用的时机为：如果定义的对象是常对象，则调用的是const成员函数，
如果定义的对象是非常对象，则调用重载的非const成员函数。


*/

