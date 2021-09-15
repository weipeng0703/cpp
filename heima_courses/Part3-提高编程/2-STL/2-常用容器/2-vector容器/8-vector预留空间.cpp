/*
功能描述：
    减少vector在动态扩展容量时的扩展次数 
函数原型：
    reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
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
// 基本使用
void test1()
{
    vector<int> v1;

    // 预留空间,就不用一直分配内存了

    v1.reserve(100000);

    // 统计分配内存空间的次数
    int num = 0;
    int *p =NULL;

    for (int i = 0; i < 100000; i++)
    {
        v1.push_back(i);

        if (p != &v1[0])
        {
            p = &v1[0];
            num++;
        }
        
    }
    cout << "num = " << num << endl;

}



int main()
{
    test1();

    return 0;
}