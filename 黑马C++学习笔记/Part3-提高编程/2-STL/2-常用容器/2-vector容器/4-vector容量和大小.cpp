/*
功能描述：
    对vector容器的容量和大小操作
函数原型：
    empty(); //判断容器是否为空

    capacity(); //容器的容量

    size(); //返回容器中元素的个数

    resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。

    ​ //如果容器变短，则末尾超出容器长度的元素被删除。

    resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。

    ​ //如果容器变短，则末尾超出容器长度的元素被删除
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

    if (v1.empty())
    {
        cout << "v1为空" << endl;
    }
    else
    {
        cout << "v1不为空" << endl;
        cout << "v1的容量为" << v1.capacity() << endl;
        // 容量永远 >= 大小
        cout << "v1的大小为" << v1.size() << endl;
    }
    // 重新指定大小
    v1.resize(15);
    cout << "v1的容量为" << v1.capacity() << endl; // 若重新指定的容量比之前长，空余的位置默认用0填充
    PrintVector(v1);

    v1.resize(20,100);      // 利用重载版本指定默认填充值
    cout << "v1的容量为" << v1.capacity() << endl;
    PrintVector(v1);

    v1.resize(10,100);      // 若重新指定的容量比之前长，多余部分删除掉
    cout << "v1的容量为" << v1.capacity() << endl;
    PrintVector(v1);

    
}


int main()
{
    test1();

    return 0;
}