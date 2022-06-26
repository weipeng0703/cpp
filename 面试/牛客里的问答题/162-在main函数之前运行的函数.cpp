// 题目
/*
写个函数在main函数执行前先运行
*/

// 解答
/*
__attribute((constructor))void before()
{
    printf("before main\n");
}

*/

#include<iostream>
using namespace std;

__attribute((constructor))void before()
{
    printf("before main\n");
}

int main()
{
    cout << "main函数" << endl;

    return 0;
}