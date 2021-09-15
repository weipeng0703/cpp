/*
类似一个二维数组
学习目标：容器中嵌套容器，我们将所有数据进行遍历输出
*/

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void test1()
{
    vector<vector<int>> v;

    // 创建小容器
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    vector<int> v4;
    
    // 向小容器中添加数据
    for (int i = 0; i < 4; i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }

    // 将小容器添加到大容器中
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);

    // 通过大容器遍历所有数据
    for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
    {
        // (*it)就是个容器<vector<int>>
        for ( vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++ )
        {
            cout << *vit << " ";
            
        }
        cout << endl;
    }
    
    
    

}

int main()
{
    test1();


    return 0;
}