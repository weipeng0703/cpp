/*
功能描述：
    利用算法实现对deque容器进行排序
算法：
    sort(iterator beg, iterator end) //对beg和end区间内元素进行排序
*/

#include<iostream>
#include<string>
#include<vector>
#include<deque>
#include<algorithm>  // 标准算法头文件

using namespace std;

void PrintDeque(const deque<int> &d)
{
    for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
    {
        // 现在容器内的数据不可以修改
        cout << *it << ' ';
    }
    
    cout << endl;

}

void test3()
{
    deque<int> d1;
    d1.push_back(10);
    d1.push_back(20);
    d1.push_back(30);
    d1.push_front(100);
    d1.push_front(200);
    d1.push_front(300);
    cout << "排序前:" << endl;
    PrintDeque(d1);

    cout << "排序后:" << endl;
    sort(d1.begin(),d1.end());  // 默认规则是从小到大
    // 对于支持随机访问的迭代器的容器了,都可以利用sort()算法进行排序  如vector容器
    PrintDeque(d1);

}

int main()
{
    // test1();
    // test2();
    test3();

    return 0;
}