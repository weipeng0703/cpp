// 题目
/*
虚函数表具体是怎样实现运行时多态的?
*/

// 解答
/*

虚函数表是一个类的虚函数的地址表，每个对象在创建时，都会有一个指针指向该类虚函数表，
每一个类的虚函数表，按照函数声明的顺序，会将函数地址存在虚函数表中，
当子类对象重写父类的虚函数的时候，父类的虚函数表中对应的位置会被子类的虚函数地址覆盖。

作用：在用父类的指针调用子类对象成员函数时，虚函数表会指明要调用的具体函数是哪个

*/

