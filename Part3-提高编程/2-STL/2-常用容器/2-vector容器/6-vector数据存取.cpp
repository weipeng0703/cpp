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


int main()
{
    test1();

    return 0;
}