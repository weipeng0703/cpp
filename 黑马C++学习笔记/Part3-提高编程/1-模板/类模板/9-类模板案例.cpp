/*
案例描述: 实现一个通用的数组类，要求如下：

    可以对内置数据类型以及自定义数据类型的数据进行存储
    将数组中的数据存储到堆区(容易产生浅拷贝)
    构造函数中可以传入数组的容量
    提供对应的拷贝构造函数以及operator=防止浅拷贝问题
    提供尾插法和尾删法对数组中的数据进行增加和删除
    可以通过下标的方式访问数组中的元素
    可以获取数组中当前元素个数和数组的容量
*/

#include<string>
#include<iostream>
using namespace std;
#include"MyArray.hpp"

void PrintArray(MyArray <int>& arr)
{
    for (int i = 0; i < arr.GetSize(); i++)
    {
        cout << arr[i] << endl;
    }

}

void test1()
{
    MyArray<int> arr1(5);
    // MyArray<int> arr3(100);
    // arr3 = arr1;
    for (int i = 0; i < 5; i++)
    {
        // 利用尾插法向数组中插入数据
        arr1.Push_Back(i);
    }
    cout << "arr1的打印输出为:" << endl;

    PrintArray(arr1);

    cout << "arr1的容量为:" << arr1.GetCapacity() << endl;
    cout << "arr1的大小为:" << arr1.GetSize() << endl;

    MyArray<int> arr2(arr1);   // 测试拷贝构造函数
    
    cout << "arr2的打印输出为:" << endl;

    PrintArray(arr2);

    // 尾删
    arr2.Pop_Back();
    cout << "arr2进行尾删操作后:" << endl;
    cout << "arr2的容量为:" << arr2.GetCapacity() << endl;
    cout << "arr2的大小为:" << arr2.GetSize() << endl;


}

// 测试自定义的数据类型
class Person
{
public:
    Person()
    {

    }

    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }


    string m_Name;
    int m_Age;

};


void PrintPersonArray(MyArray<Person>& arr)
{

    for (int i = 0; i < arr.GetSize(); i++)
    {
        cout << "姓名为:" << arr[i].m_Name << " 年龄为:" << arr[i].m_Age << endl; 
    }
    
}


void test2()
{
    MyArray<Person> arr(10);

    Person p1("孙悟空",999);
    Person p2("韩信",888);
    Person p3("黄忠",999);
    Person p4("周瑜",999);
    Person p5("李白",999);

    // 将数据插入到数组中
    arr.Push_Back(p1);
    arr.Push_Back(p2);
    arr.Push_Back(p3);
    arr.Push_Back(p4);
    arr.Push_Back(p5);
    
    // 打印数组
    cout << "打印数组数据:" << endl;
    PrintPersonArray(arr);

    cout << "arr的容量为:" << arr.GetCapacity() << endl;
    cout << "arr的大小为:" << arr.GetSize() << endl;

}

int main()
{
    // test1();
    test2();

    return 0;
}