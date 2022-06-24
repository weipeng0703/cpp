/*
功能描述：
    创建vector容器
函数原型：

    vector<T> v; //采用模板实现类实现，默认构造函数
    vector(v.begin(), v.end()); //将v[begin(), end())区间中的元素拷贝给本身。
    vector(n, elem); //构造函数将n个elem拷贝给本身。
    vector(const vector &vec); //拷贝构造函数。
*/

#include<iostream>
#include<string>
#include<vector>
using namespace std;

void PrintVector(vector<int> &v)
{
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << ' ';
    }
    
    cout << endl;


}
void test1()
{
    vector<int> v1;  // 默认/无参构造

    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }

    PrintVector(v1);

    // 通过区间的方式构造
    vector<int>v2(v1.begin(), v1.end());
    PrintVector(v2);

    // n个elem的方式构造
    vector<int> v3(10,100);
    PrintVector(v3);

    // 拷贝构造
    vector<int> v4(v3);
    PrintVector(v4);
}


int main()
{
    test1();

    return 0;
}