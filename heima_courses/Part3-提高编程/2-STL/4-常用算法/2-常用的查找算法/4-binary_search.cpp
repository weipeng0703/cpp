/*
功能描述：
    查找指定元素是否存在
函数原型：
    bool binary_search(iterator beg, iterator end, value);

    // 查找指定的元素，查到 返回true 否则false

    // 注意——————————————在无序序列中不可用

    // beg 开始迭代器

    // end 结束迭代器

    // value 查找的元素
注：**二分查找法查找效率很高，值得注意的是查找的容器中元素必须的有序序列
*/
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;


void test2()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    
    // 二分查找
    bool flag = binary_search(v.begin(), v.end(),2);

    if (flag == 0)
    {
        cout << "未找到" << endl;
    }
    else
    {
        cout << "找到了" << endl;
    }

}

int main()
{
    // test1();
    test2();

    return 0;
}