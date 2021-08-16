#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{
    int arr1[5] = {1,1,2,2,3};

    cout << "逆置前数组元素依次为：" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << arr1[i] <<endl;
    }


    // 1.用两个数组实现
    // int arr2[5];


    // for (int i = 4; i >= 0; i--)
    // {
    //     arr2[i] = arr1[5-i-1];
    // }
    // cout << "逆置后数组元素依次为：" << endl;
    // for (int j = 0; j < 5; j++)
    // {
    //     cout << arr2[j] <<endl;
    // }
    
    // 2.使用中间变量互换
    int start = 0;
    int end = (sizeof(arr1) / sizeof(arr1[0])) - 1;

    while(start < end)
    {
        int temp = arr1[start];
        arr1[start] = arr1[end];
        arr1[end] = temp;

        start++;
        end--;
    }

    cout << "逆置后数组元素依次为：" << endl;
    for (int j = 0; j < 5; j++)
    {
        cout << arr1[j] <<endl;
    }

    return 0;
}