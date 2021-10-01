/*
对于双向链表，list_node包含三个部分：
    data：存储的数据
    prev：指向前的指针
    next：指向后的指针
即其allocator申请内存大小时也是会申请容纳以上三部分的大小

对于链表的iterator()，因为链表非连续，所以其iterator不能是一个简单的指针，因为普通指针寻找的是连续空间
所以iterator应该有能力查看某一节点的next，从而根据它指向下一个节点
（所有容器，除了vector与array，他们的指针都是一个class，这样才能保证他们够聪明去执行寻找下一个节点的动作）
对于iterator：
list<int> c;
...
auto ite = c.begin();
++++ite;
ite++++;  // 不允许，类似下面的test1()

由于要符合STL容器前闭后开区间的性质，所以刻意在环状链表list尾端加一个空白节点

*/

#include<iostream>
using namespace std;

void test1()
{
    int a = 1;

    cout << ++a << endl;
    cout << a++ << endl;
    // cout << ++a << endl;
    cout << ++++a << endl;
    // cout << a++++ << endl;  // 注：这是不允许的

}

int main()
{
    test1();

    return 0;
}