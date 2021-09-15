// 在一个数组中记录了五只小猪的体重，如：int arr[5] = {300,350,200,400,250};

// 找出并打印最重的小猪体重。

#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

int main()
{
    int max = 0;
    int arr[5] = {1,1,2,2,3};
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
            
        }
    
    cout << max << endl;

    return 0;
}