/*
功能描述：
    洗牌 指定范围内的元素随机调整次序
函数原型：
    random_shuffle(iterator beg, iterator end);

    // 指定范围内的元素随机调整次序

    // beg 开始迭代器

    // end 结束迭代器
注：random_shuffle洗牌算法比较实用，使用时记得加随机数种子
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
    srand((unsigned int)time(NULL));
    vector<int> v;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

    // 打乱排序
    random_shuffle(v.begin(), v.end());
    for_each(v.begin(), v.end(), MyPrint());
    cout << endl;

}

int main()
{
    test1();

    return 0;
}