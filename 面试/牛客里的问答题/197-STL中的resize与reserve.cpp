// 题目
/*
STL里resize和reserve的区别
*/

// 解答
/*
resize()：
改变当前容器内含有元素的数量(size())，
eg: 
    vector<int>v; 
    v.resize(len);
v的size变为len,如果原来v的size小于len，那么容器新增（len-size）个元素，元素的值为默认为0.

reserve()：
改变当前容器的最大容量（capacity）,它不会生成元素，只是确定这个容器允许放入多少对象，
如果reserve(len)的值大于当前的capacity()，那么会重新分配一块能存len个对象的空间，
然后把之前v.size()个对象通过copy construtor复制过来，销毁之前的内存；

*/

// 测试
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int> a;
    a.reserve(100);
    a.resize(50);
    cout<<a.size()<<"  "<<a.capacity()<<endl;

    a.resize(150);
    cout<<a.size()<<"  "<<a.capacity()<<endl;

    a.reserve(50);
    cout<<a.size()<<"  "<<a.capacity()<<endl;

    a.resize(50);
    cout<<a.size()<<"  "<<a.capacity()<<endl;
   
}