/*
功能描述：
    互换两个容器的元素
函数原型：
    swap(container c1, container c2);

    // 互换两个容器的元素

    // c1容器1

    // c2容器2
注：swap交换容器时，注意交换的容器要同种类型
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

class Replace
{
public:
    bool operator()(int val)
    {
        return val >= 30;
    }


};

void test1()
{
    vector<int> v1;
    vector<int> v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+100);
    }
    cout << "交换前：" << endl;
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;
    for_each(v2.begin(), v2.end(), MyPrint());
    cout << endl;

    swap(v1, v2);
    cout << "交换后：" << endl;
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;
    for_each(v2.begin(), v2.end(), MyPrint());
    cout << endl;
}

int main()
{
    test1();

    return 0;
}