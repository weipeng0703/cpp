/*
作用： 最常用的排序算法，对数组内元素进行排序

算法步骤：
1.比较相邻的元素。如果第一个比第二个大，就交换他们两个。
2.对每一对相邻元素做同样的工作，执行完毕后，找到第一个最大值。
3.重复以上的步骤，每次比较次数-1，直到不需要比较

排序总轮数：元素个数 - 1
每轮对比次数：元素个数 - 当前排序轮数 - 1
*/

#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{
    int arr[9] = {4,2,8,0,5,7,1,3,9};

    cout << "排序前：" << endl;

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    
    // 第几轮排序   排序总轮数 = 元素个数 - 1
    for (int i = 0; i < 9-1; i++)
    {
        // 第i轮排序的内部过程   每轮对比次数 = 元素个数 - 当前排序轮数 - 1
        for (int j = 0; j < 9-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
        
    }
    
    cout << "\n排序后：" << endl;

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

