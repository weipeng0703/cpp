/*
功能描述：
    对vector中的数据的存取操作  
函数原型：
    at(int idx); //返回索引idx所指的数据
    operator[]; //返回索引idx所指的数据
    front(); //返回容器中第一个数据元素
    back(); //返回容器中最后一个数据元素
*/

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
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
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    
    for (int i = 0; i < 10; i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << v1.at(i) << " ";
    }

    cout << endl;
    
    // 获取第一个元素
    cout << "第一个元素为：" << v1.front() << endl;

    // 获取第一个元素
    cout << "最后一个元素为：" << v1.back() << endl;
}

// 用sort()算法进行排序
void test2()
{
    vector<int> v1;
    v1.push_back(20);
    v1.push_back(10);
    v1.push_back(50);
    v1.push_back(40);
    v1.push_back(30);

    cout << "排序前:" << endl;
    PrintVector(v1);

    sort(v1.begin(),v1.end());

    cout << "排序后:" << endl;
    PrintVector(v1);
}


int main()
{
    test1();
    test2();

    return 0;
}