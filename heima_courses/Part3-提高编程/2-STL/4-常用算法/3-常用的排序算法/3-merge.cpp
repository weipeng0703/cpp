/*
功能描述：
    两个容器元素合并，并存储到另一容器中
函数原型：
    merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

    // 容器元素合并，并存储到另一容器中

    // 注意: 两个容器必须是——————有序的

    // beg1 容器1开始迭代器
    // end1 容器1结束迭代器
    // beg2 容器2开始迭代器
    // end2 容器2结束迭代器
    // dest 目标容器开始迭代器
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
    vector<int> v2;

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
        v2.push_back(i+1);
    }
    cout << "容器1" << endl;
    for_each(v1.begin(), v1.end(), MyPrint());
    cout << endl;

    cout << "容器2" << endl;
    for_each(v2.begin(), v2.end(), MyPrint());
    cout << endl;

    // 目标容器需要提前开辟空间
    vector<int> vTarget;
    vTarget.resize(v1.size() + v2.size());

    // 合并，需要是两个有序容器
    merge(v1.begin(), v1.end(), v2.begin(), v2.end(),vTarget.begin());

    cout << "目标容器" << endl;
    for_each(vTarget.begin(), vTarget.end(), MyPrint());
    cout << endl;


}

int main()
{
    test1();

    return 0;
}