/*
功能描述：
    搬运容器到另一个容器中
函数原型：
   transform(iterator beg1, iterator end1, iterator beg2, _func);
    //beg1 源容器开始迭代器

    //end1 源容器结束迭代器

    //beg2 目标容器开始迭代器

    //_func 函数或者函数对象
注： 搬运的目标容器必须要提前开辟空间，否则无法正常搬运
*/
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

class Transform
{
public:
    int operator()(int val)
    {
        return val;
    }

};

// 函数对象
class print2
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
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int> TarV;  // 目标容器

    TarV.resize(v.size()); //   目标容器需要提前开辟空间

    transform(v.begin(), v.end(), TarV.begin(), Transform());
    for_each(TarV.begin(), TarV.end(), print2());
    

}
int main()
{
    test1();

    return 0;
}