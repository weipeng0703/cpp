// 以按位与，异或和移位实现不用“+”的两个数相加：
// num1^num2为两个数相加不带进位的结果
// (num1&num2)<<1为两个数相加的进位值
// 递归调用将进位值加到相加结果上，不断递归直到进位为0为止，结果为num1与num2相加的值

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include<stack>
using namespace std;
 
int Who(int n1, int n2)
{

    if (n2 == 0)
    {
        return n1;
    }

    int n = n1 ^ n2;
    int carry = (n1 & n2) << 1;

    return Who(n, carry);


}

int main()
{

    cout << Who(5,6) << endl;

    return 0;
}