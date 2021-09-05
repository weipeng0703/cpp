/*
案例描述：
    利用函数模板封装一个排序的函数，可以对不同数据类型数组进行排序
    排序规则从大到小，排序算法为选择排序
    分别利用char数组和int数组进行测试
*/

#include<string>
#include<iostream>
using namespace std;
// 实现交换的函数模板
template<class T>
void MySwap(T&a, T&b)
{
    T temp = a;
    a = b;
    b = temp;

}


// 利用模板写排序数组
template<class T>
void MySort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int max = i;   // 认定最大值的下标、

        // 内层循环，认定的最大值 比 遍历出的数值要小，说明j下标的元素才是真正的最大值
        for (int j =i+1; j < len; j++)
        {
            if (arr[max] < arr[j])
            {
                max = j;   // 更新最大值下标
            }
            
        }
        if (max != i)
        {
            MySwap(arr[max], arr[i]);

        }
        
        
    }
    

}

// 提供打印数组的模板
template<typename T>
void PrintArr(T arr[], int len)
{

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << endl;

}

void test1()
{
    // 测试char数组
    char CharArr[] = "badcfer";

    int len = sizeof(CharArr) / sizeof(char);
    MySort(CharArr, len);
    PrintArr(CharArr, len);

}

void test2()
{
    // 测试int数组
    int intArr[] = {1,2,4,5,234,3,53,43,5};

    int len = sizeof(intArr) / sizeof(int);
    MySort(intArr, len);
    PrintArr(intArr, len);

}
int main()
{

    // test1();
    test2();

    return 0;
}
