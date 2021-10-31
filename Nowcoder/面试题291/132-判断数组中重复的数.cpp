// 题目
/*
一个长度为N的整形数组，数组中每个元素的取值范围是[0,n-1],判断该数组否有重复的数，请说一下你的思路并手写代码
*/

// 解答
/*
把每个数放到自己对应序号的位置上，如果其他位置上有和自己对应序号相同的数，那么即为有重复的数值。时间复杂度为O(N)
同时为了节省空间复杂度，可以在原数组上进行操作，空间复杂度为O(1)


*/
#include<iostream>
using namespace std;

bool IsDuplicateNumber(int *array, int n)
{
    if(array == NULL) 
        return false;
    int temp;
    for(int i = 0; i < n; i++)
    {
        while(array[i] != i)
        {
            if(array[array[i]] == array[i])
                return true;

            else
            {
                temp = array[array[i]];
                array[array[i]] = array[i];
                array[i] = temp;
            }
        }
    }
    return false;
}