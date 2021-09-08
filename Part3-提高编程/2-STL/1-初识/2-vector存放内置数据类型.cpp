// STL中最常用的容器为Vector，可以理解为数组，下面我们将学习如何向这个容器中插入数据、并遍历这个容器

// 容器： vector

// 算法： for_each

// 迭代器： vector<int>::iterator

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void MyPrint(int val)
{
    cout << val << endl;
}

void test1()
{
    // 创建一个vector容器（可以理解为数组）
    vector<int> v;

    // 向容器中插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    // 通过迭代器访问容器数据

    // 第一种遍历方式
    // vector<int>::iterator itBegin = v.begin();   // 起始迭代器，指向容器中第一个元素
    // vector<int>::iterator itEnd = v.end();   // 结束迭代器，指向容器中最后一个元素的下一个元素位置
    
    // while (itBegin != itEnd)
    // {
    //     cout << *itBegin << endl;
    //     itBegin++;
    // }

    // 第二种遍历方式
    // for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    // 第三种遍历方式——利用STL中提供的遍历算法for_each

    for_each(v.begin(),v.end(),MyPrint);

}

int main()
{
    test1();


    return 0;
}