// 1.STL六大部件的关系
#include<vector>
#include<algorithm>
#include<functional>
#include<iostream>
using namespace std;

// int main()
// {
//     int ia[6] = {27, 210, 12, 47, 109, 83};

//     // vector为容器，allocator为分配器，二者均有<>模板
//     vector<int, allocator<int>> v(ia, ia+6);
    
//     // count_if为算法,v.begin()与v.end()为迭代器(泛化的指针)
//     // less为仿函数,bind2nd为适配器(binder),not1也是适配器(negator)
    
//     cout << count_if(v.begin(), v.end(), bind2nd(less<int>(), 40)) << endl;
//     cout << count_if(v.begin(), v.end(), not1(bind2nd(less<int>(), 40))) << endl;

//     return 0;
// }

// 2.前闭后开区间
// 对于容器(不一定连续空间), .begin()指向容器的第一个元素所在位置, .end()指向容器内最后一个元素的下一个位置
// 遍历容器:
Container<T> c;
......
for (Container<T>::iterator it = c.begin(); it!= c.end(); it++)
{
    ......
}

// range-based for statement (since C++2011)
for (decl : coll)
{
    statement
}

eg:

for (int i : {1,2,3,4,5,6,76,8})
{
    std::cout << i << std::endl;
}

std::vector<double> vec;
......
for (auto elem : vec)    // auto自动识别类别,遍历容器内每一个元素
{
    std:cout << elem << std::endl;
}

for (auto& elem : vec)    // auto自动识别类别,遍历容器内每一个元素
{
    elem *= 3;
}

// auto keyword
list<string> c;
...
list<string>::iterator ite;
ite = ::find(c.begin(), c.end(), target);

list<string> c;
auto ite = ::find(c.begin(), c.end(), target);   // auto会根据右边的代码自动识别ite的类型