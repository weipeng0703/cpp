/*
    返回bool类型的仿函数称为谓词
    如果operator()接受一个参数，那么叫做一元谓词
    如果operator()接受两个参数，那么叫做二元谓词
*/

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class MyCompare
{
public:
    bool operator()(int val1, int val2)
    {
        return val1 > val2;
    }
};


void test3()
{
    vector<int> v;

    v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);

    // 默认从小到大排序
    sort(v.begin(), v.end());
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "----------------------------" << endl;
    
    // 使用函数对象改变算法策略，排序从大到小
    sort(v.begin(), v.end(),MyCompare());

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
}

int main()
{   
    // test1();
    // test2();
    test3();

    return 0;
}