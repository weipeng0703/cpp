/*
功能描述：
    给vector容器进行赋值
函数原型：
    vector& operator=(const vector &vec);//重载等号操作符

    assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。

    assign(n, elem); //将n个elem拷贝赋值给本身。
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

    // 赋值
    vector<int>v2;
    v2 = v1;
    PrintVector(v2);

    // assign
    vector<int>v3;
    v3.assign(v1.begin(), v1.end());
    PrintVector(v3);

    // n个elem
    vector<int> v4;
    v4.assign(10,100);
    PrintVector(v4);
    
}


int main()
{
    test1();

    return 0;
}