/*
**案例描述：**封装一个函数，利用冒泡排序，实现对整型数组的升序排序

例如数组：int arr[10] = { 4,3,6,9,1,2,10,8,7,5 };
*/
#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

// 冒泡排序
void BubbleSort(int *arr,int len)   // 参数：数组的首地址和长度
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i -1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
        
    }
    
}

// 打印数组
void PrintArray(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    

}
int main()
{
    // 创建数组
    int arr[10] = { 4,3,6,9,1,2,10,8,7,5};

    int len = sizeof(arr) / sizeof(arr[0]);   // 计算数组长度

    BubbleSort(arr,len);   // 排序

    PrintArray(arr,len);   // 打印排序完毕的数组


    return 0;
}