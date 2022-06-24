/*
功能描述：
    对vector容器进行插入、删除操作  
函数原型：
    push_back(ele); //尾部插入元素ele
    pop_back(); //删除最后一个元素
    insert(const_iterator pos, ele); //迭代器指向位置pos插入元素ele
    insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele
    erase(const_iterator pos); //删除迭代器指向的元素
    erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
    clear(); //删除容器中所有元素
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

    // 尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    
    PrintVector(v1);

    // 尾删
    v1.pop_back();
    PrintVector(v1);

    // 插入
    v1.insert(v1.begin(), 100);
    PrintVector(v1);

    v1.insert(v1.begin(), 2 ,1000);
    PrintVector(v1);

    // 删除,参数也是迭代器
    v1.erase(v1.begin());
    PrintVector(v1);
    
    // 清空
    // v1.erase(v1.begin(),v1.end());
    v1.clear();
    cout << "清空后：" << endl;
    PrintVector(v1);
}


int main()
{
    test1();

    return 0;
}