/*
功能描述：
    向容器中填充指定的元素
函数原型：
   fill(iterator beg, iterator end, value);

    // 向容器中填充元素

    // beg 开始迭代器

    // end 结束迭代器

    // value 填充的值
*/

#include<numeric>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

class MyPrint
{
public:
    void operator()(int val)
    {
        cout << val << " ";
    }

};

void test1()
{
    vector<int> v;
    // for (int i = 0; i < 10; i++)
    // {
    //     v.push_back(i);
    // }
    // for_each(v.begin(), v.end(),MyPrint());
    
    v.resize(10);

    // 填充
    fill(v.begin(), v.end(), 100);

    for_each(v.begin(), v.end(),MyPrint());
}

int main()
{   
    test1();

    return 0;
}