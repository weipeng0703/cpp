/*
功能描述：
    容器内指定范围的元素拷贝到另一容器中
函数原型：
    copy(iterator beg, iterator end, iterator dest);

    // 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

    // beg 开始迭代器

    // end 结束迭代器

    // dest 目标起始迭代器
*/
#include<algorithm>
#include<vector>
#include<iostream>
#include<ctime>
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
    vector<int> v1;
	for (int i = 0; i < 10; i++)
    {
        v1.push_back(i+1);
    }
    for_each(v1.begin(), v1.end(),MyPrint());
    cout << endl;

    vector<int> v2;
    v2.resize(v1.size());

    copy(v1.begin(), v1.end(), v2.begin());

    for_each(v2.begin(), v2.end(),MyPrint());
    

    
}

int main()
{
    test1();

    return 0;
}